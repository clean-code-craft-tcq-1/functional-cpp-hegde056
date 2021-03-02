#include <assert.h>
#include <iostream>
using namespace std;

bool temperatureIsOk(float temperature)
{
    if(temperature < 0 || temperature > 45)
    {
    cout << "Temperature out of range!\n";
    return false;
    }
    else return true;
}

bool socIsOk(float soc)
{
    if(soc < 20 || soc > 80)
    {
    cout << "State of Charge out of range!\n";
    return false;
    }
    else return true;
}

bool chargeRateIsOk(float chargeRate)
{
    if(chargeRate > 0.8)
    {
    cout << "Charge Rate out of range!\n";
    return false;
    }
    else return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  bool temperatureOkIndicator , socOkIndicator , chargeRateOkIndicator = false ;
  temperatureOkIndicator = temperatureIsOk(temperature);
  socOkIndicator = socIsOk(soc) ;
  chargeRateOkIndicator = chargeRateIsOk(chargeRate);

  return ( temperatureOkIndicator && socOkIndicator && chargeRateOkIndicator);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
