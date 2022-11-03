#include <iostream>
#include <thread>
#include <chrono>
#include <string>

// Config file
#include "config.h"

using namespace std;

bool TERMINATEDWMBAR = false;
string updateBar();

int main()
{
    // setlocale(LC_ALL, "unicode");
    while (!TERMINATEDWMBAR)
    {
        printf("%s\n", &updateBar()[0]);
        this_thread::sleep_for(chrono::seconds(1));
    }
    return 0;
}

string updateBar()
{
    return (string) "[" + getCurrentBatteryPercentage(BATTERY, batIcons) + "] " +
           "[ " + getCurrentDateTime("%X") + " ]";
}