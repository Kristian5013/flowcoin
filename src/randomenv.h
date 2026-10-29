// Copyright (c) Kristian Pilatovich.
// See COPYING for license.

#ifndef FLOWCOIN_RANDOMENV_H
#define FLOWCOIN_RANDOMENV_H

#include <crypto/sha3_512.h>

/** Gather non-cryptographic environment data that changes over time. */
void RandAddDynamicEnv(SHA3_512& hasher);

/** Gather non-cryptographic environment data that does not change over time. */
void RandAddStaticEnv(SHA3_512& hasher);

#endif // FLOWCOIN_RANDOMENV_H
