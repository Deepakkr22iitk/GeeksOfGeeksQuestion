//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        sort(arr.begin(),arr.end());
        
        for(int i = 2;i<n;i++){
            int l = 0;
            int r = i-1;
            
            while(l<r){
                int sum = arr[l] + arr[r];
                if(sum > arr[i]){
                    ans += r-l;
                    r--;
                }else{
                    l++;
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends