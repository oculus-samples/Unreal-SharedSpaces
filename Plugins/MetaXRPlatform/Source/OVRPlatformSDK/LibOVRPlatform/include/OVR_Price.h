// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_PRICE_H
#define OVR_PRICE_H

#include "OVR_Platform_Defs.h"

/// The price of a ovrProductHandle. A price with a currency of "USD" and an
/// amount in hundredths of 99 has a formatted string of "$0.99".
typedef struct ovrPrice *ovrPriceHandle;

/// The price of the product in hundredths of currency units.
OVRP_PUBLIC_FUNCTION(unsigned int) ovr_Price_GetAmountInHundredths(const ovrPriceHandle obj);

/// The ISO 4217 currency code for the price of the product.
OVRP_PUBLIC_FUNCTION(const char *) ovr_Price_GetCurrency(const ovrPriceHandle obj);

/// The formatted string representation of the price.
OVRP_PUBLIC_FUNCTION(const char *) ovr_Price_GetFormatted(const ovrPriceHandle obj);


#endif
