//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
#define vc vector<char>
#define vvc vector<vc>
#define vb vector<bool>
#define vvb vector<vb>
  public:
    // Function to check if the given position is within matrix boundaries
    bool checkBoundary(int i, int j, int n, int m) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }

    // DFS function to search for the word in the grid
    bool helpFind(int i, int j, int idx, int n, int m, vvc &mat, string &word,
                  set<pair<int, int>> &vis) {
        // If the entire word is found, return true
        if (idx == word.size()) return true;

        // If out of boundary, return false
        if (!checkBoundary(i, j, n, m)) return false;

        // Movement direction: up, right, down, left
        int dt[] = {-1, 0, 1, 0, -1}; 

        // Mark the current cell as visited
        vis.insert(make_pair(i, j));

        // Explore all four possible directions
        for (int k = 0; k < 4; ++k) {
            int newi = i + dt[k], newj = j + dt[k + 1];

            // Check if we can move to the next cell and continue search
            if (checkBoundary(newi, newj, n, m) && word[idx] == mat[newi][newj] &&
                vis.find(make_pair(newi, newj)) == vis.end()) {
                
                // Recursively search in the new direction
                if (helpFind(newi, newj, idx + 1, n, m, mat, word, vis)) 
                    return true;
            }
        }

        // Backtracking: remove the current cell from visited set
        vis.erase(make_pair(i, j));
        
        return false;
    }

    // Main function to check if the word exists in the grid
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int n = mat.size(), m = mat[0].size();

        // Try to start the search from every cell in the grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (word[0] == mat[i][j]) { // Start DFS if first letter matches
                    set<pair<int, int>> vis; // Stores visited cells
                    if (helpFind(i, j, 1, n, m, mat, word, vis)) 
                        return true;
                }
            }
        }
        
        return false; // Word not found
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends