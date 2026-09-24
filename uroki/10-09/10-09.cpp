#include <iostream>
#include <cmath>


int main()
{
    //Целочисленные типы
    char a = 'g';
    std::cout << "Type char: " << sizeof(char) << std::endl;
    unsigned char b = 'r';

    int c = 4; 
    std::cout << "Type int: " << sizeof(int) << std::endl;
    
    short int d = 2;
    std::cout << "Type short int: " << sizeof(short int) << std::endl;
    short e = 3;

    long int f = 5;
    std::cout << "Type long int: " << sizeof(long int) << std::endl;

    long long int g = 6;
    std::cout <<  "Type long long int: " << sizeof(long long int) << std::endl;

    // суффиксы целочисленных типов
    long long int h = 6LL;
    unsigned int i = 1U;
    unsigned long long int j = 1ULL;
    
    // Числа с плавающей точкой
    float number_float = 1.2f;
    std::cout <<  "Type float: " << sizeof(float) << std::endl;

    double number_double = 3.14;
    std::cout <<  "Type double: " << sizeof(double) << std::endl;

    // 1 бит - знак
    // x бит - мантисса         float x = 24 бит || double x = 11 бит
    // y бит - экспонента       float y = 7 бита || double y = 52 битa

    std::cout << std::pow(2, -24) << std::endl;
    std::cout << std::pow(2, -52) << std::endl;

    long double number_long_double = 5.0;
    std::cout << "Type long double: " << sizeof(long double) << std::endl;
    //Точность long double
    std::cout << std::pow(2.0L, -116) << std::endl;

    // Логичесикй тип
    bool bool_arg = true;
    bool bool_arg1 = false;
    std::cout << "Type bool: " << sizeof(bool) << std::endl;

    //void void_arg; - ЗАПРЕЩЕНО СОЗДАВАТЬ  

    double number = 1;
    int number_int = 3.14;
    std::cout << "Number int from 3.14: " << number_int << std::endl;

    // Явное преобразование
    double number_from_int = (double)1;
    double number_from_int1 = double(1);
    double number_from_int2 = static_cast<double>(1);
    // dynamic_cast<type>(value) || reinterpret_cast<type>(value)

    double number1 = 1 / 2;
    std::cout << "Number 0.5 from int: " << number1 << std::endl;
    number1 = 1 / (double)2;
    std::cout << "Number 0.5: " << number1 << std::endl;

    //Операторы 
    // Ввод/Вывод
    // std::cin >> number;
    std::cout << "out" << std::endl;
    std::cout << "out" << '\n';

    std::cerr << "error message" << std::endl;
    
    // Арифметические операторы 
    int number2 = 2 + 6;
    number2 = 6 - 2;
    number2 = (-6 + 3) / 1 * 15;
    int number3 = 15 % 7;
    /* Многострочный комментарий
    ывпа
    ыап
    ваперыкер
    конец*/

    int number4 = 5; 
    std::cout << "number4: " << number4 << std::endl;
    int cpp = ++number4;    
    std::cout << "++number4: " << cpp << std::endl;
    std::cout << "number4: " << number4 << std::endl;
    int cpp_ = number4++;
    std::cout << "number4++: " << cpp_ << std::endl;
    std::cout << "number4: " << number4 << std::endl;

    // Логические операторы
    std::cout << "Equal: " << (number4 == cpp) << std::endl;
    std::cout << "Not equal: " << (number4 != cpp) << std::endl;
    std::cout << "Greater: " << (number4 > cpp) << std::endl;
    std::cout << "Lower: " << (number4 < cpp) << std::endl;
    std::cout << "Lower or Equal: " << (number4 <= cpp) << std::endl;
    std::cout << "Greater or Equal: " << (number4 >= cpp) << std::endl;

    bool condition = (4 < 5) && (0 == 0);
    bool condition1 = (4 > 5) || (0 == 0);
    bool condition2 = !condition;


    int x = 0;
    int y = 9;
    // int result = y / x; // NaN
    // std::cout << "result 9/0: " << result << std::endl;
    bool expr1 = (std::numeric_limits<int>::quiet_NaN() == std::numeric_limits<int>::quiet_NaN());
    bool expr2 = x == x;
    std::cout << "NaN == NaN: " << expr1 << std::endl;
    bool condition3 = (x == 0) || (y / x);
    std::cout << "(x == 0) || (y / x): " << condition3 << std::endl;

    int parameter;
    parameter = 5;
    int  parameter1 = 5;
    parameter1 += 5;
    
    double double_max = std::numeric_limits<double>::max();
    std::cout << "double_max: " << double_max << std::endl;
    double_max += 100.0;
    std::cout << "double_max + 10.0: " << double_max << std::endl;
    std::cout << "double_inf: " << std::numeric_limits<double>::infinity() << std::endl;
    


    return 0;

}