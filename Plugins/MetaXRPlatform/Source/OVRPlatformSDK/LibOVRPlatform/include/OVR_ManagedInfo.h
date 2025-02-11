// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_MANAGEDINFO_H
#define OVR_MANAGEDINFO_H

#include "OVR_Platform_Defs.h"

typedef struct ovrManagedInfo *ovrManagedInfoHandle;

OVRP_PUBLIC_FUNCTION(const char *) ovr_ManagedInfo_GetDepartment(const ovrManagedInfoHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_ManagedInfo_GetEmail(const ovrManagedInfoHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_ManagedInfo_GetEmployeeNumber(const ovrManagedInfoHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_ManagedInfo_GetExternalId(const ovrManagedInfoHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_ManagedInfo_GetLocation(const ovrManagedInfoHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_ManagedInfo_GetManager(const ovrManagedInfoHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_ManagedInfo_GetName(const ovrManagedInfoHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_ManagedInfo_GetOrganizationId(const ovrManagedInfoHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_ManagedInfo_GetOrganizationName(const ovrManagedInfoHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_ManagedInfo_GetPosition(const ovrManagedInfoHandle obj);

#endif
