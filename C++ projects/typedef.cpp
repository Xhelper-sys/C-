#include <iostream>
#include <vector>

//typedef std::vector<std::pair<std::string, int>> pairlist_t;
//typedef std::string str_t;
//typedef int number_t;

using pairlist_t = std::vector<std::pair<std::string, int>>;
using str_t = std::string;
using number_t = int;

int main() {

    // typedef = reserved keyword used to create an name additional name
    //           (alias) for antother data type.
    //           New identifier for an existing type 
    //           Helps with readability

    pairlist_t pairlist;
    str_t firstName = "Bro";
    number_t age = 21;

    std::cout << firstName << '\n';
    std::cout << age << '\n';

    return 0;
}