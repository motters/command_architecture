#pragma once

#include <string>

#include "Validator.h"

namespace Validators
{
    class Length : Validator
    {
        public:

            Length()
            {

            }

            virtual bool validate(std::string data, int length)
            {
                if(data.size() >= length)
                    return true;

                return false;
            }


            static bool greaterThanEqualTo(std::string data, int length)
            {
                if(data.size() >= length)
                    return true;

                return false;
            }

    };
}