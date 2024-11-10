//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        // int n= a.size();
        // int m= b.size();
        // vector<int> arr;
        // int i=0,j=0,k=0;
        // while(i<n && j<m){
        //     if(a[i]==b[j]){
        //         arr[k]=a[i];
        //         i++;
        //         j++;
        //         k++;
        //     }
        //     else if(a[i]>b[j]){
        //         arr[k]=b[j];
        //         i++;
        //         j++;
        //         k+=2;
        //     }
            
        //     else{
        //         arr[k]=b[j];
        //         arr[k+1]=a[i];
        //         i++;
        //         j++;
        //         k+=2;
        //     }
        // }
        
        
        // while(j!=m){
        //     arr[k]=b[j];
        //     j++;
        //     k++;
        // }
        
        // while(i!=n){
        //     arr[k]=a[i];
        //     i++;
        //     k++;
        // }
        
        
        // return arr;
        
        
        
        int i=0,j=0;
        vector<int> ans;
        
        while(i<a.size() && j<b.size())
        {
            if(a[i]<b[j])
            {
                ans.push_back(a[i]);
                i++;
            }
            else if(b[j]<a[i])
            {
                ans.push_back(b[j]);
                j++;
            }
            else
            {
                ans.push_back(a[i]);
                i++;
                j++;
            }
        }
        
        while(i<a.size())
        {
            ans.push_back(a[i]);
            i++;
        }
        while(j<b.size())
        {
            ans.push_back(b[j]);
            j++;
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
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends