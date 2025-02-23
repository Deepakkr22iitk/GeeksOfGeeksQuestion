//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        // vector<long long> ans;
        
        // for(int i=0;i<n;i++)
        // {
        //     int next=-1;
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if (arr[i] < arr[j])
        //         {
        //             next = arr[j];
        //             break;
        //         }
        //     }
        //     ans.push_back(next);
        // }
        
        // monotonic decreasing stack
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[i]>=st.top())
            {
                st.pop();
            }
            
            if(st.empty()) ans[i]=-1;
            
            else ans[i]=st.top(); 
            
            st.push(arr[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after reading t
    while (t--) {
        vector<int> a;
        string input;

        // Reading the entire input line for the array
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.nextLargerElement(a);

        // Print the result in the required format
        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout << endl;        // Ensure new line after each test case output
        cout << "~" << endl; // Ensure new line after each test case output
    }

    return 0;
}

// } Driver Code Ends