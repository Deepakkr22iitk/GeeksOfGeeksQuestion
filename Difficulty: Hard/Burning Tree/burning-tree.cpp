/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void burn(
        int root, 
        int sec, 
        int& totalSec, 
        unordered_map<int, vector<Node*>>& mp, 
        unordered_map<int, bool>& vis
    )
    {
        if(vis[root]) return;
        vis[root] = true;
        totalSec = max(sec, totalSec);
        for(int i=0;i<mp[root].size();i++) {
            burn(mp[root][i]->data, sec+1, totalSec, mp, vis);
        }
    }
    int minTime(Node* root, int target) {
        unordered_map<int, vector<Node*>> mp;
        stack<Node*> st;
        st.push(root);
        unordered_map<int, bool> vis;
        while(!st.empty()) {
            Node* top = st.top();
            st.pop();
            
            int x = top->data;
            vis[x] = false;
            if(top->left != NULL) {
                mp[x].push_back(top->left);
                mp[top->left->data].push_back(top);
                st.push(top->left);
            }
            
            if(top->right != NULL) {
                mp[x].push_back(top->right);
                mp[top->right->data].push_back(top);
                st.push(top->right);
            }
        }
        
        int totalSec = 0;
        burn(target, 0, totalSec, mp, vis);
        
        return totalSec;
    }
};