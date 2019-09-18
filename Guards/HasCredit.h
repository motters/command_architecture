#pragma once

#include "Guard.h"

namespace Guards
{
    class HasCredit : Guard
    {
        public:

            HasCredit()
            {

            }

            virtual bool validate()
            {
                return true;
            };
    };
}