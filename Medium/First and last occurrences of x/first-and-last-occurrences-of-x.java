//{ Driver Code Starts
//Initial Template for Java



import java.io.*;
import java.util.*;


// } Driver Code Ends
//User function Template for Java


class GFG
{
    ArrayList<Integer> find(int arr[], int n, int x)
    {
        // code here
        int low=0;
        int high=n-1;
        int mid=0;
        int[] a=new int[2];
        a[0]=-1;
        a[1]=-1;
        ArrayList<Integer> ans=new ArrayList<Integer>();
        while(low<=high){
            mid=(low+high)/2;
            if(arr[mid]>x){
                high=mid-1;
            }
            else if(arr[mid]==x){
                int lowp=mid;
                int highp=mid;
                while(lowp!=-1&&arr[lowp]==x){
                    lowp--;
                }
                while(highp!=n&&arr[highp]==x){
                    highp++;
                }
                a[0]=lowp+1;
                a[1]=highp-1;
                break;
            }
            else {
                low=mid+1;
            }
        }
        ans.add(a[0]);
        ans.add(a[1]);
        return ans;
    }
}



//{ Driver Code Starts.

// Driver class
class Array {

    // Driver code
    public static void main(String[] args) throws IOException {
        // Taking input using buffered reader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int testcases = Integer.parseInt(br.readLine());
        // looping through all testcases
        while (testcases-- > 0) {
//            int n = Integer.parseInt(br.readLine());
            String line = br.readLine();
            String[] q = line.trim().split("\\s+");
            int n =Integer.parseInt(q[0]);
            int x =Integer.parseInt(q[1]);
//            //int y =Integer.parseInt(q[2]);
            String line1 = br.readLine();
            String[] a1 = line1.trim().split("\\s+");
            int arr[] = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(a1[i]);
            }
            GFG ob = new GFG();
            ArrayList<Integer> ans=ob.find(arr,n,x);
            System.out.println(ans.get(0)+" "+ans.get(1));
        }
    }
}

// } Driver Code Ends