class Solution {
  private:
    int gcd(int a,int b){
        while(a!=0 && b!=0){
            if(a>=b){
                a%=b;
            }
            else{
                b%=a;
            }
        }
        if(b==0){
            return a;
        }
        return b;
    }
    
    int lcm(int a,int b){
        return (a*b)/gcd(a,b);
    }
  public:
    int lcmTriplets(int n) {
        if(n<=2) return n;
        
        int res;
        if(n%2)
        {
            res=lcm(lcm(n,n-1),n-2);
        }
        else
        {
            // If n is even, check both:
            // (n, n-1, n-3) and (n-1, n-2, n-3)
            int l1 = lcm(lcm(n,n-1),n-3);
            int l2 = lcm(lcm(n-1,n-2),n-3);
            res = max(l1,l2);
        }
        return res;
    }
};