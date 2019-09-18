#pragma once


namespace Validators
{
    class Validator
    {
    public:
        Validator()
        {

        }

        virtual bool validate() = 0;
    };
}