#include <string>
// Modules
#include "modules/dwm_clock.h"
#include "modules/dwm_battery.h"

static const std::string BATTERY = "BAT1";
static std::string batIcons[] = {"", "", "", "", "", "", "", "", "", "", ""};

//"[ " + getCurrentBatteryPercentage(BATTERY, batIcons) + " ] " +
//  static