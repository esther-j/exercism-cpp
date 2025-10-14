#include "largest_series_product.h"
#include <string>
#include <stdexcept>
#include <cctype>

namespace largest_series_product {

    int largest_product(std::string input, int span) {
        if ((int)input.length() < span) {
            throw std::domain_error("span longer than input");
        }
        if (span < 0) {
            throw std::domain_error("negative span");
        }
        int largest = 0;
        for (size_t i = 0; i < input.length() - span + 1; ++i) {
            int current = get_product(input.substr(i, span));
            if (current > largest) {
                largest = current;
            }
        }
        return largest;
    }

    int get_product(std::string number_str) {
        int total_product = 1;
        for (const char c : number_str) {
            if (!std::isdigit(c)) {
                throw std::domain_error("invalid character");
            }
            total_product *= c - '0';
        }
        return total_product;
    }

}  // namespace largest_series_product
