class Solution {
public:
    int reverse(int x) {
        int rev;
        int ans=0;
        while(x!=0)
        {
            rev=x%10;
            x=x/10;
            if(ans>INT_MAX/10 || ans<INT_MIN/10)
            return 0;
            ans = ans*10+rev;
        }
        return ans;
    }
};
