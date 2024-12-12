//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMin(vector<int>& arr) {
        // int n=arr.size();
        // if(n==1) return arr[0];
        // if(arr[n-1]>arr[0]) return arr[0];
        // if(n>1 && arr[n-2]>arr[n-1]) return arr[n-1];
        // int low=1,high=n-2;
        // while(low<=high)
        // {
        //     int mid=low+(high-low)/2;

        //     if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1]) return arr[mid];
        //     else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1]) return arr[mid+1];
        //     else
        //     {
        //         if(arr[mid]>arr[n-1])  low=mid+1;
        //         else high=mid;
        //     }
        // }
        // return 0;

        int start=0,end=arr.size()-1;
        
        while (start<end) {
            if (arr[start]<arr[end])
                return arr[start];
            
            int mid = (start+end)/2;
            
            if (arr[mid]>=arr[start]) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
        
        return arr[start];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends