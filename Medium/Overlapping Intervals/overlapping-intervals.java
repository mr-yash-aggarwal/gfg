//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            String[] s = br.readLine().trim().split(" ");
            int[][] Intervals = new int[n][2];
            int j = 0;
            for(int i = 0; i < n; i++){
                Intervals[i][0] = Integer.parseInt(s[j]);
                j++;
                Intervals[i][1] = Integer.parseInt(s[j]);
                j++;
            }
            Solution obj = new Solution();
            int[][] ans = obj.overlappedInterval(Intervals);
            for(int i = 0; i < ans.length; i++){
                for(j = 0; j < ans[i].length; j++){
                    System.out.print(ans[i][j] + " ");
                }
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends


class Solution
{
    public int[][] overlappedInterval(int[][] arr)
    {
        // Code here // Code here
        ArrayList<int[]> l=new ArrayList<>();
        Arrays.sort(arr,(a,b)->a[0]-b[0]);
        int start = arr[0][0];
        int end= arr[0][1];
        for(int[] i:arr){
            if(end>=i[0]){
                end=Math.max(end,i[1]);
            }
            else{
                l.add(new int[]{start,end});
                start=i[0];
                end=i[1];
            }
        }
        l.add(new int[]{start,end});
        return l.toArray(new int[0][]);
        
    }

}