class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        
        reverse(x.begin(),x.end());
        reverse(y.begin(),y.end());
        
        int i=0,j=0;
        int hor=1,ver=1;
        int total=0;
        
        while(i<x.size() && j<y.size())
        {
            if(x[i]>=y[j])
            {
                total+=(x[i]*hor);
                ver++;
                i++;
            }
            else
            {
                total+=(y[j]*ver);
                hor++;
                j++;
            }
        }
        
        while(i<x.size())
        {
            total+=(x[i]*hor);
            ver++;
            i++;
        }
        
        while(j<y.size())
        {
            total+=(y[j]*ver);
            hor++;
            j++;
        }
        
        return total;
    }
};
