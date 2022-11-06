#include <iostream>
#include <thread>
#include <chrono>
#include <string>

// Modules
#include "modules/dwm_clock.h"
#include "modules/dwm_battery.h"
#include "modules/dwm_alsa.h"

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
	return (string) "[" + getCurrentVolume() + "] " +
		   "[" + getCurrentBatteryPercentage() + "] " +
		   "[ " + getCurrentDateTime("%X") + " ]";
}