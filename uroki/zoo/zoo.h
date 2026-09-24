#pragma once

#include <string>

class Animal
{
public:
    Animal();
    ~Animal();
    Animal(const Animal& other);
    Animal(Animal&& other);
    Animal& operator=(const Animal& other);
    Animal& operator=(Animal&& other);
    
    virtual void MakeSound();
    virtual void AskForFood();
    virtual void Move();

};

class Gorilla : public Animal
{
public:
    Gorilla() : Animal() {};
    ~Gorilla();
    Gorilla(const Gorilla& gorilla);
    Gorilla(Gorilla&& gorilla);
    Gorilla& operator=(const Gorilla& gorilla);
    Gorilla& operator=(Gorilla&& gorilla);

    virtual void MakeSound() override;
    virtual void AskForFood() override;
    virtual void Move() override;
};

class Cat : public Animal
{
public:
    Cat() : Animal() {};
    ~Cat();
    Cat(const Cat& cat);
    Cat(Cat&& cat);
    Cat& operator=(const Cat& cat);
    Cat& operator=(Cat&& cat);

    virtual void MakeSound() override;
    virtual void AskForFood() override;
    virtual void Move() override;
};

class Parrot : public Animal
{
public:
    Parrot() : Animal() {};
    ~Parrot();
    Parrot(const Parrot& parrot);
    Parrot(Parrot&& parrot);
    Parrot& operator=(const Parrot& parrot);
    Parrot& operator=(Parrot&& parrot);

    virtual void MakeSound() override;
    virtual void AskForFood() override;
    virtual void Move() override;
};

class Shark : public Animal
{
public:
    Shark() : Animal() {};
    ~Shark();
    Shark(const Shark& shark);
    Shark(Shark&& shark);
    Shark& operator=(const Shark& shark);
    Shark& operator=(Shark&& shark);

    virtual void MakeSound() override;
    virtual void AskForFood() override;
    virtual void Move() override;
};

class Crocodile : public Animal 
{
public:
    Crocodile() : Animal() {};
    ~Crocodile();
    Crocodile(const Crocodile& crocodile);
    Crocodile(Crocodile&& crocodile);
    Crocodile& operator=(const Crocodile& crocodile);
    Crocodile& operator=(Crocodile&& crocodile);

    virtual void MakeSound() override;
    virtual void AskForFood() override;
    virtual void Move() override;
};