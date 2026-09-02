class Solution {
  public:
    int solve(int n, string s) {
        int m=s.size();
        set<char> accepted,rejected;
        int ans=0;
        for(int i=0;i<m;++i)
        {
            if(accepted.find(s[i])!=accepted.end())
            {
                n++;
            }
            else
            {
                if(rejected.find(s[i])!=rejected.end()) continue;
                else
                {
                    if(n==0)
                    {
                        rejected.insert(s[i]);
                        ans++;
                    }
                    else 
                    {
                        accepted.insert(s[i]);
                        n--;
                    }
                }
            }
        }
        return ans;
    }
};
