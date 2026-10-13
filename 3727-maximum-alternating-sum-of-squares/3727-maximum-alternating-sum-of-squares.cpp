#include <vector>
#include <algorithm>

class Solution {
public:
    long long maxAlternatingSum(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<long long> squares(n);
        
        for (int i = 0; i < n; i++) {
            squares[i] = (long long)nums[i] * nums[i];
        }
        
        std::sort(squares.begin(), squares.end());
        
        long long max_score = 0;
        int neg_count = n / 2;
        
        for (int i = 0; i < neg_count; i++) {
            max_score -= squares[i];
        }
        for (int i = neg_count; i < n; i++) {
            max_score += squares[i];
        }
        
        return max_score;
    }
};
