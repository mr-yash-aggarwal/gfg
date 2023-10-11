//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Node  
{ 
    int data; 
    Node left, right; 
   
    public Node(int d)  
    { 
        data = d; 
        left = right = null; 
    } 
}

class GFG
{
    static Node buildTree(String str)
    {
        // Corner Case
        if(str.length() == 0 || str.equals('N'))
            return null;
        String[] s = str.split(" ");
        
        Node root = new Node(Integer.parseInt(s[0]));
        Queue <Node> q = new LinkedList<Node>();
        q.add(root);
        
        // Starting from the second element
        int i = 1;
        while(!q.isEmpty() && i < s.length)
        {
              // Get and remove the front of the queue
              Node currNode = q.remove();
        
              // Get the current node's value from the string
              String currVal = s[i];
        
              // If the left child is not null
              if(!currVal.equals("N")) 
              {
        
                  // Create the left child for the current node
                  currNode.left = new Node(Integer.parseInt(currVal));
        
                  // Push it to the queue
                  q.add(currNode.left);
              }
        
              // For the right child
              i++;
              if(i >= s.length)
                  break;
              currVal = s[i];
        
              // If the right child is not null
              if(!currVal.equals("N")) 
              {
        
                  // Create the right child for the current node
                  currNode.right = new Node(Integer.parseInt(currVal));
        
                  // Push it to the queue
                  q.add(currNode.right);
              }
              
              i++;
        }
    
        return root;
    }
    
    public static void main(String args[]) throws IOException {
    
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while(t>0)
        {
            String s = br.readLine();
            Node root = buildTree(s);
            
            Solution T = new Solution();
            
            ArrayList <Integer> res = T.boundary(root);
            for (Integer num : res) System.out.print (num + " ");
            System.out.println();
            t--;
        }
    }
}

// } Driver Code Ends


//User function Template for Java

// class Node  
// { 
//     int data; 
//     Node left, right; 
   
//     public Node(int d)  
//     { 
//         data = d; 
//         left = right = null; 
//     } 
// }

class Solution
{
    //Checking if the node is a leaf or not
    boolean isLeaf(Node root){
        return root.left==null && root.right==null;
    }
    //function to add leaf nodes at the bottom from left to right
    void addBoundary(Node root,ArrayList<Integer> ans){
        if(isLeaf(root)){
            ans.add(root.data);
            return;
        }
        if(root.left!=null) addBoundary(root.left,ans);
        if(root.right!=null) addBoundary(root.right,ans);
    }
    //function that adds the left boundary while avoiding leaf nodes
    void addLeftBoundary(Node root,ArrayList<Integer> ans){
        Node curr=root.left;
        while(curr!=null){
            if(!isLeaf(curr)) ans.add(curr.data);
            if(curr.left!=null) curr=curr.left;
            else curr=curr.right;
        }
    }
    //function to add right boundary in reverse 
    void addRightBoundary(Node root,ArrayList<Integer> ans){
        Node curr=root.right;
        ArrayList<Integer> dummy=new ArrayList<>();
        while(curr!=null){
            if(!isLeaf(curr)) dummy.add(curr.data);
            if(curr.right!=null) curr=curr.right;
            else curr=curr.left;
        }
        for(int i=dummy.size()-1;i>=0;i--) ans.add(dummy.get(i));
    }
    //inorder traversal: So we are first adding the root node along with the left boundary part excluding the leaves at the bottom
	//In the next step we are adding the bottom leaves from left to right
	//finally we are reversing and adding the right boundary excluding the root node
	ArrayList <Integer> boundary(Node node)
	{
	 ArrayList<Integer> ans=new ArrayList<>();
	 if(!isLeaf(node)) ans.add(node.data);
	 if(node==null) return ans;
	 addLeftBoundary(node,ans);
	 addBoundary(node,ans);
	 addRightBoundary(node,ans);
	 return ans;
	}
}