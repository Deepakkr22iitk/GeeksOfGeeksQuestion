//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n=a.size(),m=b.size();
        // if(n<m)
        // {
        //     int count=n,req=0;
        //     int i=0,j=0;
        //     while(count)
        //     {
        //         if(b[j]<a[i])
        //         {
        //             j++;
        //             req++;
        //         }
        //         else i++;
        //         count--;
        //     }
        //     while(req)
        //     {
        //         j--;
        //         swap(a[i],b[j]);
        //         i++;
        //         req--;
        //     }
        // }
        // else
        // {
        //     int count=m,req=0;
        //     int i=n-1,j=m-1;
        //     while(count)
        //     {
        //         if(a[i]>b[j])
        //         {
        //             i--;
        //             req++;
        //         }
        //         else j--;
        //         count--;
        //     }
        //     while(req)
        //     {
        //         i++;
        //         swap(a[i],b[j]);
        //         j--;
        //         req--;
        //     }
        // }
        
        
        int count=m,req=0;
        int i=n-1,j=m-1;
        while(count)
        {
            if(i>=0 && a[i]>b[j])
            {
                i--;
                req++;
            }
            else j--;
            count--;
        }
        while(req)
        {
            i++;
            swap(a[i],b[j]);
            j--;
            req--;
        }
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return ;
    }
};

//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Inputting the test cases

    while (t--) {
        vector<int> a, b;

        // Reading the first array as a space-separated line
        string arr1;
        getline(cin >> ws, arr1); // Use ws to ignore any leading whitespace
        stringstream ss1(arr1);
        int num;
        while (ss1 >> num) {
            a.push_back(num);
        }

        // Reading the second array as a space-separated line
        string arr2;
        getline(cin, arr2);
        stringstream ss2(arr2);
        while (ss2 >> num) {
            b.push_back(num);
        }

        Solution ob;
        ob.mergeArrays(a, b);

        // Output the merged result
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends