#pragma once

#include <string>
#include <vector>
#include <any>

#include "../Commands/Contract.h"

#include "../Validators/Length.h"

namespace Interfaces
{
    template <typename T>
    class Interface
    {
    public:
        Interface()
        {

        }

        enum class ParseErrors
        {
            InvalidCommandSpecifier,
            InvalidDataLength,
            None,
        };


        void updateContract(Commands::Contract& contract, ParseErrors result)
        {
            switch (result)
            {
                case ParseErrors::InvalidDataLength:
                    contract.status = false;
                    contract.validLength = false;
                    break;
                case ParseErrors::InvalidCommandSpecifier:
                    contract.status = false;
                    contract.validLength = true;
                    break;
                case ParseErrors::None:
                    contract.status = true;
                    contract.validLength = true;
                    break;
            }
        }

        /**
         * Simplier to sscanf but more specified for the application
         *
         * @param str the string to be parsed
         * @param format format the string should be parsed to
         * @param result container to put the parsed values
         */
        virtual ParseErrors parse(std::string str, const std::string & format, std::vector < std::any > &result)
        {
            // Iterate through the format string
            std::string::const_iterator i = format.begin ();
            while (i != format.end ())
            {
                // Find a conversion specifier
                if (*i == '%')
                {
                    // Get the conversion specifier type (c,f,s etc)
                    ++i;
                    char specifier = *i;

                    // Move on pass the conversion specifier for next loop
                    ++i;

                    // Create a temp type
                    std::any anyType;

                    // Find correct conversion specifier
                    switch (specifier)
                    {
                        case 'i':
                            // Save int using all bytes till next %
                            if(Validators::Length::greaterThanEqualTo(str, 1))
                            {
                                anyType = std::stoi(str.substr (0, str.find(*i)));
                            }
                            else
                            {
                                return ParseErrors::InvalidDataLength;
                            }

                            break;
                        case 'f':
                            // Save float using all bytes till next %
                            if(Validators::Length::greaterThanEqualTo(str, 1))
                            {
                                anyType = std::stof(str.substr (0, str.find (*i)));
                            }
                            else
                            {
                                return ParseErrors::InvalidDataLength;
                            }
                            break;
                        case '4':
                        {
                            // Create uint32_t using 4 consecutive bytes
                            if(Validators::Length::greaterThanEqualTo(str, 4))
                            {
                                uint32_t byte1 = ((uint32_t) str.substr(0, 1).at(0)) << 24;
                                uint32_t byte2 = ((uint32_t) str.substr(1, 2).at(0)) << 16;
                                uint32_t byte3 = ((uint32_t) str.substr(2, 3).at(0)) << 8;
                                uint32_t byte4 = ((uint32_t) str.substr(3, 4).at(0));
                                anyType = (uint32_t) (byte1 + byte2 + byte3 + byte4);
                                str.erase(0, 4);
                            }
                            else
                            {
                                return ParseErrors::InvalidDataLength;
                            }
                            break;
                        }
                        case '3':
                        {
                            // Create uint32_t using 3 consecutive bytes
                            if(Validators::Length::greaterThanEqualTo(str, 3))
                            {
                                uint32_t byte1 = ((uint32_t) str.substr (0, 1).at(0)) << 16;
                                uint32_t byte2 = ((uint32_t) str.substr (1, 2).at(0)) << 8;
                                uint32_t byte3 = ((uint32_t) str.substr (2, 3).at(0));
                                anyType  = (uint32_t) (byte1 + byte2 + byte3);
                                str.erase (0, 3);
                            }
                            else
                            {
                                return ParseErrors::InvalidDataLength;
                            }
                            break;
                        }
                        case '2':
                        {
                            // Create uin162_t using 2 consecutive bytes
                            if(Validators::Length::greaterThanEqualTo(str, 2))
                            {
                                uint16_t byte1 = ((uint32_t) str.substr (0, 1).at(0)) << 8;
                                uint16_t byte2 = ((uint32_t) str.substr (1, 2).at(0));
                                anyType  = (uint32_t) (byte1 + byte2);
                                str.erase (0, 2);
                            }
                            else
                            {
                                return ParseErrors::InvalidDataLength;
                            }
                            break;
                        }
                        case '1':
                        {
                            // Create uint8_t using 1 consecutive bytes
                            if(Validators::Length::greaterThanEqualTo(str, 1))
                            {
                                anyType = (uint8_t) str.substr (0, 1).at(0);
                                str.erase (0, 1);
                            }
                            else
                            {
                                return ParseErrors::InvalidDataLength;
                            }
                            break;
                        }
                        case 'c':
                            // Create char
                            if(Validators::Length::greaterThanEqualTo(str, 1))
                            {
                                anyType = str.substr (0, 1).at(0);
                                str.erase (0, 1);
                            }
                            else
                            {
                                return ParseErrors::InvalidDataLength;
                            }
                            break;
                            // matching a string
                        case 's':
                            // Create string
                            if(Validators::Length::greaterThanEqualTo(str, 1))
                            {
                                anyType = str.substr (0, str.find (*i));
                            }
                            else
                            {
                                return ParseErrors::InvalidDataLength;
                            }
                            break;
                        default:
                            // Invalid conversion specifier
                            return ParseErrors::InvalidCommandSpecifier;
                    }

                    // Add value to container
                    if(anyType.has_value())
                    {
                        result.push_back(anyType);
                    }
                }
                else
                {
                    // If next format char is not % delete it
                    str.erase (0, str.find (*i) + 1);

                    // Move onto next format char
                    ++i;
                }
            }

            // String parsed successfully
            return ParseErrors::None;
        }

        virtual Commands::Contract handle(T input) = 0;
    };
}