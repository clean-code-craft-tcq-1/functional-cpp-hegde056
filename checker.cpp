#include <assert.h>
#include <iostream>
#include <string.h>
using namespace std;

#define TEMP_MIN_THRESHOLD 0.00f
#define TEMP_MAX_THRESHOLD 45.00f

#define SOC_MIN_THRESHOLD 20.00f
#define SOC_MAX_THRESHOLD 80.00f

#define CHARGE_RATE_MIN_THRESHOLD 0.00f
#define CHARGE_RATE_MAX_THRESHOLD 0.80f

bool checkValueInRange(float min , float max, const float &valueToCheck ,const std::string &paramName)
{
    if(valueToCheck >= min && valueToCheck <=max) return true;
    else
    {
        cout << paramName << " out of range!" <<endl;
        return false;
    }
}

bool checkTemperatureIsOk(const float temperature)
{
    return checkValueInRange(TEMP_MIN_THRESHOLD , TEMP_MAX_THRESHOLD,temperature, "Temperature");
}

bool checkSocIsOk(const float soc)
{
    return checkValueInRange(SOC_MIN_THRESHOLD , SOC_MAX_THRESHOLD,soc , "State of Charge");
}

bool checkChargeRateIsOk(const float chargeRate)
{
    return checkValueInRange(CHARGE_RATE_MIN_THRESHOLD , CHARGE_RATE_MAX_THRESHOLD,chargeRate, "Charge Rate");
}

bool batteryIsOk(const float temperature,const  float soc,const  float chargeRate) {
  bool temperatureOkIndicator , socOkIndicator , chargeRateOkIndicator = false ;

  temperatureOkIndicator = checkTemperatureIsOk(temperature);
  socOkIndicator = checkSocIsOk(soc) ;
  chargeRateOkIndicator = checkChargeRateIsOk(chargeRate);

  return ( temperatureOkIndicator && socOkIndicator && chargeRateOkIndicator);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
