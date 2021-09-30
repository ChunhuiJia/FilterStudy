#pragma once

class RC_LowPassFilter
{
private:
    double _last_output = 0;
    double _rcPart = 0;

public:
    RC_LowPassFilter() = default;
    ~RC_LowPassFilter() = default;
    double filter(double raw_input, double dt, double filter_coeff);
};
