#include "player.h"

Player::Player(){}

Player::Player(int hitPoints, int maxHitPoints, std::vector<PlayingCard> hand)
{
    Player::hitPoints = hitPoints;
    Player::maxHitPoints = maxHitPoints;
    Player::hand = hand;
}

PlayingCard Player::play(){
    std::cout << "This is the base class." << std::endl;
    PlayingCard selected = getCard(1);
    removeCard(selected);
    return selected;
}

int Player::getHitPoints(){
    return Player::hitPoints;
}

void Player::setHitPoints(int value){
    Player::hitPoints = value;
}

int Player::getMaxHitPoints(){
    return Player::maxHitPoints;
}

void Player::setMaxHitPoints(int value){
    Player::maxHitPoints = value;
}

std::vector<PlayingCard> Player::getHand(){
    return Player::hand;
}

void Player::setHand(std::vector<PlayingCard> playerHand){
    Player::hand = playerHand;
}

void Player::removeCard(PlayingCard &card){
    std::vector<PlayingCard>::iterator it = hand.begin();
    for(PlayingCard c: hand){
        if(c == card){
            hand.erase(it);
            break;
        }
        it++;
    }
}

void Player::addCard(PlayingCard &card){
    Player::hand.push_back(card);
}

PlayingCard Player::getCard(int index){ 
    if(index < 0 || index > (int)Player::hand.size()-1) throw -1;
    return Player::hand[index];
}

void Player::damage(int amount){
    Player::hitPoints -= amount;
}

void Player::heal(int amount){
    if(Player::hitPoints + amount >= Player::maxHitPoints){
        Player::hitPoints = Player::maxHitPoints;
    } else{
        Player::hitPoints += amount;
    }
}

std::string Player::toString(){
    return std::to_string(Player::hitPoints) + "/" + std::to_string(Player::maxHitPoints) + "// " + std::to_string(hand.size());
}

void Player::printHand(){
    std::string output = "";
    for(PlayingCard c: hand){
        std::string add = "Card:" + c.toString() + "\n";
        output += add;
    }
    std::cout << output << std::endl;
}

User::User(int hitPoints, int maxHitPoints, std::vector<PlayingCard> hand) 
        : Player(hitPoints, maxHitPoints, hand){}

PlayingCard User::play(){
    std::cout << "This is the USER class." << std::endl;
    PlayingCard selectedCard = getCard(1);
    removeCard(selectedCard);
    return selectedCard;
}

Bot::Bot(int hitPoints, int maxHitPoints, std::vector<PlayingCard> hand) 
        : Player(hitPoints, maxHitPoints, hand){}

PlayingCard Bot::play(){
    std::cout << "This is the BOT class." << std::endl;
    PlayingCard selectedCard = getCard(getHand().size()-1);
    removeCard(selectedCard);
    return selectedCard;
}