#pragma once

#include <iostream>

#include "Validator.h"

namespace Validators
{
    class Range : Validator
    {
        public:

            Range()
            {

            }

            virtual bool validate()
            {
                return true;
            };

            template<typename T>
            static bool between(T value, T min, T max)
            {
                if(value >= min && value <= max)
                    return true;

                return false;
            }

    };
}