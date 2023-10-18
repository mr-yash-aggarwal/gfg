//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])throws IOException
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    String A = sc.next();
                    String B = sc.next();
                    Solution ob = new Solution();
                    System.out.println(ob.UncommonChars(A, B));
                }
        }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    String UncommonChars(String A, String B)
    {
        // code here
        char s[]=A.toCharArray();
        char t[]=B.toCharArray();
        Set<Character> k=new TreeSet<Character>();
        Set<Character> p=new TreeSet<Character>();
        for(int i=0;i<A.length();i++){
            k.add(new Character(s[i]));
        }
        for(int i=0;i<B.length();i++){
            p.add(new Character(t[i]));
        }
        Set<Character> i=new TreeSet<Character>(k); 
        k.addAll(p);
        p.retainAll(i);
        k.removeAll(p);
        String q="";
       for (Character character : k) {
            q+=character;
        }
        if(!k.isEmpty())
        return q;
        return "-1";
    }
    
}