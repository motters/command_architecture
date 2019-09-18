#pragma once


namespace Interfaces
{
    template <typename T>
    class Interface
    {
        public:
            Interface()
            {

            }

            virtual bool handle(T input) = 0;
    };
}