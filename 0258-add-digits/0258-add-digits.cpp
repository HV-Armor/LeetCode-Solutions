class Solution {
public:
    int addDigits(int num) {
        while(num>9)
        {
        int ans=-0,rem=0;
        while(num>0)
        {
            rem=num%10;
            ans+=rem;
            num/=10;
        }
        num=ans;
        }
        return num;
    }
};