// Copyright (c) Kristian Pilatovich.
// See COPYING for license.

#ifndef FLOWCOIN_TEST_UTIL_COINS_H
#define FLOWCOIN_TEST_UTIL_COINS_H

#include <primitives/transaction.h>

class CCoinsViewCache;
class FastRandomContext;

/**
 * Create a Coin with DynamicMemoryUsage of 80 bytes and add it to the given view.
 * @param[in,out] coins_view  The coins view cache to add the new coin to.
 * @returns the COutPoint of the created coin.
 */
COutPoint AddTestCoin(FastRandomContext& rng, CCoinsViewCache& coins_view);

#endif // FLOWCOIN_TEST_UTIL_COINS_H
