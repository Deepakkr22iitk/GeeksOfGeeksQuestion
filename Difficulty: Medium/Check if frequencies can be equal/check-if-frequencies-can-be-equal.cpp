class Solution {
  public:
    bool sameFreq(string& s) {
        int n=s.size();
	    int mp[26]={0};
	    int maxi=0;
	    int unique=0;
	    for(int i=0;i<n;i++){
	       if(mp[s[i]-'a']==0){
	           unique++;
	       }
	        mp[s[i]-'a']++;
	        maxi=max(maxi,mp[s[i]-'a']);
	    }
        int x=0,y=0,z=0;
	    for(int i=0;i<26;i++){
	            if(mp[i]!=0){
	                
	            if(mp[i]==maxi){
	                x++;
	            }
	             if(mp[i]==1){
	                z++;
	            }
	            if(mp[i]==maxi-1){
	                y++;
	            }
	            }
	        }
	   if(x==unique||y==unique-1||((x==unique-1)&&(z==1))){
	       return true;
	   }
	   return false;
    }
};