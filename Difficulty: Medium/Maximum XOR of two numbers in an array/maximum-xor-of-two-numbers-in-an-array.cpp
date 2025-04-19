//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Node{
    public:
    Node* children[2];
    Node()
    {
        for(auto &x:children)
        {
            x=nullptr;
        }
    }
};

class Trie{
  Node* root;
  public:
  Trie()
  {
      root=new Node();
  }
  
  void insert(int n)
  {
      Node* ptr=root;
      for(int i=31;i>=0;--i)
      {
          int bit=(n>>i)&1;
          if(ptr->children[bit]==nullptr) ptr->children[bit]=new Node();
          
          ptr=ptr->children[bit];
      }
  }
  
  int get_mx_xor(int n)
  {
      Node* ptr=root;
      int res=0;
      for(int i=31;i>=0;--i)
      {
          int bit=(n>>i)&1;
          
          if(ptr->children[!bit]!=nullptr) 
          {
              res=(res| (1<<i));
              ptr=ptr->children[!bit];
          }
          else ptr=ptr->children[bit];
      }
      
      return res;
  }
};
class Solution {
  public:
    int maxXor(vector<int> &arr) {
        // code here
        
        Trie* t=new Trie();
        
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;++i)
        {
            t->insert(arr[i]);
        }
        
        for(int i=0;i<n;++i)
        {
            int curr=t->get_mx_xor(arr[i]);
            ans=max(ans,curr);
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends