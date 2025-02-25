//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    vector<int> nextSmallerElement(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        st.push(n);
        vector<int> next(n);
        for(int i = n - 1; i >=0 ; i-- ){
             
            int val = arr[i];
            
            while(st.size()!=1 && arr[st.top()] >= val)
                st.pop();
    
            next[i] = st.top();
            st.push(i);
        }
        return next;
    }
     vector<int> prevSmallerElement(vector<int>& arr) {
        stack<int> st;
        st.push(-1);
        int n = arr.size();
        vector<int>prev(n);
        for(int i = 0; i < n ; i++ ){
             
            int val = arr[i];
            
            while(st.top()!=-1 && arr[st.top()] >= val)
                st.pop();
    
            prev[i] = st.top();
            st.push(i);
        }
        return prev;
    }
  public:
    int getMaxArea(vector<int> &arr) {
        
        vector<int> next = nextSmallerElement(arr);
        vector<int> prev = prevSmallerElement(arr);
        int area = 0;
        
        for(int i = 0 ; i < arr.size() ; i++){
            
            int width = next[i] - prev[i] - 1 ;
            int length = arr[i];
            // cout<<width<<" ";
            area = max(area, length*width);
        }
        return area;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends