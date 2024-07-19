#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
// constructor
    ListNode(int x){
      this->val = x;
      this->next = NULL;
}
};
// Function to reverse the singly linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;     // Previous node, initially set to NULL
    ListNode* curr = head;     // Current node, initially set to head
    ListNode* next = NULL;     // Next node, initially set to NULL

    while (curr != NULL) {
        next = curr->next;     // Store the next node
        curr->next = prev;     // Reverse the current node's pointer
        prev = curr;           // Move the previous node one step forward
        curr = next;           // Move the current node one step forward
    }
    return prev;               // New head of the reversed list
}
// Function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
// Helper function to insert a new node at the end of the list
void insert(ListNode*& head, int val) {
    if (head == NULL) {
        head = new ListNode(val);
    } else {
        ListNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new ListNode(val);
    }
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    cout << "Original list: ";
    printList(head);
    // Reverse the linked list
    head = reverseList(head);
    cout << "Reversed list: ";
    printList(head);
    return 0;
}


// output 
// Original list: 1 2 3 4 5
// Reversed list: 5 4 3 2 1
