#pragma once

#include "../Storage.h"

// All guards that require setup
#include "NotSealed.h"
#include "NotLocked.h"
#include "HasCredit.h"

// Definitions
Storage* Guards::NotSealed::m_storage = nullptr;


namespace Guards
{
    class GuardsInit
    {
        public:

            static void init(Storage& storage)
            {
                // Set storage class pointer
                NotSealed::m_storage = &storage;
            }
    };
}