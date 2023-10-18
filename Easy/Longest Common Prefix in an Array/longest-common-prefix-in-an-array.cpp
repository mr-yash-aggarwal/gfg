//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        int mn=INT_MAX;
        string s="";
        for(int i=0;i<N;i++)
        {
            if(arr[i].length()<mn)
            {
                mn=arr[i].length();
                s=arr[i];
            }
            
           
        }
        int m=INT_MAX;
         for(int i=0;i<N;i++)
        {
            
            string g=arr[i];
            
            for(int j=0;j<mn;j++)
            {
                if(g[j]!=s[j])
                {
                    if(m>j-1){
                      m = min(m, j-1);
                    break;}
                }
                
                
            }
          
            if(m<0)
        {
            return "-1";
        }
        }
        if(m<0)
        {
            return "-1";
        }
        if(m==INT_MAX)
        {
            return s;
        }
        string f;
        int i=0;
        while(i<=m)
        {
            f+=s[i];
            i++;
        }
        return f;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends