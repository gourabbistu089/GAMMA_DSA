
class Node {
    int data;
    Node next;
    Node prev;

    Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }

    Node(int data, Node next, Node prev) {
        this.data = data;
        this.next = next;
        this.prev = prev;
    }

}

public class DoublyLL {
    private static void printList(Node head) {
        System.out.println("Linked List: ");
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }
    private static void printListReverse(Node head) {
        System.out.println("Linked List in reverse: ");
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.prev;
        }
    }

    private static Node arrayToDLL(int[] arr) {
        if (arr.length == 0)
            return null;

        Node head = new Node(arr[0]);
        Node current = head;

        for (int i = 1; i < arr.length; i++) {
            current.next = new Node(arr[i]);
            current.next.prev = current;
            current = current.next;
        }
        return head;
    }
    private static Node deleteFirstNode(Node head){
        if(head == null) return null;
        if(head.next == null){
            return null;
        }
    
        Node temp = head;
        head = head.next;
        head.prev = null;
        temp.next = null;
        return head;
    }

    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4, 5 };

        Node head = arrayToDLL(arr);
        printList(head);
        System.out.println();
        // printListReverse(head);
        Node newHead = deleteFirstNode(head);
        printList(newHead);
    }

}