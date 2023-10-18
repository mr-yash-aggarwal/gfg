//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    vector<int>v(256, -1);
    int l = 0, r = 0, n = s.length(), ans = INT_MIN;
    while(r < n){
        if(v[s[r]] != -1) l = max(l, v[s[r]]+1);
        ans = max(ans, r-l+1);
        v[s[r]] = r;
        r++;
    }
    return ans;
   // your code here
}