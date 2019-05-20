#ifndef EVENT_H
#define EVENT_H

#include <SDL2/SDL.h>

class Event
{
    public:
    Event();
    virtual ~Event();

    virtual void onEvent(SDL_Event *e);
    virtual void onExit();
    virtual void onKeyDown(SDL_Keycode sym, Uint16 mod, Uint16 scancode);
    virtual void onKeyUp(SDL_Keycode sym, Uint16 mod, Uint16 scancode);
    /*  Mouse button down   */
    virtual void onLButtonDown(int xm, int ym);
    virtual void onRButtonDown(int xm, int ym);
    virtual void onMButtonDown(int xm, int ym);
    /*  Mouse move   */
    virtual void onMouseMove(int xm, int ym, int relx, int rely, bool left, bool right, bool middle);
    /*  Mouse button up   */
    virtual void onLButtonUp(int xm, int ym);
    virtual void onRButtonUp(int xm, int ym);
    virtual void onMButtonUp(int xm, int ym);
    /*  Window events   */
    virtual void onWindowShown(int winId);
    virtual void onWindowHidden(int winId);
    virtual void onWindowResize(int winId, int data1, int data2);
    virtual void onWindowSizeChanged(int winId, int data1, int data2);
    virtual void onMouseEnter();
    virtual void onMouseLeave();
    virtual void onWindowExposed();
    virtual void onWindowMove(int winId, int data1, int data2);
    virtual void onWindowMinimize(int winId, int data1, int data2);
    virtual void onWindowMaximize(int winId, int data1, int data2);
    virtual void onTakeFocus();
    virtual void onWindowRestored();
    virtual void onInputFocus();
    virtual void onInputFocusLost();
    /*  Joystick events   */
    virtual void onJoyAxis(Uint8 which, Uint8 axis, Sint16 value);
    virtual void onJoyBallMotion(Uint8 which, Uint8 axis, Sint16 xrel, Sint16 yrel);
    virtual void onJoyHatMotion(Uint8 which, Uint8 hat, Uint8 button);
    virtual void onJoyButtonDown(Uint8 which, Uint8 button);
    virtual void onJoyButtonUp(Uint8 which, Uint8 button);
    virtual void onUser(Uint8 type, int code, void *data1, void *data2);

    private:

};

#endif // EVENT_H
