class Solution {
  public:
    int solve(int m)
    {
        if(m<=2) return m;
        
        int res=solve(m-1);
        int pair=(m-1)*solve(m-2);
        
        return res+pair;
    }
    int countFriendsPairings(int n) {
        return solve(n);
    }
};
