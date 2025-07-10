#include <iostream>
#include <string>

using namespace std;

// Interface for Character (Component)
class ICharacter
{
public:
    virtual string getAbilities() = 0;
    virtual ~ICharacter() {}
};

// Concrete Component
class MarioCharacter : public ICharacter
{
public:
    string getAbilities() override
    {
        return "Mario Character";
    }
};

// Abstract Decorator
class CharacterDecorator : public ICharacter
{
protected:
    ICharacter *character;

public:
    CharacterDecorator(ICharacter *ch) : character(ch) {}
    virtual ~CharacterDecorator() { delete character; }
    virtual string getAbilities() = 0;
};

// Concrete Decorator: Height
class HeightDecorator : public CharacterDecorator
{
public:
    HeightDecorator(ICharacter *ch) : CharacterDecorator(ch) {}
    string getAbilities() override
    {
        return character->getAbilities() + " with Height";
    }
};

// Concrete Decorator: Gun
class GunDecorator : public CharacterDecorator
{
public:
    GunDecorator(ICharacter *ch) : CharacterDecorator(ch) {}
    string getAbilities() override
    {
        return character->getAbilities() + " with Gun";
    }
};

// Concrete Decorator: Star
class StarDecorator : public CharacterDecorator
{
public:
    StarDecorator(ICharacter *ch) : CharacterDecorator(ch) {}
    string getAbilities() override
    {
        return character->getAbilities() + " with Star (Limited Time)";
    }
};

// Main function
int main()
{
    // Create base Mario character
    ICharacter *mario = new MarioCharacter();
    cout << "Base Character: " << mario->getAbilities() << endl;

    // Add Height decorator
    mario = new HeightDecorator(mario);
    cout << "After Height Power-Up: " << mario->getAbilities() << endl;

    // Add Gun decorator
    mario = new GunDecorator(mario);
    cout << "After Gun Power-Up: " << mario->getAbilities() << endl;

    // Add Star decorator
    mario = new StarDecorator(mario);
    cout << "After Star Power-Up: " << mario->getAbilities() << endl;

    // Clean up
    delete mario;
    return 0;
}