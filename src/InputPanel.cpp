#include "InputPanel.h"
#include "Constants.h"
#include "Button.h"

InputPanel::InputPanel(const Game& g)
    : score(g.score), numberOfErrors(g.numberOfErrors), difficultyLevel(g.difficultyLevel), time(g.time), saveName(g.saveName) {

    buttons.emplace_back(ButtonActions::undo, sf::FloatRect({10, 60}, {75, 75}));
    buttons.emplace_back(ButtonActions::erase, sf::FloatRect({110, 60}, {75, 75}));
    buttons.emplace_back(ButtonActions::hint, sf::FloatRect({210, 60}, {75, 75}));
    buttons.emplace_back(ButtonActions::sketchMode, sf::FloatRect({310, 60}, {75, 75}));

    buttons.emplace_back(ButtonActions::numeric1, sf::FloatRect({5, 160}, {120, 80}));
    buttons.emplace_back(ButtonActions::numeric2, sf::FloatRect({145, 160}, {120, 80}));
    buttons.emplace_back(ButtonActions::numeric3, sf::FloatRect({280, 160}, {120, 80}));
    buttons.emplace_back(ButtonActions::numeric4, sf::FloatRect({5, 250}, {120, 80}));
    buttons.emplace_back(ButtonActions::numeric5, sf::FloatRect({145, 250}, {120, 80}));
    buttons.emplace_back(ButtonActions::numeric6, sf::FloatRect({280, 250}, {120, 80}));
    buttons.emplace_back(ButtonActions::numeric7, sf::FloatRect({5, 340}, {120, 80}));
    buttons.emplace_back(ButtonActions::numeric8, sf::FloatRect({145, 340}, {120, 80}));
    buttons.emplace_back(ButtonActions::numeric9, sf::FloatRect({280, 340}, {120, 80}));

    buttons.emplace_back(ButtonActions::newGame, sf::FloatRect({5, 440}, {180, 60}));
    buttons.emplace_back(ButtonActions::saveGame, sf::FloatRect({195, 440}, {60, 60}));
    buttons.emplace_back(ButtonActions::loadGame, sf::FloatRect({265, 440}, {60, 60}));
    buttons.emplace_back(ButtonActions::exitGame, sf::FloatRect({335, 440}, {180, 60}));

}



