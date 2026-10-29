// Copyright (c) Kristian Pilatovich.
// See COPYING for license.

#ifndef FLOWCOIN_WALLET_RPC_WALLET_H
#define FLOWCOIN_WALLET_RPC_WALLET_H

#include <span>

class CRPCCommand;

namespace wallet {
std::span<const CRPCCommand> GetWalletRPCCommands();
} // namespace wallet

#endif // FLOWCOIN_WALLET_RPC_WALLET_H
