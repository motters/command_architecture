#pragma once

#include "Guard.h"

namespace Guards
{
    class NotLocked : Guard
    {
        public:

            NotLocked()
            {

            }

            virtual bool validate()
            {
                return true;
            };
    };
}