#include <iostream>

int main() {

    int x; //declaration
    x = 5; //assignement

    int y = 6;
    int sum = x + y;

    std::cout << x << '\n';
    std::cout << y << '\n';
    std::cout << sum << '\n';

    //integer (whole number)
    int age = 21;
    int year = 2023;
    int days = 7;

    //double (number including deciaml)
    double price = 10.99;
    double GPA = 2.5;
    double temperature = 25.1;

    std::cout << price << '\n';

    //single character
    char grade = 'A';
    char initial = 'B';
    char currency = '$';

    std::cout << initial << '\n';

    //boolean (true or false)
    bool student = true;
    bool power = false;
    bool forSale = true;

    //string (objects that represents a sequence of text)
    std::string name = "Bro";
    std::string day = "Friday";
    std::string food = "pizza";
    std::string adresse = "123 Fake St.";

    std::cout << name << '\n';


    std::cout << "Hello " << name << '\n';
    std::cout << "You are " << age << " years old";

    return 0;
}