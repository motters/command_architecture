#pragma once

#include "Validator.h"

namespace Validators
{
    class Contains : Validator
    {
        public:
            Contains()
            {

            }

            virtual bool validate()
            {
                return true;
            };

    };
}