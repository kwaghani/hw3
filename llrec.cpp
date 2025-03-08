
#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    // Base case - if head is NULL
    if (!head) { 
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    Node* nextNode = head->next;  // Store next node before modifying pointers
    head->next = nullptr;  // Disconnect current node to prevent cycles

    if (head->val <= pivot) { 
        smaller = head;
        llpivot(nextNode, smaller->next, larger, pivot);
    } else { 
        larger = head;
        llpivot(nextNode, smaller, larger->next, pivot);
    }

    head = nullptr; // Ensure head is completely detached
}
