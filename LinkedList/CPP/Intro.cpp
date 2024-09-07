#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Array to Linked list 
Node* arrayToLinkedList(int arr[], int size){
    if(size == 0) return NULL;

    Node *head = new Node(arr[0]);
    Node *current = head;
    for(int i = 1; i < size; i++){
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}
// Traversing a Linked List
void printLinkedList(Node *head){  
    cout<<"Linked List: "<<endl; 
    Node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}
// Length of Linked List
int lenngthLL(Node *head){
    int len = 0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}

// Searching of Linked List
bool search(Node *head, int key){
   Node *temp=head;
    while(temp){
        if(temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}
int main(){

    /*
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->next = temp2;
    */

    int arr[] = {10,20,30,40,50};

    Node *head = arrayToLinkedList(arr,5);

    printLinkedList(head);

    cout<<"Length of Linked List: "<<lenngthLL(head)<<endl;

    if(search(head, 300)==1) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;




    return 0;
}