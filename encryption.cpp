//
// Created by Kamilla IU8-13
//

#include "header.hpp"

void decryption(const std::string &file_name, unsigned int key) {
    unsigned char b1, b2, b3, b4;
    unsigned int block, xored_block, shifted_block, gamma;
    srand(key);
    std::ifstream in;
    in.open(file_name, std::ios::binary);
    std::vector<char> result;
    std::string outdata;
    getline(in, outdata);
    in.close();
    for (size_t i = 0; i < outdata.size(); i += 4) {
        gamma = rand();
        b1 = outdata[i];
        b2 = i + 1 < outdata.size() ? outdata[i + 1] : 0u;
        b3 = i + 2 < outdata.size() ? outdata[i + 2] : 0u;
        b4 = i + 3 < outdata.size() ? outdata[i + 3] : 0u;
        block = ((static_cast<unsigned int>(b1) << 24u) | static_cast<unsigned int>(b2) << 16u |
                 static_cast<unsigned int>(b3) << 8u | static_cast<unsigned int>(b4));
        shifted_block = (block >> 4u) | (block << 28u);
        xored_block = shifted_block ^ gamma;
        result.push_back(xored_block >> 24u);
        result.push_back(xored_block >> 16u);
        result.push_back(xored_block >> 8u);
        result.push_back(xored_block);
    }
    for (char symbol: result) std::cout << symbol;
}
