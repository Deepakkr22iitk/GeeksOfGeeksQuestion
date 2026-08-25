class Solution {
  public:
    int minMoves(vector<int>& arr) {
        int n=arr.size(),maxi=0;
        vector<int>v(n+1,0);
        for(int i:arr){v[i]+=1+v[i-1];maxi=max(maxi,v[i]);}
        return n-maxi ;
    }
};