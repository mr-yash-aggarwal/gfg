//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class Geeks
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n =sc.nextInt();
            int arr[] = new int[n];
            
            for(int i = 0; i < n; i++)
             arr[i] = sc.nextInt();
             
           System.out.println(new Solution().majorityElement(arr, n)); 
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    static int majorityElement(int a[], int size)
    {
        // your code here
        int n=-1;
        HashMap<Integer , Integer> map = new HashMap<>();
        for(int x: a)
        {
            if(map.isEmpty()|| !map.containsKey(x))
            {
                map.put(x,1);
            }
            else if(map.containsKey(x))
            {
                map.put(x , map.get(x)+1);
            }
        }
        for(Map.Entry <Integer , Integer> e : map.entrySet())
        {
            if(e.getValue() > size/2)
            {
                n=e.getKey();
            }
        }
        return n;
    }
}