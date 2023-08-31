// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_ABUSE_REPORT_VIDEO_MODE_H
#define OVR_ABUSE_REPORT_VIDEO_MODE_H

#include "OVR_Platform_Defs.h"

/// Determines under what circumstances the frontend UI will attempt to gather
/// video evidence to support a report
typedef enum ovrAbuseReportVideoMode_ {
  ovrAbuseReportVideoMode_Unknown,
  /// The UI will collect video evidence if the object_type supports it.
  ovrAbuseReportVideoMode_Collect,
  /// The UI will try to collect video evidence if the object_type supports it,
  /// but will allow the user to skip that step if they wish.
  ovrAbuseReportVideoMode_Optional,
  /// The UI will not collect video evidence.
  ovrAbuseReportVideoMode_Skip,
} ovrAbuseReportVideoMode;

/// Converts an ovrAbuseReportVideoMode enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrAbuseReportVideoMode_ToString(ovrAbuseReportVideoMode value);

/// Converts a string representing an ovrAbuseReportVideoMode enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrAbuseReportVideoMode) ovrAbuseReportVideoMode_FromString(const char* str);

#endif
