#include "RC_LowPassFilter.h"

double RC_LowPassFilter::filter(double raw_input, double dt, double filter_coeff)
{
    double d_out = raw_input - _last_output;
    _rcPart = filter_coeff * d_out / dt;
    double output = raw_input - _rcPart;
    _last_output = output;
    return output;
}