#include <iostream>
#include <string>
#include <vector>


int main(){
    int a = 0;
    std::vector <std::string>months {
        "p", "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"
    };
    std::cin >> a;
    std::cout<< months[a] + " ";
    std::cout<< a;
    return 0;
}