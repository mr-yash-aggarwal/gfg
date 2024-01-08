//{ Driver Code Starts
import java.util.*;
import java.io.*;

class Node
{
    int data;
    Node next;

    Node(int d)
    {
        data = d;
        next = null;
    }
}


public class MainClass {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t=scanner.nextInt();
        while(t-->0)
        {
            int N = scanner.nextInt();
            int M = scanner.nextInt();

            Node node1 = null;
            Node temp1 = null;
            for (int i = 0; i < N; i++) {
                int value = scanner.nextInt();
                Node newNode = new Node(value);
                if (node1 == null) {
                    node1 = newNode;
                    temp1 = node1;
                } else {
                    temp1.next = newNode;
                    temp1 = temp1.next;
                }
            }
    
            Node node2 = null;
            Node temp2 = null;
            for (int i = 0; i < M; i++) {
                int value = scanner.nextInt();
                Node newNode = new Node(value);
                if (node2 == null) {
                    node2 = newNode;
                    temp2 = node2;
                } else {
                    temp2.next = newNode;
                    temp2 = temp2.next;
                }
            }
    
            GfG gfg = new GfG();
            Node result = gfg.mergeResult(node1, node2);
    
            printList(result);
        }
    }

    static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }
}

// } Driver Code Ends


/* Structure of the node*/
/* class Node
{
	int data;
	Node next;
	
	Node(int d)
	{
		data = d;
		next = null;
	}
} */

class GfG
{
    Node mergeResult(Node node1, Node node2)
    {
	    Node p = node1,q = node2;
	    
	    //if any of node already null or both already null.
	    if(p==null && q==null){
	        return null;
	    }
	    if(p==null){
	        Node ans = reverseLinkedList(q);
	        return ans;
	    }
	    if(q==null){
	        Node ans = reverseLinkedList(p);
	        return ans;
	    }
	    
	    
	    //create a entire LinkedList using marge sort
	    Node temp ;
        if(p.data<q.data){
            temp = new Node(p.data);
            p = p.next;
        }else{
            temp = new Node(q.data);
            q = q.next;
        }
        
        Node start = temp; //pointer to point first position.
        //create LinkedList        
        create_LinkedList_Using_margeSort(p,q,temp);

	    //lets reverse it for the anser. 
	    Node ans = reverseLinkedList(start);
	    return ans;
	    
    }
    public void create_LinkedList_Using_margeSort(Node p,Node q,Node temp){
        while(p!=null && q!=null){
	        if(p.data<q.data){
	            temp.next = new Node(p.data);
	            temp = temp.next;
	            p = p.next;
	        }else{
	            temp.next = new Node(q.data);
	            temp = temp.next;
	            q = q.next;
	        }
	    }
	    while(p!=null){
	        temp.next = new Node(p.data);
	        temp = temp.next;
	        p = p.next;
	    }
	    while(q!=null){
	        temp.next = new Node(q.data);
	        temp = temp.next;
	        q = q.next;
	    }
    }
    
    public static Node reverseLinkedList(Node node){
        Node prev = node;
        Node after = prev.next;
        Node temp = after;
        
        prev.next = null;
        while(temp.next!=null){
            temp = after.next;
            after.next = prev;
            prev = after;
            after = temp;
        }
        temp.next = prev;
        return temp;
    }
}
