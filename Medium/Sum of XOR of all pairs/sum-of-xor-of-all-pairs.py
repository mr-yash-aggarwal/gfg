#User function Template for python3

class Solution:
    def sumXOR (self, a, n) : 
        sum1 = 0
        for i in range(0,32):
            no_O = 0
            no_Z = 0
            for j in a:
                if (j & (1 << i)):
                    no_O += 1
                else:
                    no_Z += 1
            sum1 = sum1 + (no_O * no_Z) * (1 << i)
        return sum1
    



#{ 
 # Driver Code Starts
#Initial Template for Python 3



for _ in range(0,int(input())):
    
    n = int(input())
    arr = list(map(int,input().strip().split()))
    ob = Solution()
    res = ob.sumXOR(arr, n)
    print(res)


# } Driver Code Ends