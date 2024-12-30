//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        priority_queue<int,vector<int>,greater<int> >pq;
        int size=arr.size();
        for(int i=0;i<size;i++){
            pq.push(arr[i]);
        }
        int ans=1;
        int maxans=1;
        int first=pq.top();
        pq.pop();
        while(!pq.empty()){
        int second=pq.top();
        pq.pop();
        if(second-first==1){
            ans++;
        }
        else if(second-first==0){
            ans=ans;
        }
        else{
            ans=1;
        }
        maxans=(maxans>ans)?maxans:ans;
        first=second;
        }
        return maxans;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends