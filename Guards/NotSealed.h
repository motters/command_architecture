#pragma once

#include "Guard.h"

namespace Guards
{
    class NotSealed : Guard
    {
        public:

            NotSealed()
            {

            }

            virtual bool validate()
            {
                return true;
            };
    };
}