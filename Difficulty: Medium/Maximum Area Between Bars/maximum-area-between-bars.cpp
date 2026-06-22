class Solution {
  public:
    int maxArea(vector<int> &heights) {
        int n = size(heights);
        int l = 0, h = n - 1;
        
        int max = std::numeric_limits<int>::min();
        while (l <= h) {
            int height = min(heights[l], heights[h]);
            int width = h - l - 1;
            int area = height * width;
            
            max = fmax(max, area);
            
            if (heights[l] < heights[h])
                l++;
            else
                h--;
        }
        return max;
    }
};