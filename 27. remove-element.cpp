class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (nums[i] == val)
                continue;
            else {
                nums[cnt++] = nums[i];
            }
        }
        return cnt;
    }
};