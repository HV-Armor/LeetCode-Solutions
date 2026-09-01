class Solution {
public:
    int maximumGap(vector<int>& s) {
        int low = 0;
        int high = 1;

        sort(s.begin(), s.end());

        int n = s.size();

        if (n < 2)
            return 0;

        int diff = s[high] - s[low];
        int res = 0;

        while (high < n) {
            res = max(res, diff);

            low++;
            high++;

            if (high == n)
                break;

            diff = s[high] - s[low];
        }

        return res;
    }
};