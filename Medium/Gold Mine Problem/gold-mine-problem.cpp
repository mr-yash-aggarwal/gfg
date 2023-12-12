//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int maxGold(int r, int c, vector<vector<int>> mat){
        // code here
        vector<vector<int>>dp=mat;
        for(int i=1; i<c; i++){
            for(int j=0; j<r; j++){
                int v1=0, v2=0, v3=0;
                if(j-1>=0) v1=dp[j-1][i-1];
                v2=dp[j][i-1];
                if(j+1<r) v3=dp[j+1][i-1];
                dp[j][i]+=max(v1, max(v2, v3));
            }
        }
        int res=INT_MIN;
        for(int i=0; i<r; i++){
            res=max(res, dp[i][c-1]);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends