class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        vector<int> R(m, -1);
        int j = m - 1;
        for (int i = n - 1; i >= 0 && j >= 0; --i) {
            if (word1[i] == word2[j]) {
                R[j] = i;
                j--;
            }
        }
        
        vector<int> ans;
        bool changed = false;
        j = 0;
        
        for (int i = 0; i < n && j < m; ++i) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else if (!changed) {
                if (j + 1 == m || R[j + 1] > i) {
                    changed = true;
                    ans.push_back(i);
                    j++;
                }
            }
        }
        
        if (j == m) {
            return ans;
        }
        
        return {};
    }
};