//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        int n=arr.size();
        // vector<int> ans;
        // set<int> st;
        // for(int i=0;i<n;i++)
        // {
        //     st.insert(arr[i]);
        // }
        // for(int i=0;i<n;i++)
        // {
        //     if(st.find(i)!=st.end()) ans.push_back(i);
        //     else ans.push_back(-1);
        // }
        
        vector<int> ans = arr;
        for(int i=0;i<n;i++){
            if(ans[i]==-1 || ans[i]==i){
                continue;
            } else{
                while(ans[i]!=-1 && ans[i]!=i){
                    swap(ans[i], ans[ans[i]]);
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
    cin.ignore();

    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution solution;
        vector<int> ans = solution.rearrange(arr);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends