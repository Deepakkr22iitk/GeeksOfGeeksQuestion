//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> ans;
        unordered_map<int,int> freq;
        for(int i=0;i<k;++i)
        {
            freq[arr[i]]++;
        }
        ans.push_back(freq.size());
        int count=freq.size();
        for(int i=k;i<arr.size();++i)
        {
            
            if(freq[arr[i-k]]==1)
            {
                count--;
            }
            freq[arr[i-k]]--;
            if(freq.find(arr[i])==freq.end() || freq[arr[i]]==0)
            {
                count++;
            }
            freq[arr[i]]++;
            ans.push_back(count);
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
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends