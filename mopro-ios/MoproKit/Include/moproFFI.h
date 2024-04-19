// This file was autogenerated by some hot garbage in the `uniffi` crate.
// Trust me, you don't want to mess with it!

#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// The following structs are used to implement the lowest level
// of the FFI, and thus useful to multiple uniffied crates.
// We ensure they are declared exactly once, with a header guard, UNIFFI_SHARED_H.
#ifdef UNIFFI_SHARED_H
    // We also try to prevent mixing versions of shared uniffi header structs.
    // If you add anything to the #else block, you must increment the version suffix in UNIFFI_SHARED_HEADER_V4
    #ifndef UNIFFI_SHARED_HEADER_V4
        #error Combining helper code from multiple versions of uniffi is not supported
    #endif // ndef UNIFFI_SHARED_HEADER_V4
#else
#define UNIFFI_SHARED_H
#define UNIFFI_SHARED_HEADER_V4
// ⚠️ Attention: If you change this #else block (ending in `#endif // def UNIFFI_SHARED_H`) you *must* ⚠️
// ⚠️ increment the version suffix in all instances of UNIFFI_SHARED_HEADER_V4 in this file.           ⚠️

typedef struct RustBuffer
{
    int32_t capacity;
    int32_t len;
    uint8_t *_Nullable data;
} RustBuffer;

typedef int32_t (*ForeignCallback)(uint64_t, int32_t, const uint8_t *_Nonnull, int32_t, RustBuffer *_Nonnull);

// Task defined in Rust that Swift executes
typedef void (*UniFfiRustTaskCallback)(const void * _Nullable, int8_t);

// Callback to execute Rust tasks using a Swift Task
//
// Args:
//   executor: ForeignExecutor lowered into a size_t value
//   delay: Delay in MS
//   task: UniFfiRustTaskCallback to call
//   task_data: data to pass the task callback
typedef int8_t (*UniFfiForeignExecutorCallback)(size_t, uint32_t, UniFfiRustTaskCallback _Nullable, const void * _Nullable);

typedef struct ForeignBytes
{
    int32_t len;
    const uint8_t *_Nullable data;
} ForeignBytes;

// Error definitions
typedef struct RustCallStatus {
    int8_t code;
    RustBuffer errorBuf;
} RustCallStatus;

// ⚠️ Attention: If you change this #else block (ending in `#endif // def UNIFFI_SHARED_H`) you *must* ⚠️
// ⚠️ increment the version suffix in all instances of UNIFFI_SHARED_HEADER_V4 in this file.           ⚠️
#endif // def UNIFFI_SHARED_H

// Continuation callback for UniFFI Futures
typedef void (*UniFfiRustFutureContinuation)(void * _Nonnull, int8_t);

