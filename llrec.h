#ifndef LLREC_H
#define LLREC_H

#ifndef NULL
#define NULL 0
#endif

// Only include what is necessary for the recursive linked list functions

/**
 * Node struct for linked list.
 */
struct Node {
    int val;
    Node *next;
    Node(int v, Node* n) : val(v), next(n) {}
};

/**
 * Given a linked list pointed to by head, creates two lists:
 * - smaller: nodes with values less than or equal to the pivot.
 * - larger: nodes with values greater than the pivot.
 * The input list pointed to by head should be empty upon return.
 *
 * This function must be implemented recursively.
 */
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot);

/**
 * Given a linked list pointed to by head, removes (filters out) nodes
 * whose value meets the predicate criteria (i.e. should be removed).
 * Removed nodes are deallocated.
 *
 * This function must be implemented recursively.
 *
 * @param[in] head  Pointer to the head of the list.
 * @param[in] pred  Predicate functor that returns true for nodes to be removed.
 * @return Head pointer to the resulting (filtered) list.
 */
template <typename Comp>
Node* llfilter(Node* head, Comp pred) {
    if (!head) return nullptr;  // Base case: empty list

    // Recursively process the rest of the list.
    Node* filteredRest = llfilter(head->next, pred);

    // If current node meets the predicate, remove it.
    if (pred(head->val)) {
        delete head;
        return filteredRest;
    } else {
        head->next = filteredRest;
        return head;
    }
}

#endif
