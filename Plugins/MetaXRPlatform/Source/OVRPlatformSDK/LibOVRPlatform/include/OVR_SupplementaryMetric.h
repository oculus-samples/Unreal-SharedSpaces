// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_SUPPLEMENTARYMETRIC_H
#define OVR_SUPPLEMENTARYMETRIC_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"

typedef struct ovrSupplementaryMetric *ovrSupplementaryMetricHandle;

OVRP_PUBLIC_FUNCTION(ovrID)     ovr_SupplementaryMetric_GetID(const ovrSupplementaryMetricHandle obj);
OVRP_PUBLIC_FUNCTION(long long) ovr_SupplementaryMetric_GetMetric(const ovrSupplementaryMetricHandle obj);

#endif