// Scaffolding functions
void uniffi_mopro_ffi_fn_free_moprocircom(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_mopro_ffi_fn_constructor_moprocircom_new(RustCallStatus *_Nonnull out_status
    
);
RustBuffer uniffi_mopro_ffi_fn_method_moprocircom_generate_proof(void*_Nonnull ptr, RustBuffer circuit_inputs, RustCallStatus *_Nonnull out_status
);
void uniffi_mopro_ffi_fn_method_moprocircom_initialize(void*_Nonnull ptr, RustBuffer arkzkey_path, RustBuffer wasm_path, RustCallStatus *_Nonnull out_status
);
int8_t uniffi_mopro_ffi_fn_method_moprocircom_verify_proof(void*_Nonnull ptr, RustBuffer proof, RustBuffer public_input, RustCallStatus *_Nonnull out_status
);
uint32_t uniffi_mopro_ffi_fn_func_add(uint32_t a, uint32_t b, RustCallStatus *_Nonnull out_status
);
RustBuffer uniffi_mopro_ffi_fn_func_arkworks_pippenger(RustBuffer num_msm, RustCallStatus *_Nonnull out_status
);
RustBuffer uniffi_mopro_ffi_fn_func_generate_proof2(RustBuffer circuit_inputs, RustCallStatus *_Nonnull out_status
);
RustBuffer uniffi_mopro_ffi_fn_func_hello(RustCallStatus *_Nonnull out_status
    
);
void uniffi_mopro_ffi_fn_func_initialize_mopro(RustCallStatus *_Nonnull out_status
    
);
void uniffi_mopro_ffi_fn_func_initialize_mopro_dylib(RustBuffer dylib_path, RustCallStatus *_Nonnull out_status
);
RustBuffer uniffi_mopro_ffi_fn_func_to_ethereum_inputs(RustBuffer inputs, RustCallStatus *_Nonnull out_status
);
RustBuffer uniffi_mopro_ffi_fn_func_to_ethereum_proof(RustBuffer proof, RustCallStatus *_Nonnull out_status
);
int8_t uniffi_mopro_ffi_fn_func_verify_proof2(RustBuffer proof, RustBuffer public_input, RustCallStatus *_Nonnull out_status
);
RustBuffer ffi_mopro_ffi_rustbuffer_alloc(int32_t size, RustCallStatus *_Nonnull out_status
);
RustBuffer ffi_mopro_ffi_rustbuffer_from_bytes(ForeignBytes bytes, RustCallStatus *_Nonnull out_status
);
void ffi_mopro_ffi_rustbuffer_free(RustBuffer buf, RustCallStatus *_Nonnull out_status
);
RustBuffer ffi_mopro_ffi_rustbuffer_reserve(RustBuffer buf, int32_t additional, RustCallStatus *_Nonnull out_status
);
void ffi_mopro_ffi_rust_future_continuation_callback_set(UniFfiRustFutureContinuation _Nonnull callback
);
void ffi_mopro_ffi_rust_future_poll_u8(void* _Nonnull handle, void* _Nonnull uniffi_callback
);
void ffi_mopro_ffi_rust_future_cancel_u8(void* _Nonnull handle
);
void ffi_mopro_ffi_rust_future_free_u8(void* _Nonnull handle
);
uint8_t ffi_mopro_ffi_rust_future_complete_u8(void* _Nonnull handle, RustCallStatus *_Nonnull out_status
);
void ffi_mopro_ffi_rust_future_poll_i8(void* _Nonnull handle, void* _Nonnull uniffi_callback
);
void ffi_mopro_ffi_rust_future_cancel_i8(void* _Nonnull handle
);
void ffi_mopro_ffi_rust_future_free_i8(void* _Nonnull handle
);
int8_t ffi_mopro_ffi_rust_future_complete_i8(void* _Nonnull handle, RustCallStatus *_Nonnull out_status
);
void ffi_mopro_ffi_rust_future_poll_u16(void* _Nonnull handle, void* _Nonnull uniffi_callback
);
void ffi_mopro_ffi_rust_future_cancel_u16(void* _Nonnull handle
);
void ffi_mopro_ffi_rust_future_free_u16(void* _Nonnull handle
);
uint16_t ffi_mopro_ffi_rust_future_complete_u16(void* _Nonnull handle, RustCallStatus *_Nonnull out_status
);
void ffi_mopro_ffi_rust_future_poll_i16(void* _Nonnull handle, void* _Nonnull uniffi_callback
);
void ffi_mopro_ffi_rust_future_cancel_i16(void* _Nonnull handle
);
void ffi_mopro_ffi_rust_future_free_i16(void* _Nonnull handle
);
int16_t ffi_mopro_ffi_rust_future_complete_i16(void* _Nonnull handle, RustCallStatus *_Nonnull out_status
);
void ffi_mopro_ffi_rust_future_poll_u32(void* _Nonnull handle, void* _Nonnull uniffi_callback
);
void ffi_mopro_ffi_rust_future_cancel_u32(void* _Nonnull handle
);
void ffi_mopro_ffi_rust_future_free_u32(void* _Nonnull handle
);
uint32_t ffi_mopro_ffi_rust_future_complete_u32(void* _Nonnull handle, RustCallStatus *_Nonnull out_status
);
void ffi_mopro_ffi_rust_future_poll_i32(void* _Nonnull handle, void* _Nonnull uniffi_callback
);
void ffi_mopro_ffi_rust_future_cancel_i32(void* _Nonnull handle
);
void ffi_mopro_ffi_rust_future_free_i32(void* _Nonnull handle
);
int32_t ffi_mopro_ffi_rust_future_complete_i32(void* _Nonnull handle, RustCallStatus *_Nonnull out_status
);
void ffi_mopro_ffi_rust_future_poll_u64(void* _Nonnull handle, void* _Nonnull uniffi_callback
);
void ffi_mopro_ffi_rust_future_cancel_u64(void* _Nonnull handle
);
void ffi_mopro_ffi_rust_future_free_u64(void* _Nonnull handle
);
uint64_t ffi_mopro_ffi_rust_future_complete_u64(void* _Nonnull handle, RustCallStatus *_Nonnull out_status
);
void ffi_mopro_ffi_rust_future_poll_i64(void* _Nonnull handle, void* _Nonnull uniffi_callback
);
void ffi_mopro_ffi_rust_future_cancel_i64(void* _Nonnull handle
);
void ffi_mopro_ffi_rust_future_free_i64(void* _Nonnull handle
);
int64_t ffi_mopro_ffi_rust_future_complete_i64(void* _Nonnull handle, RustCallStatus *_Nonnull out_status
);
void ffi_mopro_ffi_rust_future_poll_f32(void* _Nonnull handle, void* _Nonnull uniffi_callback
);
void ffi_mopro_ffi_rust_future_cancel_f32(void* _Nonnull handle
);
void ffi_mopro_ffi_rust_future_free_f32(void* _Nonnull handle
);
float ffi_mopro_ffi_rust_future_complete_f32(void* _Nonnull handle, RustCallStatus *_Nonnull out_status
);
void ffi_mopro_ffi_rust_future_poll_f64(void* _Nonnull handle, void* _Nonnull uniffi_callback
);
void ffi_mopro_ffi_rust_future_cancel_f64(void* _Nonnull handle
);
void ffi_mopro_ffi_rust_future_free_f64(void* _Nonnull handle
);
double ffi_mopro_ffi_rust_future_complete_f64(void* _Nonnull handle, RustCallStatus *_Nonnull out_status
);
void ffi_mopro_ffi_rust_future_poll_pointer(void* _Nonnull handle, void* _Nonnull uniffi_callback
);
void ffi_mopro_ffi_rust_future_cancel_pointer(void* _Nonnull handle
);
void ffi_mopro_ffi_rust_future_free_pointer(void* _Nonnull handle
);
void*_Nonnull ffi_mopro_ffi_rust_future_complete_pointer(void* _Nonnull handle, RustCallStatus *_Nonnull out_status
);
void ffi_mopro_ffi_rust_future_poll_rust_buffer(void* _Nonnull handle, void* _Nonnull uniffi_callback
);
void ffi_mopro_ffi_rust_future_cancel_rust_buffer(void* _Nonnull handle
);
void ffi_mopro_ffi_rust_future_free_rust_buffer(void* _Nonnull handle
);
RustBuffer ffi_mopro_ffi_rust_future_complete_rust_buffer(void* _Nonnull handle, RustCallStatus *_Nonnull out_status
);
void ffi_mopro_ffi_rust_future_poll_void(void* _Nonnull handle, void* _Nonnull uniffi_callback
);
void ffi_mopro_ffi_rust_future_cancel_void(void* _Nonnull handle
);
void ffi_mopro_ffi_rust_future_free_void(void* _Nonnull handle
);
void ffi_mopro_ffi_rust_future_complete_void(void* _Nonnull handle, RustCallStatus *_Nonnull out_status
);
uint16_t uniffi_mopro_ffi_checksum_func_add(void
    
);
uint16_t uniffi_mopro_ffi_checksum_func_arkworks_pippenger(void
    
);
uint16_t uniffi_mopro_ffi_checksum_func_generate_proof2(void
    
);
uint16_t uniffi_mopro_ffi_checksum_func_hello(void
    
);
uint16_t uniffi_mopro_ffi_checksum_func_initialize_mopro(void
    
);
uint16_t uniffi_mopro_ffi_checksum_func_initialize_mopro_dylib(void
    
);
uint16_t uniffi_mopro_ffi_checksum_func_to_ethereum_inputs(void
    
);
uint16_t uniffi_mopro_ffi_checksum_func_to_ethereum_proof(void
    
);
uint16_t uniffi_mopro_ffi_checksum_func_verify_proof2(void
    
);
uint16_t uniffi_mopro_ffi_checksum_method_moprocircom_generate_proof(void
    
);
uint16_t uniffi_mopro_ffi_checksum_method_moprocircom_initialize(void
    
);
uint16_t uniffi_mopro_ffi_checksum_method_moprocircom_verify_proof(void
    
);
uint16_t uniffi_mopro_ffi_checksum_constructor_moprocircom_new(void
    
);
uint32_t ffi_mopro_ffi_uniffi_contract_version(void
    
);

