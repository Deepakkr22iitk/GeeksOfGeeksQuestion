//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
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
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends