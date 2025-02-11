// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_PRODUCT_H
#define OVR_PRODUCT_H

#include "OVR_Platform_Defs.h"
#include "OVR_Price.h"

/// The class that represents the product information for a specific IAP which
/// is available for purchase in your app. You can retrieve more information
/// about the product(s) by using their SKU with ovr_IAP_GetProductsBySKU()
typedef struct ovrProduct *ovrProductHandle;

/// The description for the product. The description should be meaningful and
/// explanatory to help outline the product and its features.
OVRP_PUBLIC_FUNCTION(const char *) ovr_Product_GetDescription(const ovrProductHandle obj);

/// The formatted string for the ovrPriceHandle. This is the same value stored
/// in ovrPriceHandle.
OVRP_PUBLIC_FUNCTION(const char *) ovr_Product_GetFormattedPrice(const ovrProductHandle obj);

/// The name of the product. This will be used as a the display name and should
/// be aligned with the user facing title.
OVRP_PUBLIC_FUNCTION(const char *) ovr_Product_GetName(const ovrProductHandle obj);

/// The ovrPriceHandle of the product contains the currency code, the amount in
/// hundredths, and the formatted string representation.
OVRP_PUBLIC_FUNCTION(ovrPriceHandle) ovr_Product_GetPrice(const ovrProductHandle obj);

/// The unique string that you use to reference the product in your app. The
/// SKU is case-sensitive and should match the SKU reference in your code.
OVRP_PUBLIC_FUNCTION(const char *) ovr_Product_GetSKU(const ovrProductHandle obj);


#endif
