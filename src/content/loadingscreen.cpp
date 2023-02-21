#include "content/loadingscreen.hpp"

std::queue<Registry::Content*>* loadQueue;

int numContent = 1;
int numLoaded = 0;

bool LoadingScreen::run()
{
    Graphics::Rectangle titleRect = Graphics::Rectangle(0, -100, 400, 200);
    titleRect.dock(0.5, 0.5);
    titleRect.middle();
    GUI::drawTextWhite("Astrocolony", titleRect, 6);

    Graphics::Rectangle barRect = Graphics::Rectangle(0, 100, 0, 24);
    barRect.dock(0.5, 0.5);
    barRect.scale(0.5, 0);
    barRect.middle();

    GUI::drawTextWhite("Loading Content... (" + std::to_string(numLoaded) + "/" + std::to_string(numContent) + ")", barRect.x, barRect.y - 30, 1);

    Graphics::setDrawColor(0xFF, 0xFF, 0xFF);
    Graphics::drawRectangle(barRect);

    barRect.add(-2);
    Graphics::setDrawColor(0x00, 0x00, 0x00);
    Graphics::drawRectangle(barRect);

    barRect.add(-2);
    barRect.w *= numLoaded / numContent;
    Graphics::setDrawColor(0xFF, 0xFF, 0xFF);
    Graphics::drawRectangle(barRect);

    if (loadQueue == nullptr) {
        loadQueue = Registry::master.makeQueue();
        numContent = loadQueue->size();
    } else {
        if (loadQueue->empty()) {
            delete loadQueue;
            return true;
        } else {
            Registry::Content* content = loadQueue->front();
            loadQueue->pop();
            content->load();
            numLoaded += 1;
        }
    }

    return false;
}
