#include "pch.h"
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Devices.Power.h>
#include <iostream>

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Devices::Power;

int main()
{
    init_apartment();

    // Get the default battery
    Battery battery = Battery::AggregateBattery();
    BatteryReport report = battery.GetReport();

    // Get the design capacity and full charge capacity
    auto designCapacity = report.DesignCapacityInMilliwattHours();
    auto fullChargeCapacity = report.FullChargeCapacityInMilliwattHours();
    auto RemainingCapacity = report.RemainingCapacityInMilliwattHours();
    auto ChargeRate = report.ChargeRateInMilliwatts();

    // Print the capacities
    if (designCapacity && fullChargeCapacity)
    {
        std::wcout << L"Design Capacity: " << designCapacity.Value() << L" mWh" << std::endl;
        std::wcout << L"Full Charge Capacity: " << fullChargeCapacity.Value() << L" mWh" << std::endl;
        std::wcout << L"Remaining Capacity: " << RemainingCapacity.Value() << L" mWh" << std::endl;
        std::wcout << L"Charge Rate: " << ChargeRate.Value() << L" mW" << std::endl;

        // Calculate and print the remaining capacity percentage
        double remainingCapacityPercentage = (static_cast<double>(fullChargeCapacity.Value()) / designCapacity.Value()) * 100;
        std::wcout << L"Remaining Capacity: " << remainingCapacityPercentage << L"%" << std::endl;
    }
    else
    {
        std::wcout << L"Unable to retrieve battery capacities." << std::endl;
    }

    // Existing code

    return 0;
}
