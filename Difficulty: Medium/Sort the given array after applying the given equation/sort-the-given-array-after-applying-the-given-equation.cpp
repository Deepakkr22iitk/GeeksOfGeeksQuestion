//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        int n=arr.size();
        vector<int> ans(n,0);
        int i=0,s=0,e=n-1;
        if(A>0)
        {
            i=n-1;
        }
        while(s<=e)
        {
            int start=A*(arr[s]*arr[s])+B*(arr[s])+C;
            int end=A*(arr[e]*arr[e])+B*(arr[e])+C;
            
            if(A>0)
            {
                if(start>end)
                {
                    ans[i]=start;
                    s++;
                }
                else
                {
                    ans[i]=end;
                    e--;
                }
                i--;
            }
            else
            {
                if(start>end)
                {
                    ans[i]=end;
                    e--;
                }
                else
                {
                    ans[i]=start;
                    s++;
                }
                i++;
            }
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

        int a, b, c;
        cin >> a >> b >> c;
        cin.ignore();

        Solution obj;
        vector<int> ans = obj.sortArray(arr, a, b, c);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << endl;

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends