//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool f(int i, int j, string& wild, string& pat, vector<vector<int>>& dp)
    {
        if(i<0 && j<0) return true;
        if(i<0 || j<0) return false;
        if(dp[i][j] != -1) return dp[i][j];
        
        bool op1=false, op2=false;
        if((wild[i] == pat[j]) || (wild[i] == '?')) {
            op1 = f(i-1, j-1, wild, pat, dp);
        }
        if(wild[i] == '*') {
            op2 = f(i-1, j-1, wild, pat, dp) | f(i,j-1, wild, pat, dp) | f(i-1, j, wild, pat, dp);
        }
        
        return dp[i][j] = (op1 | op2);
    }
    
    bool match(string wild, string pattern)
    {
        // code here
        int n = wild.size(), m=pattern.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, wild, pattern, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends