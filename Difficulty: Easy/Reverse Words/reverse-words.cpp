//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        vector<string> words;
        string word;
        
        for (char c : str) {
            if (c == '.') {
                words.push_back(word);
                word = "";
            } else {
                word += c;
            }
        }
        
        words.push_back(word);
        reverse(words.begin(), words.end());
        
        string newWord;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            newWord += words[i];
            if (i != n - 1) newWord += ".";
        }
        
        return newWord;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends