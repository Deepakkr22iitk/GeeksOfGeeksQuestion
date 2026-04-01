class Solution {
  public:
    int countStrings(int n) {
        if(n==1 ) return 2;
       if(n==2) return 3;
       int a = 2;
       int  b = 3;
       int count = 0;                                                 //    Iterations working 
       for(int i=3;i<=n;i++){                                    // count 2+3 =5 ;  n =3
           count = a+b;                                               // a = 3 , b =5 
           a=b;                                                          // count 3+5= 8;  n=4
           b=count;                                                     // a = 5, b = 8
       }                                                                  // count = 5+8=13 n=5
       return b;
    }
};