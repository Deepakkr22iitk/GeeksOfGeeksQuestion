//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        long long ans=0;
        while(!pq.empty()){
            long long min1=pq.top();pq.pop();
            if(pq.empty()) return ans;
            long long min2=pq.top();pq.pop();
            long long new_entry=min1+min2;
            ans+=new_entry;
            pq.push(new_entry);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends