//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> mat, int x, int y) {
        if(mat[0][0]==0)
        return -1;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        
        q.push({{0,0},0});
        vis[0][0]=1;
        
        vector<vector<int>> dx={{-1,0},{0,-1},{1,0},{0,1}};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            
            if(r==x && c==y){
                return t;
            }
            
            for(int i=0;i<4;i++){
                int nr=r+dx[i][0];
                int nc=c+dx[i][1];
                if(nr<n && nc<m && nr>=0 && nc>=0 && mat[nr][nc]==1 &&vis[nr][nc]==0){
                    q.push({{nr,nc},t+1});
                    vis[nr][nc]=2;
                }
            }
        }
        return -1;
    }
    /*
    Time Complexity:O(N*M)
    Auxillary Space:O(N*M)
    */
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends