#pragma once
#include <iostream>
#include <string>
#include <map>
#include "core/graphics.hpp"
#include "core/input.hpp"

namespace GUI
{
    void unloadAssets();
    void loadAssets();

    void drawDialog(int x, int y, int w, int h);
    void drawDialog(Graphics::Rectangle rect);

    Graphics::Rectangle getTextBounds(std::string text, int size);
    Graphics::Rectangle getTextBounds(std::string text);
    void drawTextWhite(std::string text, int x, int y, int size);
    void drawTextWhite(std::string text, int x, int y);
    void drawTextWhite(std::string text, Graphics::Rectangle rect, int size);
    void drawTextWhite(std::string text, Graphics::Rectangle rect);
    void drawTextBlack(std::string text, int x, int y, int size);
    void drawTextBlack(std::string text, int x, int y);
    void drawTextBlack(std::string text, Graphics::Rectangle rect, int size);
    void drawTextBlack(std::string text, Graphics::Rectangle rect);
    bool buttonWhite(int x, int y, int w, int h);
    bool buttonWhite(Graphics::Rectangle rect);
    bool buttonGreen(int x, int y, int w, int h);
    bool buttonGreen(Graphics::Rectangle rect);
    bool buttonRed(int x, int y, int w, int h);
    bool buttonRed(Graphics::Rectangle rect);
}
