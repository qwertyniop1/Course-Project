#include "Event.h"

Event::Event() {
}

Event::~Event() {
}

void Event::onEvent(SDL_Event * event) {
    switch (event->type) {
        //case SDL_ACTIVEEVENT
    case SDL_KEYUP:
        onKeyUp(event->key.keysym.sym, event->key.keysym.mod);
        break;

    case SDL_KEYDOWN:
        onKeyDown(event->key.keysym.sym, event->key.keysym.mod);
        break;

    case SDL_MOUSEMOTION:
        onMouseMove(event->motion.x, event->motion.y, event->motion.xrel, event->motion.yrel, (event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0,
                   (event->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0, (event->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
        break;

    case SDL_MOUSEBUTTONDOWN:
        switch (event->button.button) {
        case SDL_BUTTON_LEFT:
            onLButtonDown(event->button.x, event->button.y);
            break;
        case SDL_BUTTON_RIGHT:
            onRButtonDown(event->button.x, event->button.y);
            break;
        case SDL_BUTTON_MIDDLE:
            onMButtonDown(event->button.x, event->button.y);
            break;
        default:
            break;
        }

    case SDL_MOUSEBUTTONUP:
        switch (event->button.button) {
        case SDL_BUTTON_LEFT:
            onLButtonUp(event->button.x, event->button.y);
            break;
        case SDL_BUTTON_RIGHT:
            onRButtonUp(event->button.x, event->button.y);
            break;
        case SDL_BUTTON_MIDDLE:
            onMButtonUp(event->button.x, event->button.y);
            break;
        default:
            break;
        }

    //useless
    case SDL_JOYAXISMOTION: {
        onJoyAxis(event->jaxis.which, event->jaxis.axis, event->jaxis.value);
        break;
    }

    case SDL_JOYBALLMOTION: {
        onJoyBall(event->jball.which, event->jball.ball, event->jball.xrel, event->jball.yrel);
        break;
    }

    case SDL_JOYHATMOTION: {
        onJoyHat(event->jhat.which, event->jhat.hat, event->jhat.value);
        break;
    }

    case SDL_JOYBUTTONDOWN: {
        onJoyButtonDown(event->jbutton.which, event->jbutton.button);
        break;
    }

    case SDL_JOYBUTTONUP: {
        onJoyButtonUp(event->jbutton.which, event->jbutton.button);
        break;
    }

    case SDL_QUIT:
        onExit();
        break;

    case SDL_SYSWMEVENT:
        break;

    default:
        onUser(event->user.type, event->user.code, event->user.data1, event->user.data2);
        break;
    }
}

void Event::onInputFocus()
{
}

void Event::onInputBlur()
{
}

void Event::onKeyDown(SDL_Keycode sym, Uint16 mod) {
    
}

void Event::onKeyUp(SDL_Keycode sym, Uint16 mod)
{
}

void Event::onMouseFocus()
{
}

void Event::onMouseBlur()
{
}

void Event::onMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle)
{
}

void Event::onMouseWheel(bool Up, bool Down)
{
}

void Event::onLButtonDown(int mX, int mY)
{
}

void Event::onLButtonUp(int mX, int mY)
{
}

void Event::onRButtonDown(int mX, int mY)
{
}

void Event::onRButtonUp(int mX, int mY)
{
}

void Event::onMButtonDown(int mX, int mY)
{
}

void Event::onMButtonUp(int mX, int mY)
{
}

void Event::onJoyAxis(Uint8 which, Uint8 axis, Sint16 value)
{
}

void Event::onJoyButtonDown(Uint8 which, Uint8 button)
{
}

void Event::onJoyButtonUp(Uint8 which, Uint8 button)
{
}

void Event::onJoyHat(Uint8 which, Uint8 hat, Uint8 value)
{
}

void Event::onJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel)
{
}

void Event::onMinimize()
{
}

void Event::onRestore()
{
}

void Event::onResize(int w, int h)
{
}

void Event::onExpose()
{
}

void Event::onExit()
{
}

void Event::onUser(Uint8 type, int code, void * data1, void * data2)
{
}
