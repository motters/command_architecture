#pragma once

#include <string>

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

            static bool startsWith(std::string &str, const std::string &format)
            {
                if (str.rfind(format, 0) == 0)
                    return true;

                return false;
            }

    };
}