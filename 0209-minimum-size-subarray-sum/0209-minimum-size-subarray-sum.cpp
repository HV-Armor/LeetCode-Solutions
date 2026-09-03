class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0,high;
        int sum=0,ans=nums.size()+1;
        for(high=0;high<nums.size();high++){
            sum+=nums[high];
            while(sum>=target){
                int len =high-low+1;
                ans=min(ans,len);
                sum-=nums[low];
                low++;
            }
        }
        if(ans==nums.size()+1){
            return 0;
        }
        else
        return ans;
    }
};