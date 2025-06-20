class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int maxWater = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            water = (j-i)*(min(height[j], height[i]));
            maxWater = max(water, maxWater);
            if (height[i]<height[j])
                i++;
            else 
                j--;
        }
        return maxWater;
    }
};