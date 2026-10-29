// Copyright (c) Kristian Pilatovich.
// See COPYING for license.

#ifndef FLOWCOIN_UTIL_THREAD_H
#define FLOWCOIN_UTIL_THREAD_H

#include <functional>
#include <string_view>

namespace util {
/**
 * A wrapper for do-something-once thread functions.
 */
void TraceThread(std::string_view thread_name, std::function<void()> thread_func);

} // namespace util

#endif // FLOWCOIN_UTIL_THREAD_H
