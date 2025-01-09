use std::collections::HashMap;

use serde_wasm_bindgen::{from_value, to_value};
use wasm_bindgen::prelude::*;

use halo2_fibonacci;

#[wasm_bindgen]
pub fn generate_proof(
    srs_key: &[u8],
    proving_key: &[u8],
    input: JsValue,
) -> Result<JsValue, JsValue> {
    let srs_key_str = std::str::from_utf8(srs_key)
        .map_err(|e| JsValue::from_str(&format!("Invalid UTF-8 in srs_key: {}", e)))?;
    let proving_key_str = std::str::from_utf8(proving_key)
        .map_err(|e| JsValue::from_str(&format!("Invalid UTF-8 in proving_key: {}", e)))?;

    let input: HashMap<String, Vec<String>> = from_value(input)
        .map_err(|e| JsValue::from_str(&format!("Failed to parse input: {}", e)))?;

    // Generate proof
    let (proof, public_input) = halo2_fibonacci::prove(srs_key_str, proving_key_str, input)
        .map_err(|e| JsValue::from_str(&format!("Proof generation failed: {}", e)))?;

    // Serialize the output back into JsValue
    to_value(&(proof, public_input))
        .map_err(|e| JsValue::from_str(&format!("Serialization failed: {}", e)))
}

#[wasm_bindgen]
pub fn verify_proof(
    srs_key: &[u8],
    verifying_key: &[u8],
    proof: JsValue,
    public_inputs: JsValue,
) -> Result<JsValue, JsValue> {
    let srs_key_str = std::str::from_utf8(srs_key)
        .map_err(|e| JsValue::from_str(&format!("Invalid UTF-8 in srs_key: {}", e)))?;
    let verifying_key_str = std::str::from_utf8(verifying_key)
        .map_err(|e| JsValue::from_str(&format!("Invalid UTF-8 in verifying_key: {}", e)))?;

    let proof: Vec<u8> = from_value(proof)
        .map_err(|e| JsValue::from_str(&format!("Failed to parse proof: {}", e)))?;
    let public_inputs: Vec<u8> = from_value(public_inputs)
        .map_err(|e| JsValue::from_str(&format!("Failed to parse public_inputs: {}", e)))?;

    // Verify proof
    let is_valid = halo2_fibonacci::verify(srs_key_str, verifying_key_str, proof, public_inputs)
        .map_err(|e| JsValue::from_str(&format!("Proof verification failed: {}", e)))?;

    // Convert result to JsValue
    to_value(&is_valid).map_err(|e| JsValue::from_str(&format!("Serialization failed: {}", e)))
}
