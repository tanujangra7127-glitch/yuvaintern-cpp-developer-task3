
#include <iostream>
#include <cstddef>

using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;

        Node(int value)
            : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t count;

public:
    DoublyLinkedList()
        : head(nullptr), tail(nullptr), count(0) {}

    // Prevent unsafe copying of raw pointers
    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

    ~DoublyLinkedList() {
        clear();
    }

    bool empty() const {
        return head == nullptr;
    }

    size_t size() const {
        return count;
    }

    // Insert at the beginning
    void pushFront(int value) {
        Node* node = new Node(value);
        node->next = head;

        if (head != nullptr)
            head->prev = node;
        else
            tail = node;

        head = node;
        ++count;
    }

    // Insert at the end
    void pushBack(int value) {
        Node* node = new Node(value);
        node->prev = tail;

        if (tail != nullptr)
            tail->next = node;
        else
            head = node;

        tail = node;
        ++count;
    }

    // Insert at a specific index
    bool insertAt(size_t index, int value) {
        if (index > count)
            return false;

        if (index == 0) {
            pushFront(value);
            return true;
        }

        if (index == count) {
            pushBack(value);
            return true;
        }

        Node* current = head;

        for (size_t i = 0; i < index; ++i)
            current = current->next;

        Node* node = new Node(value);
        node->prev = current->prev;
        node->next = current;

        current->prev->next = node;
        current->prev = node;

        ++count;
        return true;
    }

    // Delete the first matching value
    bool removeValue(int value) {
        Node* current = head;

        while (current != nullptr &&
               current->data != value) {
            current = current->next;
        }

        if (current == nullptr)
            return false;

        if (current->prev != nullptr)
            current->prev->next = current->next;
        else
            head = current->next;

        if (current->next != nullptr)
            current->next->prev = current->prev;
        else
            tail = current->prev;

        delete current;
        --count;
        return true;
    }

    // Search and return index, or -1
    int search(int value) const {
        Node* current = head;
        int index = 0;

        while (current != nullptr) {
            if (current->data == value)
                return index;

            current = current->next;
            ++index;
        }

        return -1;
    }

    // Sort values in ascending order
    void sortAscending() {
        if (count < 2)
            return;

        for (Node* current = head->next;
             current != nullptr;
             current = current->next) {

            Node* scan = current;

            while (scan->prev != nullptr &&
                   scan->prev->data > scan->data) {
                int temp = scan->data;
                scan->data = scan->prev->data;
                scan->prev->data = temp;

                scan = scan->prev;
            }
        }
    }

    // Display from head to tail
    void displayForward() const {
        Node* current = head;
        cout << "Forward: ";

        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr)
                cout << " <-> ";

            current = current->next;
        }

        cout << '\n';
    }

    // Display from tail to head
    void displayBackward() const {
        Node* current = tail;
        cout << "Backward: ";

        while (current != nullptr) {
            cout << current->data;
            if (current->prev != nullptr)
                cout << " <-> ";

            current = current->prev;
        }

        cout << '\n';
    }

    // Release all allocated nodes
    void clear() {
        Node* current = head;

        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = nullptr;
        tail = nullptr;
        count = 0;
    }
};

int main() {
    DoublyLinkedList list;

    cout << "Week 3: Advanced Data Structures\n\n";

    // Insertion tests
    list.pushBack(30);
    list.pushBack(10);
    list.pushFront(40);
    list.insertAt(1, 20);

    list.displayForward();
    list.displayBackward();

    cout << "Size: " << list.size() << '\n';

    // Search test
    int target = 10;
    int position = list.search(target);

    if (position != -1)
        cout << target << " found at index "
             << position << '\n';
    else
        cout << target << " not found\n";

    // Sorting test
    cout << "\nSorting...\n";
    list.sortAscending();
    list.displayForward();

    // Deletion test
    cout << "\nRemoving 20...\n";

    if (list.removeValue(20))
        cout << "Value removed successfully\n";
    else
        cout << "Value not found\n";

    list.displayForward();

    // Invalid deletion test
    cout << "\nRemoving 99...\n";
    if (!list.removeValue(99))
        cout << "99 was not found\n";

    // Clear test
    list.clear();

    cout << "\nList cleared\n";
    cout << "Empty: "
         << (list.empty() ? "Yes" : "No") << '\n';
    cout << "Final size: " << list.size() << '\n';

    return 0;
}
