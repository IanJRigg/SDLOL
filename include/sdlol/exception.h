#ifndef SDLOL_EXCEPTION_H
#define SDLOL_EXCEPTION_H

#include <exception>
#include <string>

class SDLOL_Exception : public std::runtime_error
{
public:
    explicit SDLOL_Exception(const std::string& message) :
        runtime_error(message)
    {

    };
};

#endif