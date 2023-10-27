#User function Template for python3

class Solution:
    def minimumNumberOfDeletions(self,S):
        n = len(S)
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        new = S[::-1]
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if S[i - 1] == new[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])
        return len(S) - dp[n][n]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        
        S=input()

        ob = Solution()
        print(ob.minimumNumberOfDeletions(S))
# } Driver Code Ends