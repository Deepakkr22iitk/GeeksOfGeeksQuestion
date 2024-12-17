//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

using ll=long long;
class Solution {
  public:
    bool isValid(vector<int>& arr, int n, int m, int maxAllowed) {
        int s = 1, p = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > maxAllowed)
                return false;
            if (p + arr[i] <= maxAllowed) {
                p += arr[i];
            } else {
                s++;
                p = arr[i];
            }
        }
        return s <= m;
    }
    int findPages(vector<int>& arr, int m) {
        int n = arr.size();
        if (m > n)
            return -1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        int ans = -1, st = 0, end = sum;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (isValid(arr, n, m, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends