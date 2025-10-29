#include "eliuds_eggs.h"
#include <ostream>
#include <iostream>

namespace chicken_coop {

int get_num_places(int n) {
    int num_places = 0;
    while (n > 0) {
        n /= 2;
        num_places++;
    }
    return num_places;   
}
    
int positions_to_quantity(int n) {
    int shift = get_num_places(n) - 1;
    int num_eggs = 0;
    while (n > 0) {
        int new_n = n - (1 << shift--);
        if (new_n >= 0) {
            num_eggs += 1;
            n = new_n;
        }
    }
    return num_eggs;
}
    
}  // namespace chicken_coop
