
# Linked List Overview

A **linked list** is a linear data structure where each element (node) contains a data part and a reference (or pointer) to the next node in the sequence. Linked lists are dynamic, meaning they can grow and shrink in size during runtime, unlike arrays that have a fixed size.

### Use Cases of Linked Lists:
- **Dynamic memory allocation**: Efficient when memory needs to be dynamically allocated at runtime.
- **Implementation of stacks, queues, and graphs**.
- **Efficient insertion and deletion**: Insertion and deletion of nodes are faster as no shifting is required (unlike arrays).

---

## Linked List Creation in C++ and Java

### C++ (using `struct`)
```cpp
#include <iostream>
using namespace std;

// Define a node structure
struct Node {
    int data;        // Data of the node
    Node* next;      // Pointer to the next node
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to traverse the linked list
void traverse(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
```

### Java (using `class`)
```java
public class LinkedList {
    // Node class definition
    static class Node {
        int data;
        Node next;

        // Constructor to create a new node
        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // Function to traverse the linked list
    public static void traverse(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}
```

---

## Memory Space Considerations
Each node in a linked list requires memory for storing:
1. **Data**: The actual value of the node (e.g., an integer).
2. **Pointer/Reference**: The pointer to the next node in C++ or reference to the next object in Java.

Linked lists usually have more memory overhead than arrays because of the extra space used by the pointers.

---

## Converting an Array to Linked List (C++ and Java)

### C++ Code
```cpp
Node* arrayToLinkedList(int arr[], int size) {
    if (size == 0) return nullptr;

    Node* head = createNode(arr[0]);
    Node* current = head;

    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }

    return head;
}
```

### Java Code
```java
public static Node arrayToLinkedList(int[] arr) {
    if (arr.length == 0) return null;

    Node head = new Node(arr[0]);
    Node current = head;

    for (int i = 1; i < arr.length; i++) {
        current.next = new Node(arr[i]);
        current = current.next;
    }

    return head;
}
```

---

## Traversing a Linked List

Traversal means visiting each node of the linked list. We usually start from the head node and move to the next node until the end.

### C++ Code
```cpp
void traverse(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
```

### Java Code
```java
public static void traverse(Node head) {
    Node temp = head;
    while (temp != null) {
        System.out.print(temp.data + " ");
        temp = temp.next;
    }
    System.out.println();
}
```

---

## Searching in a Linked List

To search for a particular element in a linked list, we can traverse through each node and compare its data with the target.

### C++ Code
```cpp
bool search(Node* head, int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}
```

### Java Code
```java
public static boolean search(Node head, int key) {
    Node temp = head;
    while (temp != null) {
        if (temp.data == key) return true;
        temp = temp.next;
    }
    return false;
}
```
