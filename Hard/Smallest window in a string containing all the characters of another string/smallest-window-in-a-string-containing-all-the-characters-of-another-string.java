//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		int test = scan.nextInt();
		
		while(test > 0){
		    String s = scan.next();
		    String t = scan.next();
		    
		    System.out.println(new Solution().smallestWindow(s, t));
		    test--;
		}
	}
}
// } Driver Code Ends


class Solution
{
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    public static String smallestWindow(String s, String p){
        if(p.length()>s.length()){
            return "-1";
        }
        int[] count1=new int[256];
        int[] count2=new int[256];
        int[] count3=new int[256];
        int max=0;
        for(int k=0;k<p.length();k++){
            count2[p.charAt(k)]++;
            count3[p.charAt(k)]++;
            max++;
        }
        String res="";
        int min=Integer.MAX_VALUE;
        String curr="-1";
        String test=new String(p);
        int i=0;
        while(i<s.length()+1){
            if(max!=0){
                if(i>=s.length()){
                    break;
                }
                String n=new String(s.charAt(i)+"");
                count1[s.charAt(i)]++;
                if(count2[s.charAt(i)]>0){
                    count2[s.charAt(i)]--;
                    max--;
                }
                res=res+n;
                i++;
            }
            if(max==0){
                if(res.length()==p.length()){
                    return res;
                }
                else if(min>res.length()){
                    min=res.length();
                    curr=res;
                }
                if(count3[res.charAt(0)]==0 || count1[res.charAt(0)]>count3[res.charAt(0)]){   
                    count1[res.charAt(0)]--;
                    res=res.substring(1,res.length());
                }
                else{
                    count1[res.charAt(0)]--;
                    count2[res.charAt(0)]++;
                    res=res.substring(1,res.length());
                    max++;
                }
            }
        }
        return curr;
    }
}