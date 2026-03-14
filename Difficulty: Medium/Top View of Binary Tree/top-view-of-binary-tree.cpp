/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int index = it.second;
            
            if(mp.find(index) == mp.end()) {
                mp[index] = node->data;
            }
            
            if(node->left != NULL) {
                q.push({node->left, index - 1});
            }
            
            if(node->right != NULL) {
                q.push({node->right, index + 1});
            }
        }
        
        vector<int> ans;
        for(auto it : mp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};