#User function Template for python3

class Solution:
    def findMidSum(self, ar1, ar2, n):
        low = 0
        high = n
        if n == 1:
            return ar1[0] + ar2[0]
        while low <= high:
            mid1 = (low + high) // 2
            mid2 = n - mid1

            l1 = ar1[mid1 - 1] if mid1 > 0 else float('-inf')
            l2 = ar2[mid2 - 1] if mid2 > 0 else float('-inf')
            h2 = ar2[mid2] if mid2 < n else float('inf')
            h1 = ar1[mid1] if mid1 < n else float('inf')

            if l1 <= h2 and l2 <= h1:
                return max(l1, l2) + min(h1, h2)
            elif l1 > h2:
                high = mid1 - 1
            else:
                low = mid1 + 1
        return -1 


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__": 		
    tc=int(input())
    while tc > 0:
        n=int(input())
        ar1=list(map(int, input().strip().split()))
        ar2=list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.findMidSum(ar1, ar2, n)
        print(ans)
        tc=tc-1

# } Driver Code Ends