//
// Created by Kamilla IU8-13
//

#include "header.hpp"

int main(int argc, const char *argv[]) {
    if (argc != 3) {
        std::cerr << "Error: Use three parameters\n";
        return 5;
    }
    const std::string mode(argv[1]);
    const std::string file_name(argv[2]);
    unsigned int key;
    std::cout << "Enter key:";
    std::cin >> key;
    if (mode == "encryption") {
        encryption(file_name, key);
    } else if (mode == "decryption") {
        decryption(file_name, key);
    } else {
        std::cout << "wrong mode";
    }
    return 0;
}
