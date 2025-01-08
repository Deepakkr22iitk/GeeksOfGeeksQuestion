//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n=arr.size();
        int sum=0;
        unordered_map<int,int> suff_Sum;
        for(int i=0;i<n;++i)
        {
            sum+=arr[i];
            suff_Sum[sum]=(i+1);
        }
        vector<int> ans;
        sum=0;
        for(int i=0;i<n;++i)
        {
            if(suff_Sum.find(target+sum)!=suff_Sum.end())
            {
                ans.push_back(i+1);
                ans.push_back(suff_Sum[target+sum]);
                break;
            }
            sum+=arr[i];
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends