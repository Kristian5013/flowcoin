// Copyright (c) Kristian Pilatovich.
// See COPYING for license.

#ifndef FLOWCOIN_UTIL_CHAINTYPE_H
#define FLOWCOIN_UTIL_CHAINTYPE_H

#include <optional>
#include <string>
#include <string_view>

enum class ChainType {
    MAIN,
    TESTNET,
    REGTEST,
};

std::string ChainTypeToString(ChainType chain);

std::optional<ChainType> ChainTypeFromString(std::string_view chain);

#endif // FLOWCOIN_UTIL_CHAINTYPE_H
