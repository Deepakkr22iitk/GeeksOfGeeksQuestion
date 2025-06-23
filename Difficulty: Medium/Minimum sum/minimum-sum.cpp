class Solution {
  public:
    string minSum(vector<int> &arr) {
        // int n=arr.size();
        // sort(arr.begin(),arr.end());
        // int one=0,two=0;
        // for(int i=0;i<n;++i)
        // {
        //     if(i<n)
        //     {
        //         one*=10;
        //         one+=arr[i];
        //     }
        //     ++i;
        //     if(i<n)
        //     {
        //         two*=10;
        //         two+=arr[i];
        //     }
        // }
        
        // // cout<<one<<" "<<two<<"\n";
        // string ans=to_string(one+two);
        // return ans;
        
        sort(arr.begin(),arr.end());
        int ind = arr.size()-1,carry=0,sum=0;
        
        char ch;
        string str = "";
        
        while(ind >= 0){
            sum = carry + arr[ind--];
            if(ind >= 0){
                sum += arr[ind--];
            }
            ch = ((sum % 10) + '0');
            str += ch;
            carry = sum >= 10 ? 1 : 0;
        }
        
        if(carry) str += '1';
        
        reverse(str.begin(),str.end());
        
        ind = 0;
        while(ind < str.size() && str[ind] == '0') ind++;
        
        return ind >= str.size() ? "0" : str.substr(ind);
    }
};