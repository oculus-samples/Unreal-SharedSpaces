// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_LANGUAGEPACKINFO_H
#define OVR_LANGUAGEPACKINFO_H

#include "OVR_Platform_Defs.h"

/// It contains information about a specific language, including its
/// identification tag, and names in both English and the native language. It
/// is useful for applications supporting multiple languages. It can be
/// retrieved using ovr_AssetDetails_GetLanguage(). Learn more about language
/// pack in our [website](https://developer.oculus.com/documentation/native/ps-
/// language-packs/)
typedef struct ovrLanguagePackInfo *ovrLanguagePackInfoHandle;

/// Language name in English language. For example, the English name for
/// "de.lang" will be "German".
OVRP_PUBLIC_FUNCTION(const char *) ovr_LanguagePackInfo_GetEnglishName(const ovrLanguagePackInfoHandle obj);

/// Language name in its native language. For example, the native name for
/// "de.lang" will be "Deutsch".
OVRP_PUBLIC_FUNCTION(const char *) ovr_LanguagePackInfo_GetNativeName(const ovrLanguagePackInfoHandle obj);

/// Language tag in [BCP47](https://www.rfc-editor.org/info/bcp47) format with
/// a suffix of "lang". For example, "de.lang" is a valid language pack name
/// and its `tag` will be "de".
OVRP_PUBLIC_FUNCTION(const char *) ovr_LanguagePackInfo_GetTag(const ovrLanguagePackInfoHandle obj);


#endif
