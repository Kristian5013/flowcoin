// Copyright (c) Kristian Pilatovich.
// See COPYING for license.

#ifndef FLOWCOIN_DEPLOYMENTINFO_H
#define FLOWCOIN_DEPLOYMENTINFO_H

#include <consensus/params.h>

#include <array>
#include <cassert>
#include <optional>
#include <string>
#include <string_view>

struct VBDeploymentInfo {
    /** Deployment name */
    const char *name;
    /** Whether GBT clients can safely ignore this rule in simplified usage */
    bool gbt_optional_rule;
};

extern const std::array<VBDeploymentInfo,Consensus::MAX_VERSION_BITS_DEPLOYMENTS> VersionBitsDeploymentInfo;

std::string DeploymentName(Consensus::BuriedDeployment dep);

inline std::string DeploymentName(Consensus::DeploymentPos pos)
{
    assert(Consensus::ValidDeployment(pos));
    return VersionBitsDeploymentInfo[pos].name;
}

std::optional<Consensus::BuriedDeployment> GetBuriedDeployment(std::string_view deployment_name);

#endif // FLOWCOIN_DEPLOYMENTINFO_H
