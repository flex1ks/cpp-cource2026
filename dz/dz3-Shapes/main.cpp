#include <iostream>
#include <string>
#include "shapes.h"



void printShapeMenu()
{
    std::cout << "1. Triangle\n";
    std::cout << "2. Circle\n";
    std::cout << "3. Rectangular\n";
    std::cout << "4. Square\n";
}



int main()
{
    std::cout << "====Create your shapes====\n";

    double a, b, c;
    std::cout << "\nEnter Triangle sides: \n";
    std::cin >> a >> b >> c;
    std::cout << "__________________________\n";
    
    try {
        Triangle triangle(a, b, c);
        
        double r;
        std::cout << "\nEnter Circle radius: \n";
        std::cin >> r;
        std::cout << "__________________________\n";
        Circle circle(r);

        double l, w;
        std::cout << "\nEnter Rectangular sides: \n";
        std::cin >> l >> w;
        std::cout << "__________________________\n";
        Rectangular rectangular(l, w);
        if (l == w) {
            std::cout << "We got a square!\n";
            std::cout << "__________________________\n";
        }

        double s;
        std::cout << "\nEnter Square side: \n";
        std::cin >> s;
        std::cout << "__________________________\n";
        Square square(s);

       

        while (true)
        {
            std::cout << "\nChoose an action: \n";
            std::cout << "1. Find out the Area\n";
            std::cout << "2. Find out the Perimeter\n";
            std::cout << "3. Compare Areas\n";
            std::cout << "4. Compare Perimeters\n";
            std::cout << "0. Exit\n";
            std::cout << "> ";

            int action;
            std::cin >> action;

            if (action == 0) break;


            if (action < 1 or action > 4) {
                std::cout << "Wrong action\n";
                continue;
            }


            if (action == 1 or action == 2)
            {
                std::cout << "\nChoose the figure you want to learn about:\n";
                printShapeMenu();
                std::cout << "> ";
                
                int figChoice;
                std::cin >> figChoice;
                
                Shape* shape = nullptr;
                switch (figChoice) {
                    case 1: shape = &triangle; break;
                    case 2: shape = &circle; break;
                    case 3: shape = &rectangular; break;
                    case 4: shape = &square; break;
                    default:
                        std::cout << "Wrong figure\n";
                        continue;
                }

                if (action == 1)
                    std::cout << "Area = " << shape->Area() << "\n";
                else
                    std::cout << "Perimeter = " << shape->Perimeter() << "\n";
            }
            


            else if (action == 3 || action == 4)
            {
                std::cout << "\nChoose the FIRST figure:\n";
                printShapeMenu();
                std::cout << "> ";
                int fig1;
                std::cin >> fig1;

                std::cout << "Choose the SECOND figure:\n";
                printShapeMenu();
                std::cout << "> ";
                int fig2;
                std::cin >> fig2;

                Shape* sh1 = nullptr;
                Shape* sh2 = nullptr;

                switch (fig1) {
                    case 1: sh1 = &triangle; break;
                    case 2: sh1 = &circle; break;
                    case 3: sh1 = &rectangular; break;
                    case 4: sh1 = &square; break;
                }
                switch (fig2) {
                    case 1: sh2 = &triangle; break;
                    case 2: sh2 = &circle; break;
                    case 3: sh2 = &rectangular; break;
                    case 4: sh2 = &square; break;
                }

                if (sh1 && sh2) 
                {
                    if (action == 3)
                    {
                        double area1 = sh1->Area();
                        double area2 = sh2->Area();
                        
                        std::cout << "Area of first = " << area1 << "\n";
                        std::cout << "Area of second = " << area2 << "\n";

                        if (*sh1 == *sh2) {
                            std::cout << "The areas are equal.\n";
                        } 
                        else if (area1 > area2) {
                            std::cout << "The area of the FIRST figure is larger.\n";
                        } 
                        else {
                            std::cout << "The area of the SECOND figure is larger.\n";
                        }
                    } 
                    else
                    {
                        double perim1 = sh1->Perimeter();
                        double perim2 = sh2->Perimeter();
                        
                        std::cout << "Perimeter of first = " << perim1 << "\n";
                        std::cout << "Perimeter of second = " << perim2 << "\n";

                        if (*sh1 ^ *sh2) {
                            std::cout << "The perimeters are equal.\n";
                        } 
                        else if (perim1 > perim2) {
                            std::cout << "The perimeter of the FIRST figure is larger.\n";
                        } 
                        else {
                            std::cout << "The perimeter of the SECOND figure is larger.\n";
                        }
                    }
                } 
                else 
                {
                    std::cout << "Wrong figure\n";
                }
            }
        }
    }
    catch (const ShapeException& e) {
        std::cout << "\nError: " << e.what() << "\n";
    }

    std::cout << "Goodbye!\n";
    return 0;
}