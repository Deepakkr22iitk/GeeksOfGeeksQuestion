//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        Node* previous = head;
        Node* curr = head -> next;
        while(curr != head){
            Node* nextNode = curr -> next;
            curr -> next = previous;
            previous = curr;
            curr  = nextNode;
        }
        head -> next = previous;
        return previous;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        Node* curr = head -> next;
        Node* previous =  head;
        if(head -> data == key){
            while(previous -> next != head){
                previous = previous -> next;
            }
            previous -> next = head -> next;
            Node* temp = head;
            head = head -> next;
            if(temp == head){
                delete temp;
                return NULL;
            }
            delete temp;
            return head;
        }
        while(curr != head){
            if(curr -> data == key){
                Node* nextNode = curr -> next;
                
                previous -> next = nextNode;
                
                delete curr;
                return head;
            }
            previous = curr;
            curr = curr -> next;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends