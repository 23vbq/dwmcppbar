#include <string>
// Modules
#include "modules/dwm_clock.h"

std::string updateBar()
{
    return (std::string) 
        "[ " + getCurrentDateTime("%X") + " ]";
}