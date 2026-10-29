// Copyright (c) Kristian Pilatovich.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <pubkey.h>

#include <uint256.h>

extern "C" {
#include <SLH-DSA-SHAKE-256s/api.h>
}

#include <algorithm>
#include <array>
#include <vector>

// The sizes declared in pubkey.h must match the vendored SLH-DSA-SHAKE-256s.
static_assert(CPubKey::SIZE == 1 + PQCLEAN_SPHINCSSHAKE256SSIMPLE_CLEAN_CRYPTO_PUBLICKEYBYTES);
static_assert(CPubKey::SIGNATURE_SIZE == PQCLEAN_SPHINCSSHAKE256SSIMPLE_CLEAN_CRYPTO_BYTES);

bool CPubKey::Verify(const uint256& hash, const std::vector<unsigned char>& vchSig) const
{
    if (!IsValid()) return false;
    if (vchSig.size() != SIGNATURE_SIZE) return false;

    // FIPS 205 pure SLH-DSA with an empty context string signs
    // M' = 0x00 || 0x00 || hash (Algorithms 22 and 24).
    std::array<unsigned char, 2 + uint256::size()> msg{};
    std::copy(hash.begin(), hash.end(), msg.begin() + 2);

    // vch[0] is the header byte; the 64-byte public key follows it.
    const unsigned char* key = data() + 1;
    return PQCLEAN_SPHINCSSHAKE256SSIMPLE_CLEAN_crypto_sign_verify(
               vchSig.data(), vchSig.size(), msg.data(), msg.size(), key) == 0;
}

bool CPubKey::IsFullyValid() const
{
    // Any 64 bytes (PK.seed || PK.root) form a valid SLH-DSA public key, so the
    // syntactic check is the full check.
    return IsValid();
}
