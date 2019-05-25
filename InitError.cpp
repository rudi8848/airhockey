#include "InitError.hpp"

InitError::InitError() : exception(), mes(SDL_GetError())
{

}

InitError::InitError(const std::string &msg) : exception(), mes(msg)
{

}

InitError::~InitError() throw()
{

}

const char* InitError::what() const throw()
{
    return mes.c_str();
}
