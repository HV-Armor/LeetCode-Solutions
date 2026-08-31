class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        while(n--){
        s=s.substr(1)+s.substr(0,1);
        if(s==goal) return true;
        }
         return false;
    }
};