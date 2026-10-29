// Copyright (c) Kristian Pilatovich.
// See COPYING for license.

#ifndef FLOWCOIN_UTIL_BATCHPRIORITY_H
#define FLOWCOIN_UTIL_BATCHPRIORITY_H

/**
 * On platforms that support it, tell the kernel the calling thread is
 * CPU-intensive and non-interactive. See SCHED_BATCH in sched(7) for details.
 *
 */
void ScheduleBatchPriority();

#endif // FLOWCOIN_UTIL_BATCHPRIORITY_H