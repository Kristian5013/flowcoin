# Copyright (c) 2026 tessera core
# See COPYING for license.

# Vendored post-quantum key-encapsulation mechanism (ML-KEM-1024, FIPS 203),
# wired up by its own cmake/ module alongside cmake/SLH-DSA-SHAKE-256s.cmake.
# Used by the P2P v2 transport key agreement (crypto/mlkem.cpp -> v2cipher.cpp),
# where Core's BIP-324 uses secp256k1 ellswift ECDH — Tessera has no curve, so
# the shared secret comes from ML-KEM-1024 instead. PQClean sources
# (crypto_kem/ml-kem-1024/clean), built verbatim as C11.
#
# The scheme-specific files are namespaced PQCLEAN_MLKEM1024_*, so they coexist
# with the SPHINCS+ files of the same names (params.h, ...) without symbol
# collision. ML-KEM-1024 has no fips202.c / randombytes.c of its own: those
# PQClean common/ primitives are non-namespaced and are compiled once by the
# slhdsa256s target, so mlkem1024 links it to resolve them and reads their
# headers from that directory.
#
# Built before core_interface so the vendored C keeps its own build policy.
add_library(mlkem1024 STATIC
    ${PROJECT_SOURCE_DIR}/src/ML-KEM-1024/cbd.c
    ${PROJECT_SOURCE_DIR}/src/ML-KEM-1024/indcpa.c
    ${PROJECT_SOURCE_DIR}/src/ML-KEM-1024/kem.c
    ${PROJECT_SOURCE_DIR}/src/ML-KEM-1024/ntt.c
    ${PROJECT_SOURCE_DIR}/src/ML-KEM-1024/poly.c
    ${PROJECT_SOURCE_DIR}/src/ML-KEM-1024/polyvec.c
    ${PROJECT_SOURCE_DIR}/src/ML-KEM-1024/reduce.c
    ${PROJECT_SOURCE_DIR}/src/ML-KEM-1024/symmetric-shake.c
    ${PROJECT_SOURCE_DIR}/src/ML-KEM-1024/verify.c)
target_include_directories(mlkem1024 PRIVATE
    ${PROJECT_SOURCE_DIR}/src/ML-KEM-1024
    # fips202.h + randombytes.h (PQClean common/), compiled by slhdsa256s.
    ${PROJECT_SOURCE_DIR}/src/SLH-DSA-SHAKE-256s)
target_link_libraries(mlkem1024 PUBLIC slhdsa256s)
