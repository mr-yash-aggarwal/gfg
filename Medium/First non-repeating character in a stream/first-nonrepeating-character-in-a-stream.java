//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String A = br.readLine().trim();
            Solution ob = new Solution();
            String ans = ob.FirstNonRepeating(A);
            out.println(ans);
        }
        out.close();
    }
}

// } Driver Code Ends


class Solution
{
    public String FirstNonRepeating(String str)
    {
        // code here
        char freq[]= new char[26]; //'z'-'a'=25
        Queue<Character> q= new LinkedList<>();
        StringBuilder sb= new StringBuilder();
        
        //Traverse the string
        for(int i=0;i<str.length();i++){
            
            char ch=str.charAt(i);
            
            q.add(ch);
            freq[ch-'a']++;
            
            
            while(!q.isEmpty() && freq[q.peek()-'a']!=1){
                q.remove();
            }
            if(q.isEmpty()){
                sb.append('#');
            }
            else{
                sb.append(q.peek());
            }
        }
        return sb.toString();
    }
}