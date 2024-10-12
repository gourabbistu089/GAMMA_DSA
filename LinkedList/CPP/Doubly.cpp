#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

// Array to Linked list
Node *arrayToLinkedList(int arr[], int size)
{
    if (size == 0)
        return NULL;

    Node *head = new Node(arr[0]);
    Node *back = head;
    for (int i = 1; i < size; i++)
    {
        back->next = new Node(arr[i], nullptr, back);
        back = back->next;
    }
    return head;
}
void printLinkedList(Node *head)
{
    cout << "Linked List: " << endl;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void printReverseLinkedList(Node *head)
{
    cout << "Reverse Linked List: " << endl;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}
// Delete first node'
Node *deleteFirstNode(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
    return head;
}
// Delete the last node
Node *deleteLastNode(Node *head)
{
    cout << "Delete Last Node" << endl;
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *back = temp->prev;
    temp->prev = NULL;
    back->next = NULL;
    delete temp;
    return head;
}

// Delete the kth node
Node *deleteKthNode(Node *head, int k)
{
    cout << "Delete "<< k<<"th Node" << endl;
    if (head == NULL)
        return head;
    Node *temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        if (cnt == k)break;
        temp = temp->next;
    }
    // Reached kth node
    Node *back = temp->prev;
    Node* front = temp->next;

    // Single element
    if (back == NULL && front == NULL)
    {
        delete temp;
        return NULL;
    }
    // Two elements
    if (back == NULL)
    {
        return deleteFirstNode(head);
    }
    if (front == NULL)
    {
        return deleteLastNode(head);
    }
    // more node 
    back->next = front;
    front->prev = back;
    temp->next = NULL;
    temp->prev = NULL;
    delete temp;
    return head;
}
// Delete node of given value
void *deleteNode(Node *temp){
    cout<<"Delete Node"<<temp->data<<endl;
    Node*back = temp->prev;
    Node*front = temp->next;
    if(front->next == NULL){    
        back->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    back->next = front;
    front->prev = back;
    temp->next = NULL;
    temp->prev = NULL;
    delete temp;
}
// Insert At Head
Node *insertAtHead(Node *head, int data){
    cout<<"Insert At Head"<<data<<endl;
    Node *newNode = new Node(data, head, NULL);
    head->prev = newNode;
    return newNode;
}
// Insert At Before tail
Node *insertBeforeTail(Node *head, int data){
    cout<<"Insert At Tail"<<data<<endl;
    if(head->next == NULL){ 
        return insertAtHead(head, data);
    }
    Node *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* back = tail->prev;
    Node *newNode = new Node(data, tail, back);
    back->next = newNode;
    tail->prev = newNode;
    return head;
}
// Insert a Tail
Node *insertTail(Node *head, int data){
    cout<<"Insert At Tail"<<data<<endl;
    if(head == NULL){ 
       return new Node(data);
    }
    Node *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node *newNode = new Node(data, nullptr, tail);
    tail->next = newNode;
    return head;
}
Node* insertBeforeKthNode(Node *head, int data, int k){
    cout<<"Insert Before "<<k<<"th Node"<<data<<endl;
    if(k==1) return insertAtHead(head, data);
    Node *temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        if(cnt==k){
            break;
        }
        temp = temp->next;
    }
    Node *back = temp->prev;
    Node *newNode = new Node(data, temp, back);
    back->next = newNode;
    temp->prev = newNode;
    return head;
}
// Insert before given node 
void insertBeforeGivenNode(int data, Node *givenNode){
    cout<<"Insert Before "<<givenNode->data<<endl;
    Node *back = givenNode->prev;
    Node *newNode = new Node(data, givenNode, back);    // newNode->next = givenNode);
    givenNode->prev = newNode;
    back->next = newNode;
}
    int main()
    {
        int arr[] = {10, 20, 30, 40, 50};
        Node *head = arrayToLinkedList(arr, 5);
        printLinkedList(head);
        // printReverseLinkedList(head);
        // Node *newHead = deleteFirstNode(head);
        // printLinkedList(newHead);
        // newHead = deleteLastNode(newHead);
        // printLinkedList(newHead);
        // Node *newHead = deleteKthNode(head, 0);
        // printLinkedList(newHead);
        // deleteNode(head);
        // printLinkedList(head);
        // head = insertAtHead(head, 60);
        // printLinkedList(head);
        //     head = insertBeforeTail(head, 610);
        // printLinkedList(head);

        // head = insertBeforeKthNode(head, 80, 5);
        // printLinkedList(head);
        // insertBeforeGivenNode(30, head->next);
        // printLinkedList(head) ;
        head = insertTail(head, 160);
        printLinkedList(head);
        return 0;

    }