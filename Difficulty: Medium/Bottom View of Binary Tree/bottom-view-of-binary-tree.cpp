/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            Node* node = q.front().first;
            int level = q.front().second;
            q.pop();
            mp[level]=node->data;
            if(node->left)q.push({node->left,level-1});
            if(node->right)q.push({node->right,level+1});
        }
        vector<int>ans;
        for(auto it:mp)ans.push_back(it.second);
        return ans;
    }
};