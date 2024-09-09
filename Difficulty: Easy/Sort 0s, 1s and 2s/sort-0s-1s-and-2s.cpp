//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n=arr.size();
        int i=0,j=n-1;
        int idx=0;
        while(idx<n)
        {
            if(arr[idx]==0)
            {
                arr[i]=0;
                i++;
            }
            else if(arr[idx]==2)
            {
                // arr[j]=2;
                j--;
            }
            idx++;
        }
        while(i<=j)
        {
            arr[i]=1;
            i++;
        }
        j++;
        while(j<n)
        {
            arr[j]=2;
            j++;
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends