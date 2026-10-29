// Copyright (c) Kristian Pilatovich.
// See COPYING for license.

#include <mapport.h>

// Tessera ships no NAT-PMP/PCP/UPnP port mapping, so these are no-ops.
void StartMapPort(bool) {}
void InterruptMapPort() {}
void StopMapPort() {}
