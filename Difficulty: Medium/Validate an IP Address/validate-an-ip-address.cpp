//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        int cnt=0;
        for(int i=0;i<str.length();)
        {
            string temp;
            while(i<str.length()&&str[i]!='.') {
                temp+=str[i];
                ++i;
            }
            while(i<str.length()&&str[i]=='.') ++i;
            
            if(temp.length()&&temp[0]=='0')
            {
                int j=0;
                while(j<temp.length()&&temp[j]=='0') ++j;
                if(j!=temp.length()) return false;
            }
            if(temp.length()){
                int val=stoi(temp);
                if((val<=255&&val>=0)) ++cnt;
                else return 0;
            }
        }
        return (cnt==4);
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends