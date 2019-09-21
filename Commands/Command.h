#pragma once

#include <iostream>
#include <tuple>

#include "Contract.h"

namespace Commands
{
    class Command
    {
        public:

            template<typename T>
            struct Value
            {
                bool state = false;
                T value;

                void set(bool s, T v)
                {
                    state = v;
                    value = v;
                }
            };

            template<typename T>
            Value<T> get(std::any param)
            {
                Value<T> rtn;
                if(param.has_value() && param.type().name() == typeid(T).name())
                    rtn.set(true, std::any_cast<T>(param));

                return rtn;
            }
    };
}