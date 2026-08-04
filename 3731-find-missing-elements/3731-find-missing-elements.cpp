class Solution { 
public: 
    vector<int> findMissingElements(vector<int>& nums) {
     
        sort(nums.begin(), nums.end());
        
        vector<int> result; 
        
               for (int i = 0; i < nums.size() - 1; i++) {
         
            int current = nums[i];
            int next = nums[i + 1];
            
         
            for (int missing = current + 1; missing < next; missing++) {
                result.push_back(missing);
            }
        }
        
        return result;
    } 
};
