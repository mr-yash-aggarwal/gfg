#User function Template for python3

class Solution:
    def countWays(self, N, S):
        # code here
        dp=[[[0,0] for i in range(N)] for j in range(N)]
        for i in range(0,N,2):
            if S[i]=='T':
                dp[i][i][1]=1
            else:
                dp[i][i][0]=1
        for l in range(3,N+1,2):
            for i in range(0,N-l+1,2):
                j=i+l-1
                t=(l-1)//2
                for k in range(1,t+1):
                    k2=2*k
                    if (S[i+k2-1]=='&'):
                        dp[i][j][1]+=dp[i][i+k2-2][1]*dp[i+k2][j][1]
                        dp[i][j][0]+=dp[i][i+k2-2][1]*dp[i+k2][j][0]+dp[i][i+k2-2][0]*dp[i+k2][j][1]+dp[i][i+k2-2][0]*dp[i+k2][j][0]
                    elif(S[i+k2-1]=='|'):
                        dp[i][j][0]+=dp[i][i+k2-2][0]*dp[i+k2][j][0]
                        dp[i][j][1]+=dp[i][i+k2-2][0]*dp[i+k2][j][1]+dp[i][i+k2-2][1]*dp[i+k2][j][0]+dp[i][i+k2-2][1]*dp[i+k2][j][1]
                    else:
                        dp[i][j][0]+=dp[i][i+k2-2][0]*dp[i+k2][j][0]+dp[i][i+k2-2][1]*dp[i+k2][j][1]
                        dp[i][j][1]+=dp[i][i+k2-2][1]*dp[i+k2][j][0]+dp[i][i+k2-2][0]*dp[i+k2][j][1]
        return dp[0][N-1][1]%1003

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(10**6)

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        S = input()
        
        ob = Solution()
        print(ob.countWays(N, S))
# } Driver Code Ends