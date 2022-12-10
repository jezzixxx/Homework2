//
// Created by Kamilla IU8-13
//

#include "header.hpp"

void encryption(const std::string &file_name, unsigned int key) {
    std::string str;
    std::cout << "Enter str:";
    std::cin >> str;
    unsigned char b1, b2, b3, b4, r1, r2, r3, r4;
    unsigned int block, xored_block, shifted_block, gamma;
    srand(key);
    std::ofstream out;
    out.open(file_name, std::ios::binary);
    for (size_t i = 0; i < str.size(); i += 4) {
        gamma = rand();
        b1 = str[i];
        b2 = i + 1 < str.size() ? str[i + 1] : 0u;
        b3 = i + 2 < str.size() ? str[i + 2] : 0u;
        b4 = i + 3 < str.size() ? str[i + 3] : 0u;
        block = ((static_cast<unsigned int>(b1) << 24u) | static_cast<unsigned int>(b2) << 16u |
                 static_cast<unsigned int>(b3) << 8u | static_cast<unsigned int>(b4));
        xored_block = block ^ gamma;
        shifted_block = (xored_block << 4u) | (xored_block >> 28u);
        r1 = shifted_block >> 24u;
        r2 = shifted_block >> 16u;
        r3 = shifted_block >> 8u;
        r4 = shifted_block;
        out << r1 << r2 << r3 << r4;
    }
}
