#pragma once

#include "Validator.h"

namespace Validators
{
    class Length : Validator
    {
        public:

            Length()
            {

            }

            virtual bool validate()
            {
                return true;
            };

    };
}