#include "high_scores.h"

#include <algorithm>

namespace arcade {

std::vector<int> HighScores::list_scores() {
    return scores;
}

int HighScores::latest_score() {
    return *(scores.end() - 1);
}

int HighScores::personal_best() {
    std::vector sorted_scores = scores;
    std::sort(sorted_scores.begin(), sorted_scores.end());
    return *(sorted_scores.end() - 1);
}

std::vector<int> HighScores::top_three() {
    std::vector sorted_scores = scores;
    std::sort(sorted_scores.begin(), sorted_scores.end());
    std::vector results = std::vector(sorted_scores.rbegin(), std::min(sorted_scores.rbegin() + 3, sorted_scores.rend()));
    return results;
}

}  // namespace arcade
