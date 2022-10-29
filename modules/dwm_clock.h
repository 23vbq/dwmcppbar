#include <time.h>
#include <string>

std::string getCurrentDateTime(std::string format)
{
    time_t now = time(0);
    struct tm tstruct;
    char buffer[80];
    tstruct = *localtime(&now);
    strftime(buffer, sizeof(buffer), &format[0], &tstruct);
    return buffer;
}