class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxSoFar = values[0];  // Represents `values[i] + i` for the best `i` seen so far
        int maxScore = 0;

        for (int j = 1; j < values.size(); ++j) {
            maxScore = max(maxScore, maxSoFar + values[j] - j);  // Compute score for (i, j)
            maxSoFar = max(maxSoFar, values[j] + j);  // Update `maxSoFar` for future pairs
        }

        return maxScore;
    }
};
