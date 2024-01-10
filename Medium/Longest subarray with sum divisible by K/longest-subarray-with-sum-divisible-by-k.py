#User function Template for python3
class Solution:
    def longSubarrWthSumDivByK (self,arr,  n, K) : 
        maxiLen = 0
        preSum = 0
        dist = {}
        for i in range(n):
            preSum += arr[i]
            rem = preSum % K
            if(rem == 0):
                maxiLen = max(maxiLen,i+1)
            if (rem < 0):
                rem += K 
            if(rem in dist):
                maxiLen = max(maxiLen,i - dist[rem])
            else:
                dist[rem] = i 
        return maxiLen


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

	for _ in range(0,int(input())):
		n, K = map(int ,input().split())
		arr = list(map(int,input().strip().split()))
		ob = Solution()
		res = ob.longSubarrWthSumDivByK(arr, n, K)
		print(res)




# } Driver Code Ends