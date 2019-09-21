#pragma once

#include <any>


namespace Tools
{
    class GetAny
    {
    public:

        template<typename T>
        struct Value
        {
            bool state = false;
            T value;

            void set(bool s, T v)
            {
                state = s;
                value = v;
            }
        };

        template<typename T>
        Value<T> get(std::vector<std::any> vec, int i)
        {
            if(vec.size() > i)
                return Tools::GetAny::get<T>(vec.at(i));

            Value<T> a;
            return a;
        }

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