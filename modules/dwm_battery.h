#include <iostream>
#include <fstream>
#include <string>

std::string getCurrentBatteryPercentage(std::string batteryName, std::string *batIcons)
{
    std::string _return;

    std::string buffer;
    std::ifstream in("/sys/class/power_supply/" + batteryName + "/capacity");
    std::getline(in, buffer);
    in.close();
    int percentage = atoi(&buffer[0]);
    in.open("/sys/class/power_supply/" + batteryName + "/status");
    std::getline(in, buffer);
    in.close();

    if (buffer == "Charging")
        _return = batIcons[10];
    else if (percentage > 90)
        _return = batIcons[9];
    else if (percentage > 80)
        _return = batIcons[8];
    else if (percentage > 70)
        _return = batIcons[7];
    else if (percentage > 60)
        _return = batIcons[6];
    else if (percentage > 50)
        _return = batIcons[5];
    else if (percentage > 40)
        _return = batIcons[4];
    else if (percentage > 30)
        _return = batIcons[3];
    else if (percentage > 20)
        _return = batIcons[2];
    else if (percentage > 15)
        _return = batIcons[1];
    else
        _return = (std::string) "CHECK " + batIcons[0] + " ENGINE";

    _return += " " + std::to_string(percentage);

    return _return;
}