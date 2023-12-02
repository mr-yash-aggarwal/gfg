#User function Template for python3

class Solution:
    def isRepresentingBST(self, arr, N):
        for i in range(N):
            if arr[i]==arr[-1]:
                break
            if arr[i]>arr[i+1]:
                return 0
        return 1

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range (t):
        N = int(input())
        arr = input().split()
        for itr in range(N):
            arr[itr] = int(arr[itr])
        
        ob = Solution()
        print(ob.isRepresentingBST(arr, N))
# } Driver Code Ends