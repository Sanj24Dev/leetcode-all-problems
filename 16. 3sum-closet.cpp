class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = 0;
        int max_closeness = INT_MAX;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i<n-2; i++) {
            int j = i+1;
            int k = n-1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int closeness = abs(sum-target);
                // cout << i << j << k << " " << closeness << " " << max_closeness << endl;
                if (closeness < max_closeness) {
                    max_closeness = closeness;
                    ret = sum;
                }
                if (sum < target) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        return ret;
    }
};