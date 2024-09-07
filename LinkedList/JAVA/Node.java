
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
    }
}
