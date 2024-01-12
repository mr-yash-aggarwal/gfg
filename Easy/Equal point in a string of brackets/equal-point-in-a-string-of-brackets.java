//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main(String[] args) throws IOException
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        while(t-->0)
        {
            String str = br.readLine();
            
            Solution obj = new Solution();
            System.out.println(obj.countSub(str));
            
        }
	}
}


// } Driver Code Ends


//User function Template for Java

class Solution {
    public long countSub(String str) {
        
   
        int o=0,c=0;
        for(int i=0;i<str.length();i++)
        {
            if(str.charAt(i)=='(')
            o++;
            if(str.charAt(i)==')')
            c++;
    }
    int open=0;
    
      for(int i=0;i<str.length();i++)
        {
            if(str.charAt(i)=='(')
            {
            open++;
            }
            else
            {
               c--;
            }
            
            if(open==c)
            return i+1;
    }
    return 0;
    
}
    
}
