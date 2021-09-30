#pragma once
namespace autotruck
{
    namespace control
    {
        class TurnLightFilter
        {
        public:
            TurnLightFilter() = default;
            ~TurnLightFilter() = default;
            bool filter(unsigned int signal_input, double filter_dt_s, double cycle_time_s = 0.02);

        private:
            int count_ = 0;
            double elapsed_time_ = 0;
            bool self_lock_ = false;
        };
    }
}
