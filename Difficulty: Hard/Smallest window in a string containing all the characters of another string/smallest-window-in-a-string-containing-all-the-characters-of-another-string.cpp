//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        int m = s.length();
        int n = p.length();
    
        // Edge case: if s is smaller than p, it's impossible to find a valid window
        if (m < n) return "-1";
    
        // Frequency arrays for characters in 'a' to 'z'
        int pCount[26] = {0};
        int windowCount[26] = {0};
    
        // Count the frequency of characters in string p
        for (char c : p) {
            pCount[c - 'a']++;
        }
    
        int required = 0;  // Number of unique characters in p that need to be fully matched
        for (int i = 0; i < 26; i++) {
            if (pCount[i] > 0) {
                required++;
            }
        }
    
        int left = 0, right = 0;
        int formed = 0;  // To keep track of how many characters in p are satisfied in the window
    
        int minLength = INT_MAX;  // Length of the smallest window
        int startIdx = 0;         // Start index of the smallest window
    
        while (right < m) {
            // Expand the window by including s[right]
            char c = s[right];
            windowCount[c - 'a']++;
    
            // Check if this character fully satisfies the condition for p
            if (pCount[c - 'a'] > 0 && windowCount[c - 'a'] == pCount[c - 'a']) {
                formed++;
            }
    
            // Try to contract the window until it ceases to be valid
            while (left <= right && formed == required) {
                c = s[left];
    
                // Update the smallest window
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    startIdx = left;
                }
    
                // Shrink the window by removing s[left]
                windowCount[c - 'a']--;
    
                // If this character no longer satisfies p's condition, reduce formed count
                if (pCount[c - 'a'] > 0 && windowCount[c - 'a'] < pCount[c - 'a']) {
                    formed--;
                }
    
                left++;  // Move the left pointer to the right
            }
    
            right++;  // Expand the window by moving the right pointer to the right
        }
    
        // If no valid window was found, return "-1"
        return minLength == INT_MAX ? "-1" : s.substr(startIdx, minLength);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends