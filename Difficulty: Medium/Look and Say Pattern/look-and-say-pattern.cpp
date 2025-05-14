//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string getNext(string str){
        
        int len = str.size();
        int j = 0;
        string ans = "";
        while(j < len-1){
            int count = 1;
            char curr = str[j];
            while(j < (len-1) && str[j] == str[j+1]){
                count++;
                j++;
            }
            
            ans = ans + (to_string(count) + curr);
            j++;
            
        }
        if(str[len - 2] != str[len - 1])
            ans += (to_string(1)+ str[len - 1]);
            
        return ans;
        
    }
    string countAndSay(int n) {
        string str = "1";
        //str = getNext("21");
        //cout << "111221\n";
        for(int i = 2; i <= n; i++){
            str = getNext(str);
        }
        return str;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends