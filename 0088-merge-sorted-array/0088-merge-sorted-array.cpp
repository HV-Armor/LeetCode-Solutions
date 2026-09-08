class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int low=m,high=0;
        while(low<nums1.size()){
            nums1[low]=nums2[high];
            low++;
            high++;
        }
        sort(nums1.begin(),nums1.end());
        // for(int i=0;i<nums1.size();i++){
        //     cout<<nums1[i];
        // }
    }
};