void InputPanel::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();

    sf::Text scoreLabel(Constants::normalFont, "Score ");
    scoreLabel.setPosition({10, 0});
    scoreLabel.setFillColor(sf::Color::Black);
    scoreLabel.setCharacterSize(22);
    target.draw(scoreLabel, states);

    sf::Text timeLabel(Constants::normalFont, "Score ");
    timeLabel.setPosition({240, 0});
    timeLabel.setFillColor(sf::Color::Black);
    timeLabel.setCharacterSize(22);
    target.draw(timeLabel, states);



    ///< Undo Button
    sf::Texture undoButtonTexture;
    if (!undoButtonTexture.loadFromFile("assets/img/buttons/undoButtonTexture.png")) {
        std::cerr<<"Error occurred while loading SAVE BUTTON texture from file.";
    }
    sf::Sprite undoButtonSprite(undoButtonTexture);
    undoButtonSprite.setPosition({10, 60});
    target.draw(undoButtonSprite, states);

    ///< Erase Button
    sf::Texture eraseButtonTexture;
    if (!eraseButtonTexture.loadFromFile("assets/img/buttons/eraseButtonTexture.png")) {
        std::cerr<<"Error occurred while loading ERASE BUTTON texture from file.";
    }
    sf::Sprite eraseButtonSprite(eraseButtonTexture);
    eraseButtonSprite.setPosition({110, 60});
    target.draw(eraseButtonSprite, states);


    ///< Hint Button
    sf::Texture hintButtonTexture;
    if (!hintButtonTexture.loadFromFile("assets/img/buttons/hintButtonTexture.png")) {
        std::cerr<<"Error occurred while loading HINT BUTTON texture from file.";
    }
    sf::Sprite hintButtonSprite(hintButtonTexture);
    hintButtonSprite.setPosition({210, 60});
    target.draw(hintButtonSprite, states);


    ///< sketchMode Button
    sf::Texture sketchModeTexture;
    if (!sketchModeTexture.loadFromFile("assets/img/buttons/sketchModeOFFbuttonTexture.png")) {
        std::cerr<<"Error occurred while loading SKETCH MODE OFF BUTTON texture from file.";
    }
    sf::Sprite sketchModeSprite(sketchModeTexture);
    sketchModeSprite.setPosition({310, 60});
    target.draw(sketchModeSprite, states);


    ///< Numpad

    ///< ONE Numpad Button
    sf::Texture oneNumpadButtonTexture;
    if (!oneNumpadButtonTexture.loadFromFile("assets/img/buttons/numpadButtons/oneButtonTexture.png")) {
        std::cerr<<"Error occurred while loading ONE BUTTON BUTTON texture from file.";
    }
    sf::Sprite oneNumpadButtonSprite(oneNumpadButtonTexture);
    oneNumpadButtonSprite.setPosition({5, 160});
    target.draw(oneNumpadButtonSprite, states);


    ///< TWO Numpad Button
    sf::Texture twoNumpadButtonTexture;
    if (!twoNumpadButtonTexture.loadFromFile("assets/img/buttons/numpadButtons/twoButtonTexture.png")) {
        std::cerr<<"Error occurred while loading TWO BUTTON BUTTON texture from file.";
    }
    sf::Sprite twoNumpadButtonSprite(twoNumpadButtonTexture);
    twoNumpadButtonSprite.setPosition({145, 160});
    target.draw(twoNumpadButtonSprite, states);


    ///< THREE Numpad Button
    sf::Texture threeNumpadButtonTexture;
    if (!threeNumpadButtonTexture.loadFromFile("assets/img/buttons/numpadButtons/threeButtonTexture.png")) {
        std::cerr<<"Error occurred while loading THREE BUTTON BUTTON texture from file.";
    }
    sf::Sprite threeNumpadButtonSprite(threeNumpadButtonTexture);
    threeNumpadButtonSprite.setPosition({280, 160});
    target.draw(threeNumpadButtonSprite, states);


    ///< FOUR Numpad Button
    sf::Texture fourNumpadButtonTexture;
    if (!fourNumpadButtonTexture.loadFromFile("assets/img/buttons/numpadButtons/fourButtonTexture.png")) {
        std::cerr<<"Error occurred while loading FOUR BUTTON BUTTON texture from file.";
    }
    sf::Sprite fourNumpadButtonSprite(fourNumpadButtonTexture);
    fourNumpadButtonSprite.setPosition({5, 250});
    target.draw(fourNumpadButtonSprite, states);


    ///< FIVE Numpad Button
    sf::Texture fiveNumpadButtonTexture;
    if (!fiveNumpadButtonTexture.loadFromFile("assets/img/buttons/numpadButtons/fiveButtonTexture.png")) {
        std::cerr<<"Error occurred while loading FIVE BUTTON BUTTON texture from file.";
    }
    sf::Sprite fiveNumpadButtonSprite(fiveNumpadButtonTexture);
    fiveNumpadButtonSprite.setPosition({145, 250});
    target.draw(fiveNumpadButtonSprite, states);


    ///< SIX Numpad Button
    sf::Texture sixNumpadButtonTexture;
    if (!sixNumpadButtonTexture.loadFromFile("assets/img/buttons/numpadButtons/sixButtonTexture.png")) {
        std::cerr<<"Error occurred while loading SIX BUTTON BUTTON texture from file.";
    }
    sf::Sprite sixNumpadButtonSprite(sixNumpadButtonTexture);
    sixNumpadButtonSprite.setPosition({280, 250});
    target.draw(sixNumpadButtonSprite, states);


    ///< SEVEN Numpad Button
    sf::Texture sevenNumpadButtonTexture;
    if (!sevenNumpadButtonTexture.loadFromFile("assets/img/buttons/numpadButtons/sevenButtonTexture.png")) {
        std::cerr<<"Error occurred while loading SEVEN BUTTON BUTTON texture from file.";
    }
    sf::Sprite sevenNumpadButtonSprite(sevenNumpadButtonTexture);
    sevenNumpadButtonSprite.setPosition({5, 340});
    target.draw(sevenNumpadButtonSprite, states);


    ///< EIGHT Numpad Button
    sf::Texture eightNumpadButtonTexture;
    if (!eightNumpadButtonTexture.loadFromFile("assets/img/buttons/numpadButtons/eightButtonTexture.png")) {
        std::cerr<<"Error occurred while loading EIGHT BUTTON BUTTON texture from file.";
    }
    sf::Sprite eightNumpadButtonSprite(eightNumpadButtonTexture);
    eightNumpadButtonSprite.setPosition({145, 340});
    target.draw(eightNumpadButtonSprite, states);


    ///< NINE Numpad Button
    sf::Texture nineNumpadButtonTexture;
    if (!nineNumpadButtonTexture.loadFromFile("assets/img/buttons/numpadButtons/nineButtonTexture.png")) {
        std::cerr<<"Error occurred while loading NINE BUTTON BUTTON texture from file.";
    }
    sf::Sprite nineNumpadButtonSprite(nineNumpadButtonTexture);
    nineNumpadButtonSprite.setPosition({280, 340});
    target.draw(nineNumpadButtonSprite, states);



    ///< NEW GAME Button
    sf::Texture newGameButtonTexture;
    if (!newGameButtonTexture.loadFromFile("assets/img/buttons/newGameButtonTexture.png")) {
        std::cerr<<"Error occurred while loading NEW GAME BUTTON texture from file.";
    }
    sf::Sprite newGameButtonSprite(newGameButtonTexture);
    newGameButtonSprite.setPosition({5, 440});
    target.draw(newGameButtonSprite, states);

    ///< SAVE GAME Button
    sf::Texture saveGameButtonTexture;
    if (!saveGameButtonTexture.loadFromFile("assets/img/buttons/saveGameButtonTexture.png")) {
        std::cerr<<"Error occurred while loading SAVE GAME BUTTON texture from file.";
    }
    sf::Sprite saveGameButtonSprite(saveGameButtonTexture);
    saveGameButtonSprite.setPosition({195, 440});
    target.draw(saveGameButtonSprite, states);

    ///< LOAD GAME Button
    sf::Texture loadGameButtonTexture;
    if (!loadGameButtonTexture.loadFromFile("assets/img/buttons/loadGameButtonTexture.png")) {
        std::cerr<<"Error occurred while loading SAVE GAME BUTTON texture from file.";
    }
    sf::Sprite loadGameButtonSprite(loadGameButtonTexture);
    loadGameButtonSprite.setPosition({265, 440});
    target.draw(loadGameButtonSprite, states);


    ///< EXIT GAME Button
    sf::Texture exitGameButtonTexture;
    if (!exitGameButtonTexture.loadFromFile("assets/img/buttons/exitGameButtonTexture.png")) {
        std::cerr<<"Error occurred while loading SAVE GAME BUTTON texture from file.";
    }
    sf::Sprite exitGameButtonSprite(exitGameButtonTexture);
    exitGameButtonSprite.setPosition({335, 440});
    target.draw(exitGameButtonSprite, states);

}

void InputPanel::handleClick(const sf::Vector2f &mousePos, Board& board, Cell* selectedCell) const{
    std::cout<<"Starts handling click \n";
    for (auto& button: buttons) {
        if (button.hitbox.contains(mousePos)) {

            Button::performAction(button.buttonAction, board, selectedCell);
            return;
        }
    }
}

bool InputPanel::contains(const sf::Vector2f& mousePos) const{
    const sf::Vector2f pos = getPosition();
    const sf::FloatRect bounds({pos, panelSize});
    if (bounds.contains(mousePos)){ return true;}
    return false;
}


