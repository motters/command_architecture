#pragma once

#include <iostream>
#include <tuple>

#include "Contract.h"

#include "../Tools/GetAny.h"

namespace Commands
{
    class Command : public Tools::GetAny
    {
        public:

            template <typename ... T, typename ... Args>
            void response(Contract& contract, Args... A)
            {
                contract.commandStatus = true;

                (contract.returns.push_back(std::any_cast<T>(A.value)), ...);
            }

    };
}