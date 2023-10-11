//{ Driver Code Starts
import java.io.*;
import java.util.*;

  public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
        while (tc-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] arr = new int[n];
            String[] inputLine = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            System.out.println(new Solution().maxProduct(arr, n));
        }
    }
}

// } Driver Code Ends


class Solution {
    // Function to find maximum product subarray
    long maxProduct(int[] arr, int n) {
        
        
        long ans=arr[0];
        long ma=ans;
        long mi=ans;
        
        
        for(int i=1;i<n;i++)
        {
            if(arr[i]<0)
            {
                long temp=ma;
                ma=mi;
                mi=temp;
            }
            ma=Math.max(arr[i],ma*arr[i]);
            mi=Math.min(arr[i],mi*arr[i]);
            ans=Math.max(ans,ma);
        }
        return ans;
    }
}