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
    
}

// Remove Head Node
Node* removeHead(Node *head){
    if(head == NULL) return NULL;
    Node *temp = head->next;
    delete head;
    return temp;
}

// Remove Tail Node
Node* removeTail(Node *head){
    if(head == NULL || head->next == NULL) return NULL;
    Node*temp = head;
    while(temp->next->next){
        temp=temp->next;
    }
    delete(temp->next);
    temp->next = NULL;
    return head;
}
// Remove Kth Node from head

Node* removeKthNode(Node *head, int k){
    if(head==NULL)return head;
    if(k==1){
        Node*temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    Node*temp=head, *prev=nullptr;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        if(cnt==k){
            prev->next = prev->next->next;
            delete(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
Node* removeelem(Node *head, int elem){
    if(head==NULL)return head;
    if(head->data==elem){
        Node*temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    Node*temp=head, *prev=nullptr;
    while (temp)
    {
        if(temp->data == elem){
            prev->next = prev->next->next;
            delete(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
// Insert At head 
Node* insertAtHead(Node *head, int data){
    Node *newNode = new Node(data);
    newNode->next = head;
    return newNode;
}

// Insert At Tail
Node* insertAtTail(Node *head, int data){
    Node *temp = head;
    while(temp->next !=nullptr){
        temp= temp->next;
    }
    temp->next = new Node(data);
    return head;
}

// Insert At Kth Node
Node* insertAtKthNode(Node *head, int data, int k){
    if(head==NULL)return head;
    if(k==1){
        Node *newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }
    Node *temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        if(cnt==k-1){
            Node *newNode = new Node(data);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}
// Insert Before Value 
Node* insertBeforeVal(Node *head, int data, int val){
    if(head==NULL)return head;
    if(head->data==val){
        Node *newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }
    Node *temp = head;
    // Node *prev = nullptr;
    while (temp)
    {
        if(temp->next->data==val){
            Node *newNode = new Node(data);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}
int main(){

    int arr[] = {10,20,30,40,50};
    Node *head = arrayToLinkedList(arr,5);
    printLinkedList(head);
    // cout<<"Length of Linked List: "<<lenngthLL(head)<<endl;
    // if(search(head, 300)==1) cout<<"Found"<<endl;
    // else cout<<"Not Found"<<endl;

    head = removeHead(head);
    printLinkedList(head);

    head = removeTail(head);
    printLinkedList(head);

    head = removeKthNode(head, 3);
    printLinkedList(head);

    head = removeelem(head, 30);
    printLinkedList(head);


    head = insertAtHead(head, 100);
    printLinkedList(head);

    head = insertAtHead(head, 60);
    head = insertAtTail(head, 200);
    printLinkedList(head);

    head = insertAtKthNode(head, 400, 8);
    printLinkedList(head);

    head = insertBeforeVal(head, 300, 200);
    printLinkedList(head);
    return 0;
}