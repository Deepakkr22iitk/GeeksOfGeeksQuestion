//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

class Solution{
public:
    bool solve( int num , int div ) {
        
        if( num%div == 0 ) return false;
        if( num%div == num ) return true;
        int quo = num/div;
        int rem = num%div;
        
        int res = (quo*div)+(rem - quo);
        
        return solve( res , div+1 );
        
    }
    bool isLucky(int n) {
        return solve( n , 2 );
    }
};

//{ Driver Code Starts.
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Solution obj;
        //calling isLucky() function
        if(obj.isLucky(n))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    
cout << "~" << "\n";
}
    
}
// } Driver Code Ends