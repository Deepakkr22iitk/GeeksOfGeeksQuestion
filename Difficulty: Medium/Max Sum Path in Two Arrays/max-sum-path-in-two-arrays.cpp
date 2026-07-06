class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        int n=a.size();
        int m=b.size();
        
        int sum1=0,sum2=0,result=0;
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(a[i]<b[j])
            {
                sum1+=a[i++];
            }
            else if(b[j]<a[i])
            {
                sum2+=b[j++];
            }
            else
            {
                result+=max(sum1,sum2);
                result+=a[i];
                i++;j++;
                sum1=0;sum2=0;
            }
        }
        
        while(i<n) sum1+=a[i++];
        while(j<m) sum2+=b[j++];
        
        result+=max(sum1,sum2);
        return result;
        
    }
};