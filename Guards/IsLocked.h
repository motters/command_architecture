#pragma once

#include "Guard.h"

namespace Guards
{
    class IsLocked : Guard
    {
        public:

            IsLocked()
            {

            }

            virtual bool validate()
            {
                return true;
            };
    };
}