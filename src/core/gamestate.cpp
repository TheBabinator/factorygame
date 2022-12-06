#include "core/gamestate.hpp"

Gamestate::State Gamestate::currentState = Gamestate::LOADING;

Graphics::Sheet* testSheet;
Graphics::Region* testRegion0;
Graphics::Region* testRegion1;
Graphics::Region* testRegion2;
Graphics::Region* testRegion3;

void Gamestate::update(int deltaTicks)
{
    switch (currentState)
    {
        default:
            break;
        case State::LOADING:
            if (LoadingScreen::run()) currentState = Gamestate::MENU;
            break;
        case State::MENU:
            // draw background
            {
                int hash = 0;
                for (int x = 0; x < SDLManager::screenWidth; x += 32)
                {
                    for (int y = 0; y < SDLManager::screenHeight; y += 32)
                    {
                        hash = (hash + x + y * x) % 69;
                        switch (hash % 4)
                        {
                            case 0:
                                testRegion0->draw(x, y);
                                break;
                            case 1:
                                testRegion1->draw(x, y);
                                break;
                            case 2:
                                testRegion2->draw(x, y);
                                break;
                            case 3:
                                testRegion3->draw(x, y);
                                break;
                            default:
                                break;
                        }
                    }
                }
            }
            // title
            {
                Graphics::Rectangle rect = Graphics::Rectangle(0, 200, 400, 200);
                rect.dock(0.5, 0);
                rect.middle();
                rect.x += 6;
                rect.y += 6;
                GUI::drawTextBlack("hell", rect, 6);
                rect.x -= 6;
                rect.y -= 6;
                GUI::drawTextWhite("hell", rect, 6);
                // menu frame
                rect = Graphics::Rectangle(0, -9, 300, 194);
                rect.dock(0.5, 0.5);
                rect.middle();
                GUI::drawDialog(rect);
                // new save button
                rect = Graphics::Rectangle(0, -60, 284, 40);
                rect.dock(0.5, 0.5);
                rect.middle();
                if (GUI::buttonWhite(rect)) prepareGametest();
                GUI::drawTextBlack("Start new Game", rect);
                // load save button
                rect = Graphics::Rectangle(0, -20, 284, 40);
                rect.dock(0.5, 0.5);
                rect.middle();
                if (GUI::buttonWhite(rect)) currentState = State::QUIT;
                GUI::drawTextBlack("Load existing Game", rect);
                // settings button
                rect = Graphics::Rectangle(0, 20, 284, 40);
                rect.dock(0.5, 0.5);
                rect.middle();
                if (GUI::buttonWhite(rect)) currentState = State::QUIT;
                GUI::drawTextBlack("Settings", rect);
                // quit button
                rect = Graphics::Rectangle(0, 60, 284, 40);
                rect.dock(0.5, 0.5);
                rect.middle();
                if (GUI::buttonWhite(rect)) currentState = State::QUIT;
                GUI::drawTextBlack("Exit to Desktop", rect);
                // text input test
                Input::allowInputText = true;
                rect = Graphics::Rectangle(0, -200, 400, 200);
                rect.dock(0.5, 1);
                rect.middle();
                GUI::drawTextWhite(Input::inputText, rect);
            }
            break;
        case State::GAMETEST:

            break;
    }
}

void Gamestate::init()
{
    GUI::loadAssets();
    Tiles::addContent();
    testSheet = new Graphics::Sheet("assets/sprites/tile/dirt2.png");
    testRegion0 = testSheet->getRegionPointer(0, 0, 32, 32);
    testRegion1 = testSheet->getRegionPointer(32, 0, 32, 32);
    testRegion2 = testSheet->getRegionPointer(64, 0, 32, 32);
    testRegion3 = testSheet->getRegionPointer(96, 0, 32, 32);
}

void Gamestate::kill()
{
    GUI::unloadAssets();
    Tiles::removeContent();
    delete testSheet;
    delete testRegion0;
    delete testRegion1;
    delete testRegion2;
    delete testRegion3;
}

void Gamestate::prepareGametest()
{
    currentState = State::GAMETEST;
}
