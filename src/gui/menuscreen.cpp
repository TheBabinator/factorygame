#include "gui/menuscreen.hpp"
#include "core/gamestate.hpp"

namespace Menuscreen
{
    enum MenuDialog
    {
        MAIN,
        NEW_GAME,
        NEW_GAME_ADVANCED,
    } currentDialog = MAIN;

    enum EditingField
    {
        NONE,
        SAVE_NAME,
        RANDOM_SEED,
    } editing = NONE;

    std::string saveName = "";
    std::string randomSeed = "";

    void run()
    {
        switch (currentDialog)
        {
            case MAIN:
                mainDialog();
                break;
            case NEW_GAME:
                newGameDialog();
                break;
            case NEW_GAME_ADVANCED:
                newGameAdvancedDialog();
                break;
        }
    }

    void mainDialog()
    {
        // title text
        Graphics::Rectangle rect = Graphics::Rectangle(0, 200, 400, 200);
        rect.dock(0.5, 0);
        rect.middle();
        rect.x += 6;
        rect.y += 6;
        GUI::drawTextBlack("Astrocolony", rect, 6);
        rect.x -= 6;
        rect.y -= 6;
        GUI::drawTextWhite("Astrocolony", rect, 6);
        // menu frame
        rect = Graphics::Rectangle(0, -9, 300, 194);
        rect.dock(0.5, 0.5);
        rect.middle();
        GUI::drawDialog(rect);
        // new save button
        rect = Graphics::Rectangle(0, -60, 284, 40);
        rect.dock(0.5, 0.5);
        rect.middle();
        if (GUI::buttonWhite(rect)) {
            currentDialog = NEW_GAME;
            saveName = "My Game";
            randomSeed = "";
            for (int i = 0; i < 20; i++)
            {
                randomSeed += std::to_string(rand() % 10);
            }
        }
        GUI::drawTextBlack("Start new Game", rect);
        // load save button
        rect = Graphics::Rectangle(0, -20, 284, 40);
        rect.dock(0.5, 0.5);
        rect.middle();
        if (GUI::buttonWhite(rect)) Gamestate::currentState = Gamestate::QUIT;
        GUI::drawTextBlack("Load existing Game", rect);
        // settings button
        rect = Graphics::Rectangle(0, 20, 284, 40);
        rect.dock(0.5, 0.5);
        rect.middle();
        if (GUI::buttonWhite(rect)) Gamestate::currentState = Gamestate::QUIT;
        GUI::drawTextBlack("Settings", rect);
        // quit button
        rect = Graphics::Rectangle(0, 60, 284, 40);
        rect.dock(0.5, 0.5);
        rect.middle();
        if (GUI::buttonWhite(rect)) Gamestate::currentState = Gamestate::QUIT;
        GUI::drawTextBlack("Exit to Desktop", rect);
    }

    void newGameDialog()
    {
        // text input
        switch (editing)
        {
            case NONE:
                Input::allowInputText = false;
                Input::inputText = "";
                break;
            case SAVE_NAME:
                Input::allowInputText = true;
                Input::inputText = Input::inputText.substr(0, 20);
                saveName = Input::inputText;
                break;
            case RANDOM_SEED:
                Input::allowInputText = true;
                Input::inputText = Input::inputText.substr(0, 20);
                randomSeed = Input::inputText;
                break;
        }
        // frame
        Graphics::Rectangle dialogRect = Graphics::Rectangle(0, -250, 600, 350);
        dialogRect.dock(0.5, 1);
        dialogRect.middle();
        dialogRect.add(8);
        dialogRect.y -= 18;
        dialogRect.h += 18;
        GUI::drawDialog(dialogRect);
        GUI::drawTextWhite("New Game", dialogRect.x + 8, dialogRect.y);
        // inner rectangle
        Graphics::Rectangle innerRect = Graphics::Rectangle(0, -250, 600, 350);
        innerRect.dock(0.5, 1);
        innerRect.middle();
        GUI::drawTextWhite("blah blah", Graphics::Rectangle(innerRect.x + 380, innerRect.y, 220, 350));
        // save name field
        GUI::drawTextWhite("Name:", Graphics::Rectangle(innerRect.x, innerRect.y, 80, 40));
        if (GUI::buttonWhite(innerRect.x + 80, innerRect.y, 300, 40))
        {
            Input::inputText = saveName;
            editing = SAVE_NAME;
        }
        GUI::drawTextBlack(saveName, Graphics::Rectangle(innerRect.x + 80, innerRect.y, 300, 40));
        // random seed field
        GUI::drawTextWhite("Seed:", Graphics::Rectangle(innerRect.x, innerRect.y + 40, 80, 40));
        if(GUI::buttonGreen(innerRect.x + 340, innerRect.y + 40, 40, 40))
        {
            randomSeed = "";
            for (int i = 0; i < 20; i++)
            {
                randomSeed += std::to_string(rand() % 10);
            }
        }
        GUI::drawTextBlack("Rnd", Graphics::Rectangle(innerRect.x + 340, innerRect.y + 40, 40, 40));
        if (GUI::buttonWhite(innerRect.x + 80, innerRect.y + 40, 260, 40))
        {
            Input::inputText = randomSeed;
            editing = RANDOM_SEED;
        }
        GUI::drawTextBlack(randomSeed, Graphics::Rectangle(innerRect.x + 80, innerRect.y + 40, 260, 40));
        // start button
        if (GUI::buttonGreen(innerRect.x, innerRect.y + 100, 100, 40))
        {
            Gamestate::prepareGametest();
        }
    }

    void newGameAdvancedDialog()
    {

    }
}
