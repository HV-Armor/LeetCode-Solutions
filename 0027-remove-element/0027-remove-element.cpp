class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    vector<int> result;
    for (int num : nums) {
        if (num != val) {
            result.push_back(num);
        }
    }
    nums = result;
    return nums.size();
}
};