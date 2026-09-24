#include <iostream>
#include <random>


int main(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int>dist(1, 100);

    int a = dist(gen);
    int b = 0;
    while(b != a) {
        std::cin >> b;
        if(b > a){std::cout << "Lower\n";}
        else if(b < a){std::cout << "Greater\n";}
        else if(a == b){std::cout << "Correct!\n"; return 0;}
    }

}