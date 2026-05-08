class Solution {
  public:
    bool check(string &t) {
        int bal = 0;
        
        for(char c : t) {
            if(c == '('){
                bal++;
            }
            else if(c == ')'){
                bal--;
                if(bal < 0){
                    return false;
                }
            }
        }
        
        return bal == 0;
    }
    
    vector<string> validParenthesis(string &s) {
        
        unordered_set<string> vis;
        queue<string> q;
        vector<string> ans;
        
        q.push(s);
        vis.insert(s);
        
        bool found = false;
        
        while(!q.empty()){
            
            string cur = q.front();
            q.pop();
            
            if(check(cur)) {
                ans.push_back(cur);
                found = true;
            }
            
            if(found){
                continue;
            }
            
            for(int i = 0; i < cur.size(); i++) {
                
                if(cur[i] != '(' && cur[i] != ')'){
                    continue;
                }
                
                string nxt = cur.substr(0, i) + cur.substr(i + 1);
                
                if(!vis.count(nxt)) {
                    vis.insert(nxt);
                    q.push(nxt);
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
    }
};
