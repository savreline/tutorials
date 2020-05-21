#include "list.h"
    
DLinkedList::DLinkedList() {
    head = NULL;
    tail = NULL;
}

DLinkedList::~DLinkedList() {
    while (head) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    head = NULL;
    tail = NULL;   
}

/***************/
/*** Inserts ***/
/***************/
void DLinkedList::insertFront(int val) {
    Node *node = new Node(val);

    // Extra step: update prev
    if (head)
        head->prev = node;
    else 
        tail = node;

    // Standard re-link
    node->next = head;
    head = node;
}

/***************/
/*** Delete ***/
/***************/
void DLinkedList::deleteBack() {
    // Edge cases: nothing to delete
    //  OR single-element list
    if (!head) return;
    if (!head->next) { 
        delete head;
        head = NULL;
        tail = NULL; 
        return; 
    }

    // Delete the tail
    tail = tail->prev;
    delete tail->next;
    tail->next = NULL;
}

/************/
/*** Misc ***/
/************/
void DLinkedList::printForward() {
    Node *curr = head;
    while (curr) {
        cout << curr->val;
        curr = curr->next;
        if (curr) cout << ", ";
    }
    cout << endl;
}

void DLinkedList::printBackward() {
    Node *curr = tail;
    while (curr) {
        cout << curr->val;
        curr = curr->prev;
        if (curr) cout << ", ";
    }
    cout << endl;
}

bool DLinkedList::empty() {
    return !head;
}

int DLinkedList::size() {
    int length = 0;
    Node *curr = head;
    while (curr) {
        length++;
        curr = curr->next;
    }
    return length;
}

/************/
/*** Swap ***/
/************/
// Also take a look at 
// https://stackoverflow.com/questions/20095529/swapping-nodes-in-double-linked-list
void DLinkedList::swap(int x, int y) {

    // Locate the nodes
    Node *node1 = head;
    Node *node2 = head;
    bool adjacent = false;
    while (node1 && node1->val != x)
        node1 = node1->next;
    while (node2 && node2->val != y)
        node2 = node2->next;
    if (!node1 || !node2)
        return;

    // Detect adjacent and swap if need be
    if (node1->next == node2)
        adjacent = true;
    if (node2->next == node1) {
        adjacent = true;
        Node *temp = node1;
        node1 = node2;
        node2 = temp;
    }

    // Re-assign the head and tail if need be
    if (!node1->prev)
        head = node2;
    if (!node2->next)
        tail = node1;

    // Save references
    Node *node1next = node1->next;
    Node *node1prev = node1->prev;

    /* 8 pointer case */
    if (!adjacent) {
        // Re-link node1
        if (node1->next)
            node1->next->prev = node2;
        if (node1->prev)
            node1->prev->next = node2;
        node1->next = node2->next;
        node1->prev = node2->prev;

        // Re-link node2
        if (node2->next)
            node2->next->prev = node1;
        if (node2->prev)
            node2->prev->next = node1;
        node2->next = node1next;
        node2->prev = node1prev;

    /* 6 pointer case */
    } else {
        // Re-link node1
        if (node1->prev)
            node1->prev->next = node2;
        node1->next = node2->next;
        node1->prev = node2;

        // Re-link node2
        if (node2->next)
            node2->next->prev = node1;
        node2->next = node1;
        node2->prev = node1prev;
    }
}

