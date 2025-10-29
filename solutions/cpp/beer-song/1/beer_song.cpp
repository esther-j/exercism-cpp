#include "beer_song.h"
#include <cstdio>
#include <stdexcept>
#include <string>

namespace beer_song {
    std::string sing(int start, int end) {
        std::string song = "";
        for (int i = start; i >= end; --i) {
            song += verse(i);
            if (i != end) {
                song += '\n';
            }
        }
        return song;
    }

    std::string verse(int num_verses) {
        if (num_verses > 2) {
            return std::to_string(num_verses) + " bottles of beer on the wall, " + std::to_string(num_verses) + " bottles of beer.\nTake one down and pass it around, " + std::to_string(num_verses - 1) + " bottles of beer on the wall.\n";
        } else if (num_verses == 2) {
            return "2 bottles of beer on the wall, 2 bottles of beer.\n"
                "Take one down and pass it around, 1 bottle of beer on the wall.\n";
        } else if (num_verses == 1) {
            return "1 bottle of beer on the wall, 1 bottle of beer.\n"
                "Take it down and pass it around, no more bottles of beer on the wall.\n";
        } else if (num_verses == 0) {
            return "No more bottles of beer on the wall, no more bottles of beer.\n"
                "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
        }
        throw std::runtime_error("invalid num_verses");
    }
}  // namespace beer_song
