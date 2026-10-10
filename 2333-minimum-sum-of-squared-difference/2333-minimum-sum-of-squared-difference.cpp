#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();
        
        for (int i = 0; i < n; ++i) {
            nums1[i] = std::abs(nums1[i] - nums2[i]);
        }
        
        std::sort(nums1.begin(), nums1.end());
        
        long long current_val = 0;
        long long decrease = 0;
        long long remainder = 0;
        int break_idx = -1;
        
        for (int i = n - 1; i >= 0; --i) {
            long long count = n - i;
            current_val = nums1[i];
            long long next = (i > 0) ? nums1[i - 1] : 0;
            long long diff = current_val - next;
            
            if (k >= diff * count) {
                k -= diff * count;
            } else {
                decrease = k / count;
                remainder = k % count;
                break_idx = i;
                k = 0;
                break;
            }
        }
        
        long long ans = 0;
        if (break_idx == -1) {
            return 0;
        }
        
        for (int i = 0; i < break_idx; ++i) {
            ans += (long long)nums1[i] * nums1[i];
        }
        
        long long final_val = current_val - decrease;
        long long elements_affected = n - break_idx;
        long long normal_elements = elements_affected - remainder;
        
        ans += normal_elements * (final_val * final_val);
        ans += remainder * ((final_val - 1) * (final_val - 1));
        
        return ans;
    }
};
