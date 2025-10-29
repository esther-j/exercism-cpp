#include "diamond.h"
#include <string>
#include <algorithm>
#include <vector>

namespace diamond {

std::vector<std::string> get_rows(char c) {
    std::vector<std::string> ret;
    int cur_c = 'A';
    size_t num_rows = static_cast<size_t>(static_cast<int>(c) - cur_c);
    std::string spaces(num_rows, ' ');
ret.push_back(spaces + static_cast<char>(cur_c++) + spaces);
    for (size_t i = 1; i < num_rows; i++) {
        std::string side_spaces(num_rows - i, ' ');
        std::string mid_spaces(2 * i - 1, ' ');
        ret.push_back(side_spaces + static_cast<char>(cur_c) + mid_spaces + static_cast<char>(cur_c) + side_spaces);
        cur_c++;
    }
    return ret;
}
    
std::vector<std::string> rows(char c) {
    int cur_c = 'A';
    size_t num_rows = static_cast<size_t>(static_cast<int>(c) - cur_c);
    if (num_rows == 0) {
        return {"A"};
    }
    std::vector<std::string> half_diamond = get_rows(c);
    std::vector<std::string> ret;
    ret.insert(ret.end(), half_diamond.begin(), half_diamond.end());
    std::string mid_spaces(num_rows * 2 - 1, ' ');
    ret.push_back(c + mid_spaces + c);
    std::reverse(half_diamond.begin(), half_diamond.end());
    ret.insert(ret.end(), half_diamond.begin(), half_diamond.end());
    return ret;
}

}  // namespace diamond
