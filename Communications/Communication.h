#pragma once

#include <string>
#include <vector>
#include <any>

#include "../Commands/Contract.h"
#include "../Commands/CommandList.h"

#include "../Validators/Length.h"

#include "../Tools/GetAny.h"

namespace Communications
{
    template <typename T>
    class Communication  : Tools::GetAny
    {
    public:
        Communication()
        {

        }

        enum class ParseErrors
        {
            InvalidCommandSpecifier,
            InvalidDataLength,
            InvalidDataType,
            None,
        };

        void updateContract(Commands::Contract& contract, Commands::List command, ParseErrors result)
        {
            switch (result)
            {
                case ParseErrors::InvalidDataLength:
                    contract.status = false;
                    contract.validLength = false;
                    contract.command = command;
                    break;
                case ParseErrors::InvalidCommandSpecifier:
                    contract.status = false;
                    contract.validLength = true;
                    contract.command = command;
                    break;
                case ParseErrors::InvalidDataType:
                    contract.status = false;
                    contract.validLength = false;
                    contract.command = command;
                    break;
                case ParseErrors::None:
                    contract.status = true;
                    contract.validLength = true;
                    contract.command = command;
                    break;
            }
        }

        ParseErrors parseOut(Commands::Contract& contract, const std::string & format)
        {
            // Iterate through the format string
            std::string::const_iterator i = format.begin ();
            int param = -1;
            contract.communicationsOutput = "";
            while (i != format.end ())
            {
                // Find a conversion specifier
                if (*i == '%')
                {
                    param++;
                    // Get the conversion specifier type (c,f,s etc)
                    ++i;
                    char specifier = *i;

                    // Move on pass the conversion specifier for next loop
                    ++i;

                    // Find correct conversion specifier
                    switch (specifier)
                    {
                        case 'i':
                        {
                            // Validates and returns int value
                            auto value = get<uint32_t>(contract.returns.at(param));
                            if(value.state)
                            {
                                contract.communicationsOutput += std::to_string(value.value);
                            }
                            else
                            {
                                return ParseErrors::InvalidDataType;
                            }

                            break;
                        }
                        case 'f':
                        {
                            // Validates and returns int value
                            auto value = get<float>(contract.returns.at(param));

                            if(value.state)
                            {
                                contract.communicationsOutput += std::to_string(value.value);
                            }
                            else
                            {
                                return ParseErrors::InvalidDataType;
                            }

                            break;
                        }
                        case '4':
                        {
                            // Validates and returns int value
                            auto value = get<uint32_t>(contract.returns.at(param));
                            if(value.state)
                            {
                                uint8_t out[4];
                                *(uint32_t*)&out = value.value;
                                contract.communicationsOutput.push_back(out[3]);
                                contract.communicationsOutput.push_back(out[2]);
                                contract.communicationsOutput.push_back(out[1]);
                                contract.communicationsOutput.push_back(out[0]);
                            }
                            else
                            {
                                return ParseErrors::InvalidDataType;
                            }
                            break;
                        }
                        case '3':
                        {
                            // Validates and returns int value
                            auto value = get<uint32_t>(contract.returns.at(param));
                            if(value.state)
                            {
                                uint8_t out[4];
                                *(uint32_t*)&out = value.value;
                                contract.communicationsOutput.push_back(out[2]);
                                contract.communicationsOutput.push_back(out[1]);
                                contract.communicationsOutput.push_back(out[0]);
                            }
                            else
                            {
                                return ParseErrors::InvalidDataType;
                            }
                            break;
                        }
                        case '2':
                        {
                            // Validates and returns int value
                            auto value = get<uint16_t>(contract.returns.at(param));
                            if(value.state)
                            {
                                uint8_t out[2];
                                *(uint16_t*)&out = value.value;
                                contract.communicationsOutput.push_back(out[1]);
                                contract.communicationsOutput.push_back(out[0]);
                            }
                            else
                            {
                                return ParseErrors::InvalidDataType;
                            }

                            break;
                        }
                        case '1':
                        {
                            // Validates and returns int value
                            auto value = get<uint8_t>(contract.returns.at(param));
                            if(value.state)
                            {
                                contract.communicationsOutput.push_back(value.value);
                            }
                            else
                            {
                                return ParseErrors::InvalidDataType;
                            }

                            break;
                        }
                        case 'c':
                        {
                            // Validates and returns int value
                            auto value = get<char>(contract.returns.at(param));
                            if(value.state)
                            {
                                contract.communicationsOutput.push_back(value.value);
                            }
                            else
                            {
                                return ParseErrors::InvalidDataType;
                            }

                            break;
                        }
                        case 's':
                        {
                            // Validates and returns int value
                            auto value = get<std::string>(contract.returns.at(param));
                            if(value.state)
                            {
                                contract.communicationsOutput += value.value;
                            }
                            else
                            {
                                return ParseErrors::InvalidDataType;
                            }

                            break;
                        }
                        default:
                            // Invalid conversion specifier
                            return ParseErrors::InvalidCommandSpecifier;
                    }

                }
                else
                {
                    // Append characters to output string
                    contract.communicationsOutput += *i;

                    // Move onto next format char
                    ++i;
                }
            }

            // String parsed successfully
            return ParseErrors::None;
        }

