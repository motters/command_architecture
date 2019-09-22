#pragma once

#include <map>

#include "Contract.h"

#include "CommandList.h"

#include "Methods/Radio.h"

namespace Commands
{
    class Directory
    {
        public:

            Directory()
                : m_radio()
            {

            }

            bool call(Contract& contract)
            {
                switch(contract.command)
                {
                    case List::SetFrequency:
                        return m_radio.setFrequency(contract);
                    default:
                        return false;
                }
            }


        private:
            Methods::Radio m_radio;

    };
}