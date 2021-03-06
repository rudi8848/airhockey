#include "App.hpp"

App::App()
{
    id_state = STATE_NULL;
    next_state = STATE_NULL;
    window = nullptr;
    screen = nullptr;
    room = nullptr;
    font = nullptr;
    menu = nullptr;
}

App::~App()
{

}

e_state App::onExecute()
{
    if (onInit() == false)
        throw InitError("SDL Initialize failed!");

    onStart();
    SDL_Event e;

    while (id_state != EXIT)
    {

        onLoop();
        onRender();

        next_state = (e_state)room->onEvent(&e);
        updateState();
    }

    onQuit();
    return STATE_NULL;
}

