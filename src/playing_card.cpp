#include "playing_card.h"

PlayingCard::PlayingCard(bool target, enum Type cardType, int value)
{
    PlayingCard::target = target;
    PlayingCard::cardType = cardType;
    PlayingCard::value = value;
}

PlayingCard::PlayingCard()
{
}

bool PlayingCard::operator==(PlayingCard &other)
{
    if (this->target == other.target && this->value == other.value && this->cardType == other.cardType)
    {
        return true;
    }
    return false;
}

bool PlayingCard::getTarget()
{
    return PlayingCard::target;
}

int PlayingCard::getValue()
{
    return PlayingCard::value;
}

enum Type PlayingCard::getType(){
    return PlayingCard::cardType;
}

std::string PlayingCard::toString()
{
    std::string type;
    switch (PlayingCard::cardType)
    {
    case 0:
        type = "damage";
        break;
    }

    return type + " " + std::to_string(value);
}
