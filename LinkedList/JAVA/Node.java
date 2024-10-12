
// public class Intro {
public class Node {
        int data;
        Node next;

        // Constructor to create a new node
        Node(int data) {
            this.data = data;
            this.next = null;
        }

    // Convert Array to Linked List
     static Node arrayToLinkedList(int[] arr) {
        if (arr.length == 0) return null;

        Node head = new Node(arr[0]);
        Node current = head;

        for (int i = 1; i < arr.length; i++) {
            current.next = new Node(arr[i]);
            current = current.next;
        }
        return head;
    }

    // Print Linked List
     static void printLinkedList(Node head) {
        System.out.println("Linked List: ");
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    // Get Length of Linked List
     static int lengthLL(Node head) {
        int length = 0;
        while (head != null) {
            length++;
            head = head.next;
        }
        return length;
    }

    // Search in Linked List
    public static boolean search(Node head, int key) {
        Node temp = head;
        while (temp != null) {
            if (temp.data == key) return true;
            temp = temp.next;
        }
        return false;
    }
    // Remove Head Node
    static Node removeHead(Node head){
    if(head == null) return null;
    Node temp = head.next;
   
    return temp;
}

// Remove Tail Node
static Node removeTail(Node head){
    if(head == null || head.next == null) return null;
    Node temp = head;
    while(temp.next.next!=null){
        temp=temp.next;
    }
    temp.next = null;
    return head;
}
// Remove Kth Node from head

static Node  removeKthNode(Node head, int k){
    if(head==null)return head;
    if(k==1){
        head=head.next;
        return head;
    }
    Node temp=head, prev=null;
    int cnt = 0;
    while (temp!=null)
    {
        cnt++;
        if(cnt==k){
            prev.next = prev.next.next;
            break;
        }
        prev=temp;
        temp=temp.next;
    }
    return head;
}

    public static void main(String[] args) {

        // Sample array
        int[] arr = {10, 20, 30, 40, 50};

        // Convert array to linked list
        Node head = arrayToLinkedList(arr);

        // Print the linked list
        printLinkedList(head);

        // Get the length of the linked list
        System.out.println("Length of Linked List: " + lengthLL(head));

        // Search for an element
        if (search(head, 300)) {
            System.out.println("Found");
        } else {
            System.out.println("Not Found");
        }
        System.out.println("Removed Head");
        head = removeHead(head);
    printLinkedList(head);

    System.out.println("Removed Tail");
    head = removeTail(head);
    printLinkedList(head);
    System.out.println("Removed Kth Node"); 
    head = removeKthNode(head, 3);
    printLinkedList(head);
    }
}
