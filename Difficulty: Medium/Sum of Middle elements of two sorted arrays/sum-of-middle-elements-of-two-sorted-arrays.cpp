//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
    
        // Ensure arr1 is the smaller array
        if (n > m) {
            return kthElement(k, arr2, arr1);
        }
    
        int low = max(0, k - m), high = min(k, n);
    
        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = k - cut1;
    
            int left1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
            int right1 = (cut1 == n) ? INT_MAX : arr1[cut1];
            int right2 = (cut2 == m) ? INT_MAX : arr2[cut2];
    
            if (left1 <= right2 && left2 <= right1) {
                return max(left1, left2);
            } else if (left1 > right2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }
    
        return -1; // If the input is invalid
    }
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size();
        int m = arr2.size();
        return kthElement((n+m)/2,arr1,arr2) + kthElement((n+m)/2+1,arr1,arr2);
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends