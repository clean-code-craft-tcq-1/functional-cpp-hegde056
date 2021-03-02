#include <assert.h>
#include <iostream>
using namespace std;

#define TEMP_MIN_THRESHOLD 0.00f
#define TEMP_MAX_THRESHOLD 45.00f

#define SOC_MIN_THRESHOLD 20.00f
#define SOC_MAX_THRESHOLD 80.00f

#define CHARGE_RATE_MIN_THRESHOLD 0.00f
#define CHARGE_RATE_MAX_THRESHOLD 0.80f

bool checkValueInRange(float min , float max, const float &valueToCheck)
{
    if(valueToCheck >= min && valueToCheck <=max) return true;
    else return false;
}

bool temperatureIsOk(const float temperature)
{
    if(!checkValueInRange(TEMP_MIN_THRESHOLD , TEMP_MAX_THRESHOLD,temperature))
    {
    cout << "Temperature out of range!\n";
    return false;
    }
    else return true;
}

bool socIsOk(const float soc)
{
    if(!checkValueInRange(SOC_MIN_THRESHOLD , SOC_MAX_THRESHOLD,soc))
    {
    cout << "State of Charge out of range!\n";
    return false;
    }
    else return true;
}

bool chargeRateIsOk(const float chargeRate)
{
    if(!checkValueInRange(CHARGE_RATE_MIN_THRESHOLD , CHARGE_RATE_MAX_THRESHOLD,chargeRate))
    {
    cout << "Charge Rate out of range!\n";
    return false;
    }
    else return true;
}

bool batteryIsOk(const float temperature,const  float soc,const  float chargeRate) {
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
