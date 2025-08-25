class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        int n=s1.size(),m=s2.size();
        int ind1=0,ind2=0;
        while(ind2<m)
        {
            if(ind1<n && s2[ind2]==s1[ind1])
            {
                ind1++;
            }
            ind2++;
        }
        return ind1==n;
    }
};