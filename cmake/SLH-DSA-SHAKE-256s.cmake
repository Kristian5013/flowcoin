# Copyright (c) 2026 tessera core
# See COPYING for license.

# Vendored post-quantum signature scheme, wired up by its own cmake/ module —
# Tessera's analog of Bitcoin Core's cmake/secp256k1.cmake. Core links
# libsecp256k1 for its ECDSA/Schnorr consensus signatures; Tessera has no
# elliptic curve, so the consensus signature primitive is SLH-DSA-SHAKE-256s
# (FIPS 205), verified in CHECKSIG (pubkey.cpp). PQClean sources
# (crypto_sign/sphincs-shake-256s-simple/clean), built as C11.
#
# PQClean's code is SPHINCS+ 3.1. One line of fors.c is changed to the FIPS 205
# bit order of the FORS indices (see the comment there); every other file is
# verbatim. The FIPS 205 message prefix (0x00 || |ctx| || ctx) is added by the
# callers, pubkey.cpp and key.cpp.
#
# This target also carries the two PQClean common/ primitives — fips202.c
# (SHA3/SHAKE) and randombytes.c — whose symbols are NOT scheme-namespaced and
# must therefore be compiled exactly once. They physically live under
# src/SLH-DSA-SHAKE-256s/, so they are built here; the sibling ML-KEM-1024
# target (cmake/ML-KEM-1024.cmake) links this one to reuse them.
#
# The include directory is PRIVATE: callers include the API by path,
# <SLH-DSA-SHAKE-256s/api.h>, because this directory ships a hash.h, params.h
# and utils.h that must never shadow Tessera's own headers.
#
# Built before core_interface so the vendored C keeps its own build policy (no
# strict warnings / -UNDEBUG applied).
add_library(slhdsa256s STATIC
    ${PROJECT_SOURCE_DIR}/src/SLH-DSA-SHAKE-256s/fips202.c       # shared SHA3/SHAKE (PQClean common/)
    ${PROJECT_SOURCE_DIR}/src/SLH-DSA-SHAKE-256s/randombytes.c   # shared CSPRNG  (PQClean common/)
    ${PROJECT_SOURCE_DIR}/src/SLH-DSA-SHAKE-256s/address.c
    ${PROJECT_SOURCE_DIR}/src/SLH-DSA-SHAKE-256s/context_shake.c
    ${PROJECT_SOURCE_DIR}/src/SLH-DSA-SHAKE-256s/fors.c
    ${PROJECT_SOURCE_DIR}/src/SLH-DSA-SHAKE-256s/hash_shake.c
    ${PROJECT_SOURCE_DIR}/src/SLH-DSA-SHAKE-256s/merkle.c
    ${PROJECT_SOURCE_DIR}/src/SLH-DSA-SHAKE-256s/sign.c
    ${PROJECT_SOURCE_DIR}/src/SLH-DSA-SHAKE-256s/thash_shake_simple.c
    ${PROJECT_SOURCE_DIR}/src/SLH-DSA-SHAKE-256s/utils.c
    ${PROJECT_SOURCE_DIR}/src/SLH-DSA-SHAKE-256s/utilsx1.c
    ${PROJECT_SOURCE_DIR}/src/SLH-DSA-SHAKE-256s/wots.c
    ${PROJECT_SOURCE_DIR}/src/SLH-DSA-SHAKE-256s/wotsx1.c)
target_include_directories(slhdsa256s PRIVATE
    ${PROJECT_SOURCE_DIR}/src/SLH-DSA-SHAKE-256s)
