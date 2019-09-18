#pragma once


namespace Guards
{
    class Guard
    {
        public:

            Guard()
            {

            }

            virtual bool validate() = 0;
    };
}