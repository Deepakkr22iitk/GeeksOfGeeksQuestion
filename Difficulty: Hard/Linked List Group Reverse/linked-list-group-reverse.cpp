//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node* rev(Node* head){
        Node* prev=NULL;
        while(head){
            Node* next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
    Node *reverseKGroup(Node *head, int k) {
        Node* curr=head;
        Node* prev=head;
        Node* temp=new Node(-1);
        Node* d=temp;
        while(curr){
            int ori=k;
            while(ori-->1 && curr->next!=NULL){
                curr=curr->next;
            }
            Node* next=curr->next;
            curr->next=NULL;
            d->next=rev(prev);
            while(d->next){
                d=d->next;
            }
            prev=next;
            curr=next;
        }
        return temp->next;
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends