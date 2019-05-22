#include "InitError.hpp"

InitError::InitError() : ecxeption(), mes(SDL_GetError())
{

}

InitError::InitError(const std::string &msg) : exception(), mes(msg)
{

}

InitError::~InitError()
{

}

const char* InitError::what() const throw()
{
    return mes.c_str();
}
