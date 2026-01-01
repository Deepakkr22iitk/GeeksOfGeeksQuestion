/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        int cnt1 = 0;
        int cnt2 =0;
        Node *temp1 = head1;
        Node *temp2 = head2;
        while(temp1)
        {

            cnt1++;
            temp1 = temp1->next;
        }
        while(temp2)
        {

            cnt2++;
            temp2 = temp2->next;
        }
        if(cnt2>cnt1)
        {
            int x = cnt2-cnt1;  //5-3 = 2
            while(x--)
            {
                head2 = head2->next;
            }
            while(head1)
            {

                if(head1!=head2)
                {
                    head1 = head1->next;
                    head2 = head2->next;
                }
                else 
                return head1;
            }
        }
        else
        {
             int x = cnt1-cnt2;  //5-3 = 2
            while(x--)
            {
                head1 = head1->next;
            }
            while(head1)
            { 
                if(head1!=head2)
                {
                    head1 = head1->next;
                    head2 = head2->next;
                }
                else 
                return head1;
            } 
        }
    }
};