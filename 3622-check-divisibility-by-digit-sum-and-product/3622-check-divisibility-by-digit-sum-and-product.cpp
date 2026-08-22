class Solution {
public:
    bool checkDivisibility(int n) {
        int res , sum=0 , pro=1;
        int n1=n;
        while(n>0){
            res= n%10;
            sum+=res;
            pro*=res;
            n=n/10;
        }
        int sum1=sum+pro;
        if(n1%sum1==0)
        return true;
        else
        return false;
    }
};