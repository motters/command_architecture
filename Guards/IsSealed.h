#pragma once

#include "Guard.h"

namespace Guards
{
    class IsSealed : Guard
    {
        public:

            IsSealed()
            {

            }

            virtual bool validate()
            {
                return true;
            };
    };
}