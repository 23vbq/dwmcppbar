#include "../execute_command.h"
#include "sstream"

std::string getRamUsage()
{
    std::string buffer = &execute("free -h | grep Mem | awk '{print $3}'")[0];
    std::istringstream iss(buffer);
    for (int i = 0; i < 2; i++)
    {
        std::getline(iss, buffer, '\t');
    }
    return buffer.substr(0, buffer.length() - 1);
}
std::string getCpuPercentage()
{
    std::string buffer = &execute("top -bn1 | grep Cpu")[0];
    std::istringstream iss(buffer);
    for (int i = 0; i < 2; i++)
    {
        std::getline(iss, buffer, ',');
    }
    return buffer.substr(2, buffer.length() - 5) + (std::string) "%";
}
std::string getUsage()
{
    return " " + getRamUsage() + " " + getCpuPercentage();
}