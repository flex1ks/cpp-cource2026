#include <iostream>

#include <string>

#include "zoo.h"

int main()
{
    Gorilla gorilla;
    Cat cat;
    Parrot parrot;
    Shark shark;
    Crocodile crocodile;

    while (true)
    {
        std::cout << std::endl;
        std::cout << "Choose an animal: ";
        std::cout << std::endl;
        std::cout << "\n=== ZOO ===" << std::endl;
        std::cout << "1. Gorilla" << std::endl;
        std::cout << "2. Cat" << std::endl;
        std::cout << "3. Parrot" << std::endl;
        std::cout << "4. Shark" << std::endl;
        std::cout << "5. Crocodile" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 0)
            break;

        if (choice < 1 or choice > 5)
        {
            std::cout << "Wrong choice" << std::endl;
            continue;
        }

        std::cout << std::endl;
        std::cout << "Choose an action: " << std::endl;
        std::cout << "\n1. MakeSound" << std::endl;
        std::cout << "2. AskForFood" << std::endl;
        std::cout << "3. Move" << std::endl;

        int action;
        std::cin >> action;
        std::cout << std::endl;

        Animal* animal = 0;

        switch (choice)
        {
            case 1: animal = &gorilla;   break;
            case 2: animal = &cat;       break;
            case 3: animal = &parrot;    break;
            case 4: animal = &shark;     break;
            case 5: animal = &crocodile; break;
        }

        switch (action)
        {
            case 1: animal->MakeSound();  break;
            case 2: animal->AskForFood(); break;
            case 3: animal->Move();       break;
            default: std::cout << "Wrong action" << std::endl; break;
        }
    }

    std::cout << "Bye!" << std::endl;
    return 0;
}