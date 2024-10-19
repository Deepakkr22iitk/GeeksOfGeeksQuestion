//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        int n=str.size();
        if(str[n-1]=='0') return str;
        
        if(n<2)
        {
            if(str[1]-'0'>5) return "10";
            return "0";
        }
        
        if(str[n-1]-'0'>5)
        {
            // str[n-1]='0';
            // why we can't update str[n-1] here?
            int idx=n-2;
            while(idx>=0 && str[idx]=='9')
            {
                str[idx]='0';
                idx--;
            }
            if(idx==-1) str="1"+str;
            else str[idx]+=1;
        }
        n=str.size();
        str[n-1]='0';
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends