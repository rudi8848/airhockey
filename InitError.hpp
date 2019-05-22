#ifndef INIT_ERROR
#define INIT_ERROR

#include <SDL_error.h>
#include <exception>
#include <string>

class InitError : public std::exception
{
    public:
        InitError();
        InitError(const std::string &msg);
        virtual ~InitError() throw();

        virtual const char* what() const throw();
    private:
    std::string mes;
};

#endif // INIT_ERROR
