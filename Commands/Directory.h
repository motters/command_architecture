#pragma once

#include <map>

#include "Contract.h"

#include "CommandList.h"

#include "Radio.h"

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
                    case List::SetRelay:
                        return false;
                    case List::GetRelay:
                        return false;
                    case List::enableCredit:
                        return false;
                    case List::AddCredit:
                        return false;
                    default:
                        return false;
                }
            }


        private:
            Radio m_radio;

    };
}