#include <iostream>
#include <thread>
#include <chrono>
#include <string>

// Modules
#include "modules/dwm_clock.h"
#include "modules/dwm_battery.h"
#include "modules/dwm_alsa.h"
#include "modules/dwm_usage.h"

using namespace std;

bool TERMINATEDWMBAR = false;
string updateBar();
void delayedChecks();

string dwm_usage = "";

int main()
{
	// setlocale(LC_ALL, "unicode");
	thread t_delayedChecks(delayedChecks);
	while (!TERMINATEDWMBAR)
	{
		printf("%s\n", &updateBar()[0]);
		this_thread::sleep_for(chrono::seconds(1));
	}
	t_delayedChecks.join();
	return 0;
}

string updateBar()
{
	return (string) "[" + dwm_usage + "] " +
		   "[" + getCurrentVolume() + "] " +
		   "[" + getCurrentBatteryPercentage() + "] " +
		   "[ " + getCurrentDateTime("%X") + " ]";
}

void delayedChecks()
{
	while (!TERMINATEDWMBAR)
	{
		dwm_usage = getUsage();
		this_thread::sleep_for(chrono::seconds(2));
	}
	return;
}