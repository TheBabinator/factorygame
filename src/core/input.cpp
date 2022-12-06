#include "core/input.hpp"

bool Input::allowInputText = false;
std::string Input::inputText = "";
int Input::mouseX = 0;
int Input::mouseY = 0;
int Input::leftMouse = 0;
int Input::rightMouse = 0;
int Input::middleMouse = 0;

void Input::handleEvent(SDL_Event e)
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
    }
}

void Input::update()
{
    int buttons = SDL_GetMouseState(&mouseX, &mouseY);
    if (buttons & SDL_BUTTON_LEFT) leftMouse += 1;
    else leftMouse = 0;
    if (buttons & SDL_BUTTON_RIGHT) rightMouse += 1;
    else rightMouse = 0;
    if (buttons & SDL_BUTTON_MIDDLE) middleMouse += 1;
    else middleMouse = 0;
}
