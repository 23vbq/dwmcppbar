#include "../execute_command.h"
#include <regex>

std::regex reg("([0-9]?[0-9]%)");
static std::string volumeIcons[] = {"奄", "奔", "墳", "ﱝ"};

std::string getCurrentVolume()
{
    std::string _return;
    std::string buffer = &execute("amixer get Master | tail -n1")[0];
    std::smatch m;
    std::regex_search(buffer, m, reg);
    int volume = std::stoi(m[0].str().substr(0, m[0].str().length() - 1));
    if (volume > 66)
        _return = volumeIcons[2];
    else if (volume > 33)
        _return = volumeIcons[1];
    else
        _return = volumeIcons[0];
    _return += std::to_string(volume);
    return _return;
}