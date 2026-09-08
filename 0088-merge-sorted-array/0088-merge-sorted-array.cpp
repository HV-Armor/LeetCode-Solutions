class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int low=m,high=0;
        while(low<nums1.size()){
            if(nums1[low]==0){
                nums1[low]=nums2[high];
                low++;
                high++;
            }
            else{
                low++;
            }
        }
        sort(nums1.begin(),nums1.end());
            for(int i=0;i<nums1.size();i++){
                cout<<nums1[i];
            }
    }
};