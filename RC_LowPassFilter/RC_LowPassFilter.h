#pragma once

class RC_LowPassFilter
{
private:
    double _dt = 0.01;
    double _last_output = 0;
    double _filter_coeff = 0.2;
    double _rcPart = 0;

public:
    RC_LowPassFilter() = default;
    ~RC_LowPassFilter() = default;
    double filter(double raw_input, double dt);
};
