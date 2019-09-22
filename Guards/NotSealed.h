#pragma once

#include "Guard.h"

#include "../Storage.h"

namespace Guards
{
    class NotSealed : Guard
    {
        public:

            static bool validate()
            {
                if(m_storage->get(2) == 2)
                    return true;

                return false;
            };

            static Storage* m_storage;
    };
}