        /**
         * Simplier to sscanf but more specified for the application
         *
         * @param str the string to be parsed
         * @param format format the string should be parsed to
         * @param result container to put the parsed values
         */
        virtual ParseErrors parseIn(std::string str, const std::string & format, std::vector < std::any > &result)
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
                                anyType = (uint32_t) std::stoi(str.substr (0, str.find(*i)));
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
                                anyType = (float)std::stof(str.substr (0, str.find (*i)));
                            }
                            else
                            {
                                return ParseErrors::InvalidDataLength;
                            }
                            break;
                        case 'g':
                        {
                            // Create uint32_t using 4 consecutive bytes
                            if(Validators::Length::greaterThanEqualTo(str, 4))
                            {
                                uint8_t in[4] = {(uint8_t)str.at(3), (uint8_t)str.at(2), (uint8_t)str.at(1), (uint8_t)str.at(0)};
                                float out = *(float*)&in;
                                anyType = out;
                                str.erase(0, 4);
                            }
                            else
                            {
                                return ParseErrors::InvalidDataLength;
                            }
                            break;
                        }
                        case '4':
                        {
                            // Create uint32_t using 4 consecutive bytes
                            if(Validators::Length::greaterThanEqualTo(str, 4))
                            {
                                uint8_t in[4] = {(uint8_t)str.at(3), (uint8_t)str.at(2), (uint8_t)str.at(1), (uint8_t)str.at(0)};
                                uint32_t out = *(uint32_t*)&in;
                                anyType = out;
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
                                /*uint32_t byte1 = ((uint8_t) str.substr (0, 1).at(0)) << 16;
                                uint32_t byte2 = ((uint8_t) str.substr (1, 2).at(0)) << 8;
                                uint32_t byte3 = ((uint8_t) str.substr (2, 3).at(0));
                                anyType  = (uint32_t) (byte1 + byte2 + byte3);*/

                                uint8_t in[4] = {0, (uint8_t)str.at(2), (uint8_t)str.at(1), (uint8_t)str.at(0)};
                                uint32_t out = *(uint32_t*)&in;
                                anyType = out;
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
                                /*uint16_t byte1 = ((uint8_t) str.substr (0, 1).at(0)) << 8;
                                uint16_t byte2 = ((uint8_t) str.substr (1, 2).at(0));
                                anyType  = (uint16_t) (byte1 + byte2);*/
                                uint8_t in[2] = {(uint8_t)str.at(1), (uint8_t)str.at(0)};
                                uint16_t out = *(uint16_t*)&in;
                                anyType = out;
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