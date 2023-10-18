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
            int[][] grid = new int[n][n];
            for(int i = 0; i < n; i++){
                String[] S = br.readLine().trim().split(" ");
                for(int j = 0; j < n; j++){
                    grid[i][j] = Integer.parseInt(S[j]);
                }
            }
            Solution obj = new Solution();
            boolean ans = obj.is_Possible(grid);
            if(ans)
                System.out.println("1");
            else 
                System.out.println("0");
        }
    }
}
// } Driver Code Ends



class Solution
{
    //Function to find whether a path exists from the source to destination.
    public boolean is_Possible(int[][] grid)
    {
        int rows = grid.length;
        int cols = grid[0].length;
        
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                
                // if we have found the source
                if (grid[i][j] == 1) return dfs(grid, i, j, rows, cols);
            }
        }
        
        return false;
        
    }
    
    boolean dfs(int[][] grid, int x, int y, int rows, int cols){
        boolean outside = x < 0 || x >= rows || y < 0 || y >= cols;
        if (outside || grid[x][y] == 0) return false;
        
        // we have found the ending
        if (grid[x][y] == 2) return true;
        grid[x][y] = 0;
        int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for (int [] dir: directions){
            int xdx = x + dir[0];
            int ydy = y + dir[1];
            
            boolean pathFound = dfs(grid, xdx, ydy, rows, cols);
            if (pathFound) return true;
            
        }
        
        return false;
    }
}