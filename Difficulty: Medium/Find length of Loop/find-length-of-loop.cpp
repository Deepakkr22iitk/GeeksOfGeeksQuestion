/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        unordered_map<Node*,int> mp;
        Node* temp=head;
        int timer=1;
        while(temp)
        {
            if(mp.find(temp)!=mp.end())
            {
                return timer-mp[temp];
            }
            mp[temp]=timer;
            temp=temp->next;
            timer++;
        }
        return 0;
    }
};