class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int n = nums.size();
        for (int i=0; i<n-2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (j < k && nums[j - 1] == nums[j]) j++;
                    k--; 
                    while (j < k && nums[k + 1] == nums[k]) k--;
                }
                else if (sum < 0) {
                    j++;
                    while (j < k && nums[j - 1] == nums[j]) j++;
                }
                else {
                    k--;
                    while (j < k && nums[k + 1] == nums[k]) k--;
                }
            }
        }
        return ret;
    }
};