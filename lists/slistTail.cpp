#include "list.h"

SLinkedList::SLinkedList() {
    head = NULL;
    tail = NULL;
}

SLinkedList::~SLinkedList() {
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
void SLinkedList::insertFront(int val) {
    Node *node = new Node(val);
    if (!head)
        tail = node;

    node->next = head;
    head = node;
}

void SLinkedList::insertBack(int val) {
    Node *node = new Node(val);

    // Edge case: empty list. 
    // Need to set the head and tail pointers
    if (!head) {
        head = node;
        tail = node;
        return;
    }

    // Place the node at the end
    // Relink the tail
    tail->next = node;
    tail = node;
}

void SLinkedList::insertAfter(int val, int x) {
    // Find the spot
    Node *before = head;
    while (before && before->val != x)
        before = before->next;
    
    // If found, insert
    Node *node;
    if (before) {
        node = new Node(val); // placed here to avoid a memory leak!
        node->next = before->next;
        before->next = node;
    }

    // Update tail if need be
    if (!node->next)
        tail = node;
}

/***************/
/*** Deletes ***/
/***************/
void SLinkedList::deleteFront() {
    // Edge cases: nothing to delete
    //  OR single-element list
    if (!head) return;
    if (!head->next)
        tail = NULL;

    // Would set the head to null if single-element list
    Node *oldhead = head;
    head = head->next;
    delete oldhead;
}

void SLinkedList::deleteBack() {
    // Edge cases: nothing to delete
    //  OR single-element list
    if (!head) return;
    if (!head->next) { 
        delete head;
        head = NULL;
        tail = NULL; 
        return; 
    }

    // Locate the second last node and
    // delete it's next pointer
    Node *secondlast = head;
    while (secondlast->next->next)
        secondlast = secondlast->next;

    delete secondlast->next;
    secondlast->next = NULL;
    tail = secondlast;
}

void SLinkedList::deleteNode(int x) {
    if (!head) return;
    if (head->val == x) {
        deleteFront();
        return;
    }

    // Find the spot
    Node *before = head;
    while (before->next && before->next->val != x)
        before = before->next;

    // If found, delete
    if (before->next) {
        Node *toDelete = before->next;
        before->next = before->next->next;
        delete toDelete;
    }

    // Update the tail if need be
    if (!before->next)
        tail = before;
}

/************/
/*** Misc ***/
/************/
void SLinkedList::print() {
    Node *curr = head;
    while (curr) {
        cout << curr->val;
        curr = curr->next;
        if (curr) cout << ", ";
    }
    cout << endl;
}

bool SLinkedList::empty() {
    return !head;
}

int SLinkedList::size() {
    int length = 0;
    Node *curr = head;
    while (curr) {
        length++;
        curr = curr->next;
    }
    return length;
}

/**************/
/*** Harder ***/
/**************/
void SLinkedList::copyArray(int array[], int size) {
    Node *curr = NULL, *before = NULL;

    for (int i = 0; i < size; i++) {
        curr = new Node(array[i]);

        // Link before
        if (before)
            before->next = curr;
        
        // Set head
        if (i == 0)
            head = curr;

        // Set tail
        if (i == size - 1)
            tail = curr;

        before = curr;
    }
}

void SLinkedList::reverse() {
    Node *before = NULL, *after = NULL, *curr = head;
    Node *oldhead = head;

    while (curr) {
        // 1. Advance the after
        after = curr->next;

        // 2. Flip the link
        curr->next = before;

        // 3. Advance the before and curr
        before = curr;
        curr = after; 
    }

    head = before;
    tail = oldhead;
}

/**********************/
/*** Main and Tests ***/
/**********************/
int main() {
    /* Enable all tests or some tests */
    bool runAllTests = true;
    int tests[12] = {0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0,
                    0, 1};
    if (runAllTests) {
        for (int i = 0; i < 12; i++)
        tests[i] = 1;
    }

    /* Test 1: Insert at Front, Remove, Repeat */
    if (tests[1]) {
        SLinkedList l1 = SLinkedList();
        cout << endl << "L1 CREATED" << endl;
        cout << "Is l1 empty? " << l1.empty() << endl;

        l1.insertFront(1);
        l1.insertFront(2);
        l1.insertFront(3);
        cout << "l1 after insertion "; l1.print();
        cout << "Is l1 empty? " << l1.empty() << endl;

        int size = l1.size();
        for (int i = 0; i < size + 1; i++)
            l1.deleteFront();
        cout << "l1 after removal "; l1.print();
        cout << "Is l1 empty? " << l1.empty() << endl;

        l1.insertFront(1);
        l1.insertFront(2);
        l1.insertFront(3);        
        cout << "l1 after insertion "; l1.print();
        cout << "Is l1 empty? " << l1.empty() << endl;

        size = l1.size();
        for (int i = 0; i < size + 1; i++)
            l1.deleteFront();
        cout << "l1 after removal "; l1.print();
        cout << "Is l1 empty? " << l1.empty() << endl;
    }

    /* Test 2: Insert at Back, Remove, Repeat */
    if (tests[2]) {
        SLinkedList l2 = SLinkedList();
        cout << endl << "L2 CREATED" << endl;
        cout << "Is l2 empty? " << l2.empty() << endl;

        l2.insertBack(1);
        l2.insertBack(2);
        l2.insertBack(3);
        cout << "l2 after insertion "; l2.print();
        cout << "Is l2 empty? " << l2.empty() << endl;

        int size = l2.size();
        for (int i = 0; i < size + 1; i++)
            l2.deleteBack();
        cout << "l2 after removal "; l2.print();
        cout << "Is l2 empty? " << l2.empty() << endl;

        l2.insertBack(1);
        l2.insertBack(2);
        l2.insertBack(3);
        cout << "l2 after insertion "; l2.print();
        cout << "Is l2 empty? " << l2.empty() << endl;

        size = l2.size();
        for (int i = 0; i < size + 1; i++)
            l2.deleteBack();
        cout << "l2 after removal "; l2.print();
        cout << "Is l2 empty? " << l2.empty() << endl;
    }

    /* Test 3: Alternate Front & Back Insertion */
    if (tests[3]) {
        SLinkedList l3 = SLinkedList();
        cout << endl << "L3 CREATED" << endl;
        cout << "Is l3 empty? " << l3.empty() << endl;

        l3.insertBack(1);
        l3.insertFront(2);
        l3.insertBack(3);
        l3.insertFront(4);
        cout << "l3 after insertion "; l3.print();
        cout << "Is l3 empty? " << l3.empty() << endl;

        l3.deleteBack();
        l3.deleteFront();
        cout << "l3 after half-removal "; l3.print();
        cout << "Is l3 empty? " << l3.empty() << endl;

        l3.insertBack(10);
        l3.insertFront(20);
        l3.insertBack(30);
        l3.insertFront(40);
        cout << "l3 after insertion "; l3.print();
        cout << "Is l3 empty? " << l3.empty() << endl;

        int size = l3.size();
        for (int i = 0; i < 0.5 * (size + 1); i++) {
            l3.deleteBack();
            l3.deleteFront();
        }
        cout << "l3 after full removal "; l3.print();
        cout << "Is l3 empty? " << l3.empty() << endl;
    }

    /* Test 4: Alternate Back & Front Insertion */
    if (tests[4]) {
        SLinkedList l4 = SLinkedList();
        cout << endl << "L4 CREATED" << endl;
        cout << "Is l4 empty? " << l4.empty() << endl;

        l4.insertFront(2);
        l4.insertBack(1);
        l4.insertBack(3);
        l4.insertFront(4);
        cout << "l4 after insertion "; l4.print();
        cout << "Is l4 empty? " << l4.empty() << endl;

        l4.deleteFront();
        l4.deleteBack();
        cout << "l4 after half-removal "; l4.print();
        cout << "Is l4 empty? " << l4.empty() << endl;

        l4.insertBack(10);
        l4.insertFront(20);
        l4.insertFront(40);
        l4.insertBack(30);
        cout << "l4 after insertion "; l4.print();
        cout << "Is l4 empty? " << l4.empty() << endl;

        int size = l4.size();
        for (int i = 0; i < 0.5 * (size + 1); i++) {
            l4.deleteFront();
            l4.deleteBack();
        }
        cout << "l4 after full removal "; l4.print();
        cout << "Is l4 empty? " << l4.empty() << endl;
    }

    /* Test 5: Insert After, Remove, Repeat */
    if (tests[5]) {
        SLinkedList l5 = SLinkedList();
        cout << endl << "L5 CREATED" << endl;
        cout << "Is l5 empty? " << l5.empty() << endl;

        l5.insertFront(1);
        l5.insertAfter(10, 1);
        l5.insertAfter(20, 10);
        l5.insertAfter(50, 30);
        cout << "l5 after insertion: "; l5.print();
        cout << "Is l5 empty? " << l5.empty() << endl;

        l5.deleteBack();
        l5.deleteFront();
        l5.deleteFront();
        cout << "l5 after removal "; l5.print();
        cout << "Is l5 empty? " << l5.empty() << endl;

        l5.insertBack(1);
        l5.insertAfter(10, 1);
        l5.insertAfter(50, 30);
        l5.insertAfter(20, 10);
        cout << "l5 after insertion "; l5.print();
        cout << "Is l5 empty? " << l5.empty() << endl;

        l5.deleteFront();
        l5.deleteBack();
        l5.deleteBack();
        cout << "l5 after removal "; l5.print();
        cout << "Is l5 empty? " << l5.empty() << endl;
    }

    /* Test 6: Insert After Alternate with Front, Back */
    if (tests[6]) {
        SLinkedList l6 = SLinkedList();
        cout << endl << "L6 CREATED" << endl;
        cout << "Is l6 empty? " << l6.empty() << endl;

        l6.insertFront(1);
        l6.insertAfter(10, 1);
        l6.insertFront(2);
        l6.insertAfter(20, 2);
        l6.insertBack(3);
        l6.insertAfter(50, 3);
        cout << "l6 after insertion: "; l6.print();
        cout << "Is l6 empty? " << l6.empty() << endl;

        l6.deleteFront();
        l6.deleteBack();
        l6.deleteFront();
        cout << "l6 after half-removal "; l6.print();
        cout << "Is l6 empty? " << l6.empty() << endl;

        l6.insertAfter(100, 10);
        l6.insertFront(200);
        l6.insertBack(300);
        l6.insertAfter(1000, 200);
        cout << "l6 after insertion "; l6.print();
        cout << "Is l6 empty? " << l6.empty() << endl;

        int size = l6.size();
        for (int i = 0; i < 0.5 * (size + 1); i++) {
            l6.deleteFront();
            l6.deleteBack();
        }
        cout << "l6 after full removal "; l6.print();
        cout << "Is l6 empty? " << l6.empty() << endl;
    }

    /* Test 7: Basic Delete in the Middle */
    if (tests[7]) {
        SLinkedList l7 = SLinkedList();
        cout << endl << "L7 CREATED" << endl;
        cout << "Is l7 empty? " << l7.empty() << endl;

        l7.insertFront(1);
        cout << "l7 after insertion "; l7.print();
        cout << "Is l7 empty? " << l7.empty() << endl;

        l7.deleteNode(100);
        cout << "l7 after testing node DNE "; l7.print();
        cout << "Is l7 empty? " << l7.empty() << endl;

        l7.deleteNode(1);
        cout << "l7 after deletion of head "; l7.print();
        cout << "Is l7 empty? " << l7.empty() << endl;

        l7.insertFront(1);
        l7.insertBack(2);
        cout << "l7 after insertion "; l7.print();
        cout << "Is l7 empty? " << l7.empty() << endl;

        l7.deleteNode(100);
        cout << "l7 after testing node DNE "; l7.print();
        cout << "Is l7 empty? " << l7.empty() << endl;

        l7.deleteNode(2);
        l7.deleteNode(1);
        cout << "l7 after deletion of tail, then head "; l7.print();
        cout << "Is l7 empty? " << l7.empty() << endl;
    }

    /* Test 8: Delete in the Middle */
    if (tests[8]) {
        SLinkedList l8 = SLinkedList();
        cout << endl << "L8 CREATED" << endl;
        cout << "Is l8 empty? " << l8.empty() << endl;

        // 3, 2, 1, 2, 4, 6
        for(int i = 1; i < 4; i++) {
            l8.insertFront(i);
            l8.insertBack(2*i);
        }
        cout << "l8 after insertion "; l8.print();
        cout << "Is l8 empty? " << l8.empty() << endl;

        l8.deleteNode(100);
        cout << "l8 after testing a node that DNE "; l8.print();
        cout << "Is l8 empty? " << l8.empty() << endl;

        l8.deleteNode(1);
        cout << "l8 after deletion in the middle "; l8.print();
        cout << "Is l8 empty? " << l8.empty() << endl;

        l8.deleteNode(6);
        cout << "l8 after deletion at the back "; l8.print();
        cout << "Is l8 empty? " << l8.empty() << endl;

        l8.deleteNode(3);
        cout << "l8 after deletion at the front "; l8.print();
        cout << "Is l8 empty? " << l8.empty() << endl;
    }

    /* Test 9: Random Test of insertions and deletions */
    if (tests[9]) {
        SLinkedList l9 = SLinkedList();
        cout << endl << "L9 CREATED" << endl;
        cout << "Is l9 empty? " << l9.empty() << endl;

        l9.insertFront(1);
        l9.insertBack(2);
        l9.insertAfter(3, 2);
        cout << "l9 after first insertions "; l9.print();
        cout << "Is l9 empty? " << l9.empty() << endl;

        l9.deleteNode(4);
        l9.deleteNode(2);
        cout << "l9 after first deletions "; l9.print();
        cout << "Is l9 empty? " << l9.empty() << endl;

        l9.insertFront(1);
        l9.insertBack(2);
        l9.insertAfter(3, 2);
        l9.insertAfter(3, 3);
        cout << "l9 after second insertions "; l9.print();
        cout << "Is l9 empty? " << l9.empty() << endl;

        l9.deleteNode(3);
        l9.deleteNode(3);
        cout << "l9 after second deletions "; l9.print();
        cout << "Is l9 empty? " << l9.empty() << endl;

        // don't delete the entire list to test the destructor
    }

    /* Test 10: Make the list from an array */
    if (tests[10]) {
        int array[7] = {300, 5, 100, 10, 2, 5, 7};

        SLinkedList l10 = SLinkedList();
        cout << endl << "L10 CREATED" << endl;
        cout << "Is l10 empty? " << l10.empty() << endl;

        l10.copyArray(array, 7);
        cout << "l10 after copy "; l10.print();
        cout << "Is l10 empty? " << l10.empty() << endl;

        l10.insertFront(500);
        l10.insertBack(600);
        l10.insertAfter(700, 500);
        l10.insertAfter(800, 500);
        cout << "l10 after some insertions "; l10.print();
        cout << "Is l10 empty? " << l10.empty() << endl;

        l10.deleteNode(100);
        l10.deleteNode(10);
        l10.deleteBack();
        l10.deleteFront();
        cout << "l10 after some deletions "; l10.print();
        cout << "Is l10 empty? " << l10.empty() << endl;
    }

    /* Test 11: Reverse the list */
    if (tests[11]) {
        int array[7] = {300, 5, 100, 10, 2, 5, 7};

        SLinkedList l11 = SLinkedList();
        cout << endl << "L11 CREATED" << endl;
        cout << "Is l11 empty? " << l11.empty() << endl;

        l11.copyArray(array, 7);
        cout << "l11 after copy "; l11.print();
        cout << "Is l11 empty? " << l11.empty() << endl;

        l11.reverse();
        cout << "l11 after reverse "; l11.print();
        cout << "Is l11 empty? " << l11.empty() << endl;

        l11.insertFront(500);
        l11.insertBack(600);
        l11.insertAfter(700, 500);
        l11.insertAfter(800, 500);
        cout << "l10 after some insertions "; l11.print();
        cout << "Is l10 empty? " << l11.empty() << endl;

        l11.deleteNode(100);
        l11.deleteNode(10);
        l11.deleteBack();
        l11.deleteFront();
        cout << "l11 after some deletions "; l11.print();
        cout << "Is l11 empty? " << l11.empty() << endl;
    }
}
