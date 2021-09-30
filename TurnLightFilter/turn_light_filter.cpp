#include "turn_light_filter.h"
// #include <iostream>
// #include <ros/ros.h>

namespace autotruck
{
    namespace control
    {
        bool TurnLightFilter::filter(unsigned int signal_input, double filter_dt_s, double cycle_time_s)
        {
            bool out_of_range = false;
            bool input_reverse = true;

            if (signal_input==0)
            {
                count_ += 1;
                elapsed_time_ = count_ * cycle_time_s;
                input_reverse = true;
                if (elapsed_time_ > filter_dt_s)
                {
                    out_of_range = true;
                }
                else{
                    out_of_range = false;
                }
            }
            else
            {
                out_of_range = false;
                input_reverse = false;
                self_lock_ = true;
                count_ = 0;
            }
            bool out1 = !(out_of_range&&input_reverse);
            if(self_lock_ == true)
            {
                return out1;
            }
            else{
                return false;
            }
        }
    }
}