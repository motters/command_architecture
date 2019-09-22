#pragma once

#include <iostream>

#include "../Command.h"
#include "../Contract.h"

#include "../../Validators/Range.h"

#include "../../Guards/NotSealed.h"

namespace Commands { namespace Methods
{
    class Radio : Command
    {
        public:

            Radio()
            {

            }

            bool setFrequency(Contract& contract)
            {
                // Validates and returns value
                auto frequency = get<uint32_t>(contract.params, 1);
                auto mode = get<uint8_t>(contract.params, 2);

                // If validation passed
                if( parameterValidation(frequency, mode) &&

                    // Run guards
                    Guards::NotSealed::validate() &&

                    // Run validators
                    Validators::Range::between<uint32_t>(frequency.value, 800000000,900000000))
                {
                    // This would set a value in storage or at most would run an Event::X::function
                    std::cout << "Setting frequency to: " << frequency.value << " Mode: " << mode.value << std::endl;

                    // Data to send back to interface
                    response<uint32_t, uint8_t>(contract, frequency, mode);
                }

                // Return result
                return contract.commandStatus;
            }

    };
}}