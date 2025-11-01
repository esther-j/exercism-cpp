#include "run_length_encoding.h"
#include <string>
#include <iostream>
#include <cctype>

namespace run_length_encoding {

std::string encode(std::string input) {
    if (input.size() == 0) {
        return input;
    }
    std::string output = "";
    int freq = 0;
    char cur_c = input[0];
    for (const char c : input) {
        if (c != cur_c) {
            output += (freq == 1 ? "" : std::to_string(freq)) + cur_c;
            freq = 0;
            cur_c = c;
        }
        freq++;
    }
    output += (freq == 1 ? "" : std::to_string(freq)) + cur_c;
    return output;
}

std::string decode(std::string input) {
    if (input.size() == 0) {
        return input;
    }
    std::string output = "";
    int freq = 0;
    for (char c : input) {
        if (std::isdigit(c)) {
            freq = freq * 10 + (c - '0');
        } else {
            if (freq == 0) {
                freq = 1;
            }
            for (int i = 0; i < freq; ++i) {
                output += c;
            }
            freq = 0;
        }
    }
    return output;
}


}  // namespace run_length_encoding
