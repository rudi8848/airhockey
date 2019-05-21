#include "App.hpp"

void App::onEvent(SDL_Event* e)
{
    Event::onEvent(e);
}

void App::onExit()
{
    _running = false;
}

void App::onWindowExposed()
{
    onRender();
}

void App::move(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{
	player->move(sym, mod, scancode);
	enemy->move(sym, mod, scancode);
}