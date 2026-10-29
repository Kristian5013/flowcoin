# Copyright (c) Kristian Pilatovich.
# See COPYING for license.

add_library(tessera_crypto STATIC EXCLUDE_FROM_ALL
  aes.cpp
  chacha20.cpp
  chacha20poly1305.cpp
  hex_base.cpp
  hmac_sha256.cpp
  mlkem.cpp
  muhash.cpp
  poly1305.cpp
  sha256.cpp
  sha3.cpp
  sha3_512.cpp
  siphash.cpp
  ../support/cleanse.cpp
  ../support/lockedpool.cpp
)

target_link_libraries(tessera_crypto
  PRIVATE
    core_interface
  PUBLIC
    # crypto/mlkem.cpp wraps the vendored ML-KEM-1024 (FIPS 203) primitives.
    mlkem1024
)
