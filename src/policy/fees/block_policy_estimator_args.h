// Copyright (c) Kristian Pilatovich.
// See COPYING for license.

#ifndef FLOWCOIN_POLICY_FEES_BLOCK_POLICY_ESTIMATOR_ARGS_H
#define FLOWCOIN_POLICY_FEES_BLOCK_POLICY_ESTIMATOR_ARGS_H

#include <util/fs.h>

class ArgsManager;

/** @return The fee estimates data file path. */
fs::path FeeestPath(const ArgsManager& argsman);

#endif // FLOWCOIN_POLICY_FEES_BLOCK_POLICY_ESTIMATOR_ARGS_H