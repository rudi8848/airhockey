#include "Event.hpp"

Event::Event()
{

}

Event::~Event()
{

}

int Event::onEvent(SDL_Event *e)
{
    int ret = 0;

    switch(e->type)
    {
        /*  keyboard events   */
        case SDL_QUIT:
        {
            ret = onExit();
            break;
        }
        case SDL_KEYDOWN:
        {
            ret = onKeyDown(e->key.keysym.sym, e->key.keysym.mod, e->key.keysym.scancode);
            break;
        }
        case SDL_KEYUP:
        {
            ret = onKeyUp(e->key.keysym.sym, e->key.keysym.mod, e->key.keysym.scancode);
            break;
        }
        /*  mouse events   */
        case SDL_MOUSEBUTTONDOWN:
        {
            switch (e->button.button)
            {
                case SDL_BUTTON_LEFT:
                {
                    onLButtonDown(e->button.x, e->button.y);
                    break;
                }
                case SDL_BUTTON_RIGHT:
                {
                    onRButtonDown(e->button.x, e->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE:
                {
                    onMButtonDown(e->button.x, e->button.y);
                    break;
                }
            }
            break;
        }
        case SDL_MOUSEMOTION:
        {
            onMouseMove(e->motion.x, e->motion.y, e->motion.xrel, e->motion.yrel, (e->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT)) != 0,(e->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0,(e->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0 );
            break;
        }
        case SDL_MOUSEBUTTONUP:
        {
            switch (e->button.button)
            {
                case SDL_BUTTON_LEFT:
                {
                    onLButtonUp(e->button.x, e->button.y);
                    break;
                }
                case SDL_BUTTON_RIGHT:
                {
                    onRButtonUp(e->button.x, e->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE:
                {
                    onMButtonUp(e->button.x, e->button.y);
                    break;
                }
            }
            break;
        }
        /*  window events   */
        case SDL_WINDOWEVENT:
        {
            switch(e->window.event)
            {
                case SDL_WINDOWEVENT_SHOWN:
                {
                    onWindowShown(e->window.windowID);
                    break;
                }
                case SDL_WINDOWEVENT_HIDDEN:
                {
                    onWindowHidden(e->window.windowID);
                    break;
                }
                case SDL_WINDOWEVENT_RESIZED:
                {
                    onWindowResize(e->window.windowID, e->window.data1, e->window.data2);
                    break;
                }
                case SDL_WINDOWEVENT_SIZE_CHANGED:
                {
                    onWindowSizeChanged(e->window.windowID, e->window.data1, e->window.data2);
                    break;
                }
                case SDL_WINDOWEVENT_ENTER:
                {
                    onMouseEnter();
                    break;
                }
                case SDL_WINDOWEVENT_LEAVE:
                {
                    onMouseLeave();
                    break;
                }
                case SDL_WINDOWEVENT_EXPOSED:
                {
                    onWindowExposed();
                    break;
                }
                case SDL_WINDOWEVENT_MOVED:
                {
                    onWindowMove(e->window.windowID, e->window.data1, e->window.data2);
                    break;
                }
                case SDL_WINDOWEVENT_MINIMIZED:
                {
                    onWindowMinimize(e->window.windowID, e->window.data1, e->window.data2);
                    break;
                }
                case SDL_WINDOWEVENT_MAXIMIZED:
                {
                    onWindowMaximize(e->window.windowID, e->window.data1, e->window.data2);
                    break;
                }
                case SDL_WINDOWEVENT_CLOSE:
                {
                    e->type = SDL_QUIT;
                    SDL_PushEvent(e);
                    break;
                }
                case SDL_WINDOWEVENT_TAKE_FOCUS:
                {
                    onTakeFocus();
                    break;
                }
                case SDL_WINDOWEVENT_RESTORED:
                {
                    onWindowRestored();
                    break;
                }
                case SDL_WINDOWEVENT_FOCUS_GAINED:
                {
                    onInputFocus();
                    break;
                }
                case SDL_WINDOWEVENT_FOCUS_LOST:
                {
                    onInputFocusLost();
                    break;
                }

            }
            break;
        }
        /*   Joystick   */
        case SDL_JOYAXISMOTION:
        {
            onJoyAxis(e->jaxis.which, e->jaxis.axis, e->jaxis.value);
            break;
        }
        case SDL_JOYBALLMOTION:
        {
            onJoyBallMotion(e->jball.which, e->jball.ball, e->jball.xrel, e->jball.yrel);
            break;
        }
        case SDL_JOYHATMOTION:
        {
            onJoyHatMotion(e->jhat.which, e->jhat.hat, e->jhat.value);
            break;
        }
        case SDL_JOYBUTTONDOWN:
        {
            onJoyButtonDown(e->jbutton.which, e->jbutton.button);
            break;
        }
        case SDL_JOYBUTTONUP:
        {
            onJoyButtonDown(e->jbutton.which, e->jbutton.button);
            break;
        }

        default:
        {
            onUser(e->user.type, e->user.code, e->user.data1, e->user.data2);
            break;
        }
    }
    return ret;
}

int Event::onExit()
{
    return 0;
}

int Event::onKeyDown(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{

    return 0;
}

int Event::onKeyUp(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{
    return 0;
}

void Event::onLButtonDown(int xm, int ym)
{

}

void Event::onRButtonDown(int xm, int ym)
{

}

void Event::onMButtonDown(int xm, int ym)
{

}

void Event::onMouseMove(int xm, int ym, int relx, int rely, bool left, bool right, bool middle)
{

}

void Event::onLButtonUp(int xm, int ym)
{

}

void Event::onRButtonUp(int xm, int ym)
{

}

void Event::onMButtonUp(int xm, int ym)
{

}

void Event::onWindowShown(int winId)
{

}

void Event::onWindowHidden(int winId)
{

}

void Event::onWindowRestored()
{

}

void Event::onWindowResize(int winId, int data1, int data2)
{

}
void Event::onWindowSizeChanged(int winId, int data1, int data2)
{

}

void Event::onMouseEnter()
{

}

void Event::onMouseLeave()
{

}

int Event::onWindowExposed()
{
    return 0;
}


void Event::onWindowMove(int winId, int data1, int data2)
{

}

void Event::onWindowMinimize(int winId, int data1, int data2)
{

}

void Event::onWindowMaximize(int winId, int data1, int data2)
{

}

void Event::onTakeFocus()
{

}

void Event::onInputFocus()
{

}

void Event::onInputFocusLost()
{

}

void Event::onJoyAxis(Uint8 which, Uint8 axis, Sint16 value)
{

}

void Event::onJoyBallMotion(Uint8 which, Uint8 axis, Sint16 xrel, Sint16 yrel)
{

}

void Event::onJoyHatMotion(Uint8 which, Uint8 hat, Uint8 button)
{

}

void Event::onJoyButtonDown(Uint8 which, Uint8 button)
{

}

void Event::onJoyButtonUp(Uint8 which, Uint8 button)
{

}

int Event::onUser(Uint8 type, int code, void *data1, void *data2)
{

}

void Event::move(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{

}
