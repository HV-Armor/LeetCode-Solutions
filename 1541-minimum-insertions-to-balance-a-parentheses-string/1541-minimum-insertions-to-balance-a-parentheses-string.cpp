#include <string>

class Solution {
public:
    int minInsertions(std::string s) {
        int res = 0;
        int need = 0;
        
        for (char c : s) {
            if (c == '(') {
                need += 2;
                if (need % 2 != 0) {
                    res++;
                    need--;
                }
            } else {
                need--;
                if (need < 0) {
                    res++;
                    need = 1;
                }
            }
        }
        return res + need;
    }
};
