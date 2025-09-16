class Solution {
  public:
    string decodedString(string &s) {
        stack<string> st;
        
        int len=s.size();
        int i=len-1;
        while(i>=0)
        {
            if(s[i]=='[')
            {
                string curr="";
                while(st.top()!="]")
                {
                    curr+=st.top();
                    st.pop();
                }
                st.pop();
                
                string mkp="";
                while(!st.empty() && st.top()!="]")
                {
                    mkp+=st.top();
                    st.pop();
                }
                
                i--;
                string p;
                while(i>=0 && (s[i]>='0' && s[i]<='9'))
                {
                    p.push_back(s[i]);
                    i--;
                }
                
                reverse(p.begin(),p.end());
                
                int t=stoi(p);
                string newTemp="";
                for(int k=0;k<t;k++)
                {
                    newTemp+=curr;
                }
              
                st.push(newTemp+mkp);
            }
            else
            {
                string p="";
                p+=s[i];
                st.push(p);
                i--;
            }  
        }
        return st.top();
    }
};