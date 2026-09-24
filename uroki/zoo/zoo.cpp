#include <iostream>

#include "zoo.h"

Animal::Animal() = default;
Animal::~Animal() = default;
Animal::Animal(const Animal& other) = default;
Animal::Animal(Animal&& other) = default;
Animal& Animal::operator=(const Animal& other) = default;
Animal& Animal::operator=(Animal&& other) = default;

void Animal::MakeSound()
{
    std::cout << "Silence" << std :: endl;
}

void Animal :: AskForFood()
{
std :: cout << "I want to eat" << std :: endl;
}

void Animal :: Move()
{
std :: cout << "I move like an animal" << std :: endl;
}

Gorilla::~Gorilla() = default;
Gorilla::Gorilla(const Gorilla& other) = default;
Gorilla::Gorilla(Gorilla&& other) = default;
Gorilla& Gorilla::operator=(const Gorilla& other) = default;
Gorilla& Gorilla::operator=(Gorilla&& other) = default;

void Gorilla::MakeSound()
{
    std::cout << "Hoo hoo hoo" << std :: endl;
}

void Gorilla::AskForFood()
{
std :: cout << "I want banana" << std :: endl;
}

void Gorilla::Move()
{
std :: cout << "I move like a boss" << std :: endl;
}

Cat::~Cat() = default;
Cat::Cat(const Cat& other) = default;
Cat::Cat(Cat&& other) = default;
Cat& Cat::operator=(const Cat& other) = default;
Cat& Cat::operator=(Cat&& other) = default;

void Cat::MakeSound()
{
    std::cout << "Meow" << std :: endl;
}

void Cat::AskForFood()
{
std :: cout << "Fish, please" << std :: endl;
}

void Cat::Move()
{
std :: cout << "I love to lie" << std :: endl;
}

Parrot::~Parrot() = default;
Parrot::Parrot(const Parrot& other) = default;
Parrot::Parrot(Parrot&& other) = default;
Parrot& Parrot::operator=(const Parrot& other) = default;
Parrot& Parrot::operator=(Parrot&& other) = default;

void Parrot::MakeSound()
{
    std::cout << "Squawk!" << std :: endl;
}

void Parrot::AskForFood()
{
std :: cout << "I want a cracker" << std :: endl;
}

void Parrot::Move()
{
std :: cout << "I can fly" << std :: endl;
}

Shark::~Shark() = default;
Shark::Shark(const Shark& other) = default;
Shark::Shark(Shark&& other) = default;
Shark& Shark::operator=(const Shark& other) = default;
Shark& Shark::operator=(Shark&& other) = default;

void Shark::MakeSound()
{
    std::cout << "Chomp" << std :: endl;
}

void Shark::AskForFood()
{
std :: cout << "I want a blood" << std :: endl;
}

void Shark::Move()
{
std :: cout << "I am swimming" << std :: endl;
}

Crocodile::~Crocodile() = default;
Crocodile::Crocodile(const Crocodile& other) = default;
Crocodile::Crocodile(Crocodile&& other) = default;
Crocodile& Crocodile::operator=(const Crocodile& other) = default;
Crocodile& Crocodile::operator=(Crocodile&& other) = default;

void Crocodile::MakeSound()
{
    std::cout << "Roar" << std :: endl;
}

void Crocodile::AskForFood()
{
std :: cout << "I want a meat" << std :: endl;
}

void Crocodile::Move()
{
std :: cout << "I swim as well as run" << std :: endl;
}

