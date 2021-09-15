#include "RC_LowPassFilter.h"

double RC_LowPassFilter::filter(double raw_input, double dt)
{

    double output = raw_input - _rcPart;
    double d_out = output - _last_output;
    _rcPart = _filter_coeff * d_out / _dt;
    _last_output = output;
    return output;
}