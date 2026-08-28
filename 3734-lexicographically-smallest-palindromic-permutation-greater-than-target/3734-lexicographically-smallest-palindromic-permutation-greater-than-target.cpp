#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26);
        for (char c : s) cnt[c - 'a']++;
        
        // Check if a palindromic permutation exists
        int odd = 0, mid = -1;
        for (int i = 0; i < 26; ++i)
            if (cnt[i] & 1) { odd++; mid = i; }
        if (odd > 1) return "";
        
        // Half of the pairs
        vector<int> half(26);
        for (int i = 0; i < 26; ++i) half[i] = cnt[i] / 2;
        int m = n / 2;
        string A = target.substr(0, m);
        
        // Can we form the first half exactly as A?
        vector<int> need(26);
        for (char c : A) need[c - 'a']++;
        bool canFormA = true;
        for (int i = 0; i < 26; ++i)
            if (need[i] > half[i]) { canFormA = false; break; }
        
        bool possibleWithA = false;
        if (canFormA) {
            string revA = A;
            reverse(revA.begin(), revA.end());
            if (n % 2 == 0) {
                string B = target.substr(m);
                if (revA > B) possibleWithA = true;
            } else {
                int midT = target[m] - 'a';
                // Try a larger middle character
                int choose = -1;
                for (int c = midT + 1; c < 26; ++c)
                    if (cnt[c] & 1) { choose = c; break; }
                if (choose != -1) possibleWithA = true;
                else if (mid == midT) {
                    string B = target.substr(m + 1);
                    if (revA > B) possibleWithA = true;
                }
            }
        }
        if (possibleWithA) return build(A, mid, n);
        
        // Find the smallest first‑half > A using the multiset `half`
        string X = nextGreater(half, A);
        if (!X.empty()) return build(X, mid, n);
        
        return "";
    }
    
private:
    string build(const string& half, int mid, int n) {
        string rev = half;
        reverse(rev.begin(), rev.end());
        if (n % 2 == 0) return half + rev;
        return half + char('a' + mid) + rev;
    }
    
    // Returns the smallest permutation of `half` that is lexicographically > A,
    // or empty string if none exists.
    string nextGreater(const vector<int>& half, const string& A) {
        int m = A.size();
        for (int p = m - 1; p >= 0; --p) {
            vector<int> rem = half;
            bool ok = true;
            // Remove prefix A[0..p-1]
            for (int i = 0; i < p; ++i) {
                if (--rem[A[i] - 'a'] < 0) { ok = false; break; }
            }
            if (!ok) continue;
            
            int xp = A[p] - 'a';
            int choose = -1;
            for (int c = xp + 1; c < 26; ++c)
                if (rem[c] > 0) { choose = c; break; }
            if (choose == -1) continue;
            
            rem[choose]--;
            string ans = A.substr(0, p) + char('a' + choose);
            for (int c = 0; c < 26; ++c)
                ans += string(rem[c], char('a' + c));
            return ans;
        }
        return "";
    }
};