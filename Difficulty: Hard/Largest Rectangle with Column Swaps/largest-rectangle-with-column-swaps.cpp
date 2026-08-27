class Solution {
  public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> height(m, 0);

        int answer = 0;

        for (int i = 0; i < n; i++) {

            vector<int> count(n + 1, 0);

            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    height[j]++;
                } else {
                    height[j] = 0;
                }

                count[height[j]]++;
            }

            int width = 0;

            for (int h = n; h >= 1; h--) {
                width += count[h];

                answer = max(answer, h * width);
            }
        }

        return answer;
    }
};