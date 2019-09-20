#pragma once

#include <map>

#include "Contract.h"

namespace Commands
{
    class Directory
    {
        public:

            enum class List
            {
                StartCalibration,
                LLineCurrentCalibration,
                RelayOn,
                RelayOff,
            };


            void call(List function, Contract contract)
            {

            }




    };
}