/**********************/
/*** Main and Tests ***/
/**********************/
int main() {
    /* Enable all tests or some tests */
    bool runAllTests = true;
    int tests[8] = {0, 0, 0, 0, 0,
                    0, 1, 1};
    if (runAllTests) {
        for (int i = 0; i < 8; i++)
        tests[i] = 1;
    }

    /* Test 1: Insert at Front, Remove, Repeat */
    if (tests[1]) {
        DLinkedList l1 = DLinkedList();
        cout << endl << "L1 CREATED" << endl;
        cout << "Is l1 empty? " << l1.empty() << endl;

        l1.insertFront(1);
        l1.insertFront(2);
        l1.insertFront(3);
        cout << "l1 after insertion F: "; l1.printForward();
        cout << "l1 after insertion B: "; l1.printBackward();
        cout << "Is l1 empty? " << l1.empty() << endl;

        int size = l1.size();
        for (int i = 0; i < size + 1; i++)
            l1.deleteBack();
        cout << "l1 after removal F: "; l1.printForward();
        cout << "l1 after removal B: "; l1.printBackward();
        cout << "Is l1 empty? " << l1.empty() << endl;

        l1.insertFront(1);
        l1.insertFront(2);
        l1.insertFront(3);        
        cout << "l1 after insertion F: "; l1.printForward();
        cout << "l1 after insertion B: "; l1.printBackward();
        cout << "Is l1 empty? " << l1.empty() << endl;

        size = l1.size();
        for (int i = 0; i < size + 1; i++)
            l1.deleteBack();
        cout << "l1 after removal F: "; l1.printForward();
        cout << "l1 after removal B: "; l1.printBackward();
        cout << "Is l1 empty? " << l1.empty() << endl;
    }

    /* Test 2: Insert at Front, Remove, Repeat */
    if (tests[2]) {
        DLinkedList l2 = DLinkedList();
        cout << endl << "L2 CREATED" << endl;
        cout << "Is l2 empty? " << l2.empty() << endl;

        l2.insertFront(1);
        l2.insertFront(2);
        l2.insertFront(3);
        l2.insertFront(4);
        cout << "l2 after insertion F: "; l2.printForward();
        cout << "l2 after insertion B: "; l2.printBackward();
        cout << "Is l2 empty? " << l2.empty() << endl;

        l2.deleteBack();
        l2.deleteBack();
        cout << "l2 after half-removal F: "; l2.printForward();
        cout << "l2 after half-removal B: "; l2.printBackward();        
        cout << "Is l2 empty? " << l2.empty() << endl;

        l2.insertFront(10);
        l2.insertFront(20);
        l2.insertFront(30);
        l2.insertFront(40);
        cout << "l2 after insertion F: "; l2.printForward();
        cout << "l2 after insertion B: "; l2.printBackward();
        cout << "Is l2 empty? " << l2.empty() << endl;

        int size = l2.size();
        for (int i = 0; i < size + 1; i++)
            l2.deleteBack();
        cout << "l2 after full removal F: "; l2.printForward();
        cout << "l2 after full removal B: "; l2.printBackward();
        cout << "Is l2 empty? " << l2.empty() << endl;
    }

    /* Test 3: Test Swap */
    if (tests[3]) {
        DLinkedList l3 = DLinkedList();
        cout << endl << "L3 CREATED" << endl;
        cout << "Is l3 empty? " << l3.empty() << endl;

        for (int i = 9; i > 0; i--)
            l3.insertFront(i);
        cout << "l3 after insertion F: "; l3.printForward();
        cout << "l3 after insertion B: "; l3.printBackward();
        cout << "Is l3 empty? " << l3.empty() << endl;

        // Try to swap something that DNE
        l3.swap(12, 4);
        l3.swap(4, 13);
        l3.swap(20, 30);
        cout << "l3 after swapping nodes that DNE F: "; l3.printForward();
        cout << "l3 after swapping nodes that DNE B: "; l3.printBackward();
        cout << "Is l3 empty? " << l3.empty() << endl;

        // Swap in the middle
        l3.swap(3, 7);
        cout << "l3 after middle swap F: "; l3.printForward();
        cout << "l3 after middle swap B: "; l3.printBackward();
        cout << "Is l3 empty? " << l3.empty() << endl;

        // Swap at the head
        l3.swap(0, 6);
        cout << "l3 after head swap F: "; l3.printForward();
        cout << "l3 after head swap B: "; l3.printBackward();
        cout << "Is l3 empty? " << l3.empty() << endl;

        // Swap at the tail
        l3.swap(4, 9);
        cout << "l3 after tail swap F: "; l3.printForward();
        cout << "l3 after tail swap B: "; l3.printBackward();
        cout << "Is l3 empty? " << l3.empty() << endl;

        // Swap at head and tail
        l3.swap(6, 4);
        cout << "l3 after head and tail swap F: "; l3.printForward();
        cout << "l3 after head and tail swap B: "; l3.printBackward();
        cout << "Is l3 empty? " << l3.empty() << endl;
    }

    /* Test 4: Test Adjacent Swaps */
    if (tests[4]) {
        DLinkedList l4 = DLinkedList();
        cout << endl << "L4 CREATED" << endl;
        cout << "Is l4 empty? " << l4.empty() << endl;

        for (int i = 7; i > 0; i--)
            l4.insertFront(i);
        cout << "l4 after insertion F: "; l4.printForward();
        cout << "l4 after insertion B: "; l4.printBackward();
        cout << "Is l4 empty? " << l4.empty() << endl;

        l4.swap(4, 5);
        cout << "l4 after first swap F: "; l4.printForward();
        cout << "l4 after first swap B: "; l4.printBackward();
        cout << "Is l4 empty? " << l4.empty() << endl;

        l4.swap(5, 4);
        cout << "l4 after second swap F: "; l4.printForward();
        cout << "l4 after second swap B: "; l4.printBackward();
        cout << "Is l4 empty? " << l4.empty() << endl;
    }

    /* Test 5: Test Short Lists for Swap */
    if (tests[5]) {
        DLinkedList l5 = DLinkedList();
        cout << endl << "L5 CREATED" << endl;
        cout << "Is l5 empty? " << l5.empty() << endl;

        // One-element list
        l5.insertFront(1);
        cout << "l5 after insertion F: "; l5.printForward();
        cout << "l5 after insertion B: "; l5.printBackward();
        cout << "Is l5 empty? " << l5.empty() << endl;

        // Swap the node
        l5.swap(1, 1);
        cout << "l5 after swap F: "; l5.printForward();
        cout << "l5 after swap B: "; l5.printBackward();
        cout << "Is l5 empty? " << l5.empty() << endl;

        // Go to a 2-element list
        l5.insertFront(2);
        cout << "l5 after insertion F: "; l5.printForward();
        cout << "l5 after insertion B: "; l5.printBackward();
        cout << "Is l5 empty? " << l5.empty() << endl;

        // Try to swap something that DNE
        l5.swap(12, 2);
        l5.swap(1, 13);
        l5.swap(20, 30);
        cout << "l5 after swapping nodes that DNE F: "; l5.printForward();
        cout << "l5 after swapping nodes that DNE B: "; l5.printBackward();
        cout << "Is l5 empty? " << l5.empty() << endl;

        // Swap the two nodes
        l5.swap(1, 2);
        cout << "l5 after swap F: "; l5.printForward();
        cout << "l5 after swap B: "; l5.printBackward();
        cout << "Is l5 empty? " << l5.empty() << endl;

        // Go to a 3-element list
        l5.insertFront(3);
        cout << "l5 after insertion F: "; l5.printForward();
        cout << "l5 after insertion B: "; l5.printBackward();
        cout << "Is l5 empty? " << l5.empty() << endl;

        // Swap some nodes
        l5.swap(1, 3);
        cout << "l5 after first swap F: "; l5.printForward();
        cout << "l5 after first swap B: "; l5.printBackward();
        cout << "Is l5 empty? " << l5.empty() << endl;

        l5.swap(2, 3);
        cout << "l5 after second swap F: "; l5.printForward();
        cout << "l5 after second swap B: "; l5.printBackward();
        cout << "Is l5 empty? " << l5.empty() << endl;
    }
}
