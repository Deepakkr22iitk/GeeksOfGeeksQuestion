class Solution {
  public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        int n=chairs.size();
        int sum=0;
        sort(chairs.begin(),chairs.end());
        sort(passengers.begin(),passengers.end());
        for(int i=0; i!=n; ++i){
            int diff=(chairs[i]-passengers[i]);
            if(diff<0) sum+=(-1*diff);
            else sum+=diff;
        }
        return sum;
    }
};