#include "core/input.hpp"

namespace Input
{
    bool allowInputText = false;
    std::string inputText = "";
    int mouseX = 0;
    int mouseY = 0;
    int leftMouse = 0;
    int rightMouse = 0;
    int middleMouse = 0;
    int scrollX = 0;
    int scrollY = 0;

    std::map<std::string, KeyBinding*> keyBindings {
        {"up", new KeyBinding(SDL_SCANCODE_W)},
        {"down", new KeyBinding(SDL_SCANCODE_S)},
        {"left", new KeyBinding(SDL_SCANCODE_A)},
        {"right", new KeyBinding(SDL_SCANCODE_D)},
    };

    KeyBinding::KeyBinding(int defaultKey)
    {
        keyCode = defaultKey;
    }

    void KeyBinding::update()
    {
        const Uint8* keyboard = SDL_GetKeyboardState(NULL);
        if (keyboard[keyCode] == 0) state = 0;
        else state += 1;
    }

    void preUpdate()
    {
        scrollX = 0;
        scrollY = 0;
    }

    void handleEvent(SDL_Event e)
    {
        switch (e.type)
        {
            default:
                break;
            case SDL_KEYDOWN:
                if (allowInputText) switch (e.key.keysym.sym)
                {
                    default:
                        break;
                    case SDLK_BACKSPACE:
                        if (inputText.length() > 0) {
                            inputText.pop_back();
                        }
                        break;
                    case SDLK_RETURN:
                        inputText += "\n";
                        break;
                    case SDLK_c:
                        if (SDL_GetModState() & KMOD_CTRL) {
                            SDL_SetClipboardText(inputText.c_str());
                        }
                        break;
                    case SDLK_x:
                        if (SDL_GetModState() & KMOD_CTRL) {
                            SDL_SetClipboardText(inputText.c_str());
                            inputText = "";
                        }
                        break;
                    case SDLK_v:
                        if (SDL_GetModState() & KMOD_CTRL) {
                            inputText += SDL_GetClipboardText();
                        }
                        break;
                }
                break;
            case SDL_TEXTINPUT:
                if (allowInputText) inputText += e.text.text;
                break;
            case SDL_MOUSEWHEEL:
                scrollX = e.wheel.x;
                scrollY = e.wheel.y;
                break;
        }
    }

    void update()
    {
        int buttons = SDL_GetMouseState(&mouseX, &mouseY);
        if (buttons & SDL_BUTTON_LEFT) leftMouse += 1;
        else leftMouse = 0;
        if (buttons & SDL_BUTTON_RIGHT) rightMouse += 1;
        else rightMouse = 0;
        if (buttons & SDL_BUTTON_MIDDLE) middleMouse += 1;
        else middleMouse = 0;

        for (std::pair<std::string, KeyBinding*> pair : keyBindings)
        {
            pair.second->update();
        }
    }

    int getKeyState(std::string name)
    {
        return keyBindings[name]->state;
    }
}

