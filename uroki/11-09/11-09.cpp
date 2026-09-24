/* №1
#include <iostream>
#include <string>

int main(){
    unsigned long long int fact = 1;
    int n = 0;
    std::cin>>n;
    if (n>=0){
        for (int i = 1; i <= n; i++) fact *= i;
        std::cout <<fact<<std::endl;

    }
    else{
        std::cout << "Error, n < 0" <<std::endl;
    }
    return 0;
} 
*/


/* №2
#include <iostream>

int fibonachi(int n){
    if(n<0){return n;}
    if(n==0){return 0;}
    else if (n == 1){return 1;}
    else {return fibonachi(n-1)+fibonachi(n-2);}
}


int main(){
    int a = 0;
    std::cin >> a;
    if(a < 0){std::cout << "ERROR, a < 0"; return 1;}
    int b = fibonachi(a);

    std::cout << b;
    return 0;

}

*/


#include <iostream>
#include <string>
#include <vector>


int main(){
    int a = 0;
    std::vector <std::string>months {
        "p", "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"
    };
    std::cin >> a;
    std::cout<< months[a];
    return 0;
}

