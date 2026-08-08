class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        int n=arr.size();
        int xor_all=0;
        
        for(int i=0;i<n;++i)
        {
            xor_all^=arr[i];
        }
        
        // Get its last set bit
        xor_all &= -xor_all;
        
        int num1=0,num2=0;
        for(int i=0;i<n;++i)
        {
            if(xor_all & arr[i]) num1^=arr[i];
            else num2^=arr[i];
        }
        
        if(num2<num1) swap(num1,num2);
        return {num1,num2};
    }
};