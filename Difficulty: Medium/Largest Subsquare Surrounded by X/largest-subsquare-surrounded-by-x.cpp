class Solution {
  public:
    int largestSubsquare(vector<vector<char>> &mat) {
        if (mat.empty() || mat[0].empty()) return 0;

        int n = mat.size();
        int m = mat[0].size();

        // row[r][c]: consecutive 'X's ending at (r, c) horizontally (to the left)
        // col[r][c]: consecutive 'X's ending at (r, c) vertically (upwards)
        vector<std::vector<int>> row(n, std::vector<int>(m, 0));
        vector<std::vector<int>> col(n, std::vector<int>(m, 0));

        // Precompute consecutive counts for rows and columns
        for (int r = 0; r < n; ++r) {
            int rowCount = 0;
            for (int c = 0; c < m; ++c) {
                rowCount = (mat[r][c] == 'X') ? (rowCount + 1) : 0;
                row[r][c] = rowCount;
            }
        }

        for (int c = 0; c < m; ++c) {
            int colCount = 0;
            for (int r = 0; r < n; ++r) {
                colCount = (mat[r][c] == 'X') ? (colCount + 1) : 0;
                col[r][c] = colCount;
            }
        }

        int result = 0;

        // Check potential bottom-right corners (r, c)
        for (int r = n - 1; r >= 0; --r) {
            for (int c = m - 1; c >= 0; --c) {
                int size = std::min(row[r][c], col[r][c]);

                while (size > result) {
                    // Top edge needs >= size consecutive 'X's ending at (r - size + 1, c)
                    // Left edge needs >= size consecutive 'X's ending at (r, c - size + 1)
                    if (row[r - size + 1][c] >= size && col[r][c - size + 1] >= size) {
                        result = size;
                        break;
                    }
                    --size;
                }
            }
        }

        return result;
    }
};