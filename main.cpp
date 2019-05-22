#include "App.hpp"

int main(int argc, char *argv[])
{

    try
    {
        App game;
        return game.onExecute();
    }
    catch (const InitError &err)
    {
        //std::cerr << "Error: " << err.what() << std::endl;
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Air hockey error", err.what(), NULL);
    }
}
