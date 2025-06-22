class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int a=0; a<n-3; a++) {
            if (a>0 && nums[a] == nums[a-1]) continue;
            for (int b=a+1; b<n-2; b++) {
                if (b>a+1 && nums[b] == nums[b-1]) continue;
                int c = b+1;
                int d = n-1;
                while (c < d) {
                    long long sum = (long long)nums[a] + nums[b] + nums[c] + nums[d];
                    if (sum == target) {
                        vector<int> val = {nums[a], nums[b], nums[c], nums[d]};
                        ret.push_back(val);
                        c++;
                        while(c < d && nums[c] == nums[c-1]) c++;
                        d--;
                        while(c < d && nums[d] == nums[d+1]) d--;
                    }
                    else if (sum < target) {
                        c++;
                        // while(c < d && nums[c] == nums[c-1]) c++;
                    }
                    else {
                        d--;
                        // while(c < d && nums[d] == nums[d+1]) d--;
                    }
                }
            }
        }
        return ret;
    }
};