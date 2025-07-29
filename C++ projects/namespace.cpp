#include <iostream>

namespace first{
    int x = 1;
}

namespace second{
    int x = 2;
}

int main() {


    // Namespace = provides a solution for prreventing name conflicts
    //             in large projects. Each entity needs a unique name.
    //             A namespace allows for identifically named entities
    //             as long as the namespaces are different

    using namespace first;
    
    // std::cout << x << '\n';
    std::cout << x << '\n';
    std::cout << second::x << '\n';
    return 0;

    using std::cout;
    using std::string;

    string name = "Bro";
    cout << "Hello " << name;

}