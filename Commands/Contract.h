#pragma once

#include <string>
#include <vector>
#include <any>

namespace Commands
{
    class Contract
    {
        public:
            bool status = false;

            bool validLength = false;

            std::vector < std::any > params;


    };
}