#include "core/gui.hpp"

Graphics::Sheet* uiSheet;
Graphics::Slice9* dialogSlice;
Graphics::Slice9* buttonSlice0;
Graphics::Slice9* buttonSlice1;
Graphics::Slice9* buttonSlice2;

Graphics::Sheet* fontSheet;

typedef std::map<char, Graphics::Region*> FontMap;
int fontWidth = 10;
int fontHeight = 26;
std::string fontMapString = "abcdefghijklmnopqrstuvwxyz0123456789\nABCDEFGHIJKLMNOPQRSTUVWXYZ()/%:.,!?";
FontMap fontMapWhite;
FontMap fontMapBlack;

void GUI::unloadAssets()
{
    delete uiSheet;
    delete dialogSlice;
    delete buttonSlice0;
    delete buttonSlice1;
    delete buttonSlice2;
    delete fontSheet;
    for(FontMap::iterator itr = fontMapWhite.begin(); itr != fontMapWhite.end(); itr++)
    {
        delete itr->second;
    }
    for(FontMap::iterator itr = fontMapBlack.begin(); itr != fontMapBlack.end(); itr++)
    {
        delete itr->second;
    }
}

void GUI::loadAssets()
{
    unloadAssets();
    uiSheet = new Graphics::Sheet("assets/sprites/ui/generic.png");
    dialogSlice = uiSheet->getSlice9Pointer(0, 0, 32);
    buttonSlice0 = uiSheet->getSlice9Pointer(0, 96, 32);
    buttonSlice1 = uiSheet->getSlice9Pointer(96, 96, 32);
    buttonSlice2 = uiSheet->getSlice9Pointer(192, 96, 32);
    fontSheet = new Graphics::Sheet("assets/sprites/ui/font.png");
    int x = 0;
    int y = 0;
    for (char c : fontMapString) {
        if (c == '\n') {
            x = 0;
            y += fontHeight;
        } else {
            fontMapWhite[c] = fontSheet->getRegionPointer(x, y, fontWidth, fontHeight);
            x += fontWidth;
        }
    }
    x = 0;
    y += fontHeight;
    for (char c : fontMapString) {
        if (c == '\n') {
            x = 0;
            y += fontHeight;
        } else {
            fontMapBlack[c] = fontSheet->getRegionPointer(x, y, fontWidth, fontHeight);
            x += fontWidth;
        }
    }
}

void GUI::drawDialog(int x, int y, int w, int h)
{
    dialogSlice->draw(x, y, w, h);
}

void GUI::drawDialog(Graphics::Rectangle rect)
{
    dialogSlice->draw(rect);
}

Graphics::Rectangle GUI::getTextBounds(std::string text, int size)
{
    int x = 0;
    int w = 0;
    int h = fontHeight;
    for (char c : text) {
        if (c == '\n') {
            x = 0;
            h += fontHeight;
        } else {
            x += fontWidth;
            if (x > w) w = x;
        }
    }
    return Graphics::Rectangle(w * size, h * size);
}

Graphics::Rectangle GUI::getTextBounds(std::string text)
{
    return getTextBounds(text, 1);
}

void GUI::drawTextWhite(std::string text, int x, int y, int size)
{
    int cx = x;
    int cy = y;
    for (char c : text) {
        if (c == '\n') {
            cx = x;
            cy += fontHeight * size;
        } else {
            Graphics::Region* region = fontMapWhite[c];
            if (region != nullptr) {
                region->draw(cx, cy, fontWidth * size, fontHeight * size);
            }
            cx += fontWidth * size;
        }
    }
}

void GUI::drawTextWhite(std::string text, int x, int y)
{
    drawTextWhite(text, x, y, 1);
}

void GUI::drawTextWhite(std::string text, Graphics::Rectangle rect, int size)
{
    Graphics::Rectangle bounds = getTextBounds(text, size);
    bounds.x = rect.x;
    bounds.y = rect.y;
    bounds.middle();
    bounds.x += (int)((float)rect.w * 0.5);
    bounds.y += (int)((float)rect.h * 0.5);
    drawTextWhite(text, bounds.x, bounds.y, size);
}

void GUI::drawTextWhite(std::string text, Graphics::Rectangle rect)
{
    drawTextWhite(text, rect, 1);
}

void GUI::drawTextBlack(std::string text, int x, int y, int size)
{
    int cx = x;
    int cy = y;
    for (char c : text) {
        if (c == '\n') {
            cx = x;
            cy += fontHeight * size;
        } else {
            Graphics::Region* region = fontMapBlack[c];
            if (region != nullptr) {
                region->draw(cx, cy, fontWidth * size, fontHeight * size);
            }
            cx += fontWidth * size;
        }
    }
}

void GUI::drawTextBlack(std::string text, int x, int y)
{
    drawTextBlack(text, x, y, 1);
}

void GUI::drawTextBlack(std::string text, Graphics::Rectangle rect, int size)
{
    Graphics::Rectangle bounds = getTextBounds(text, size);
    bounds.x = rect.x;
    bounds.y = rect.y;
    bounds.middle();
    bounds.x += (int)((float)rect.w * 0.5);
    bounds.y += (int)((float)rect.h * 0.5);
    drawTextBlack(text, bounds.x, bounds.y, size);
}

void GUI::drawTextBlack(std::string text, Graphics::Rectangle rect)
{
    drawTextBlack(text, rect, 1);
}

bool GUI::buttonWhite(int x, int y, int w, int h)
{
    if (Input::mouseX >= x && Input::mouseX < x + w && Input::mouseY >= y && Input::mouseY < y + h) {
        switch (Input::leftMouse)
        {
            case 0:
                buttonSlice1->draw(x, y, w, h);
                return false;
            case 1:
                buttonSlice2->draw(x, y, w, h);
                return true;
            default:
                buttonSlice2->draw(x, y, w, h);
                return false;
        }
    }
    buttonSlice0->draw(x, y, w, h);
    return false;
}

bool GUI::buttonWhite(Graphics::Rectangle rect)
{
    return buttonWhite(rect.x, rect.y, rect.w, rect.h);
}
