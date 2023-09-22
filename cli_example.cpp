#include <iostream>
#include <string>

int main() {
    // Use the __FILE__ macro to get the path of the source file
    std::string filePath(__FILE__);

    // Output the path to the terminal
    std::cout << "Path to this source file: " << filePath << std::endl;

    return 0;
}
