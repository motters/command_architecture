#pragma once

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

    };
}