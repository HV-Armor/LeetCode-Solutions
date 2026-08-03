class Solution {
public:
    int maxProduct(int n) {
        int max1 = 0;
        int max2 = 0;
        
        while (n > 0) {
            int rem = n % 10;
            
            if (rem > max1) {
                max2 = max1; // Old maximum becomes second largest
                max1 = rem;  // Update maximum
            } else if (rem > max2) {
                max2 = rem;  // Update second largest
            }
            
            n = n / 10;
        }
        
        return max1 * max2;
    }
};
