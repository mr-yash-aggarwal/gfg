#User function Template for python3

from collections import defaultdict
from itertools import chain

class Solution:
    def repeatedRows(self, arr, m, n):
        D = defaultdict(list)
        
        for index, row in enumerate(arr):
            row_tuple = tuple(row)
            D[row_tuple].append(index) # this is to avoid error unshable type list
        
        return sorted(chain(*[val[1:] for val in D.values() if len(val) > 1]))

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n, m = list(map(int, input().strip().split()))
        
        arr = []
        for i in range(n):
            nums = list(map(int, input().strip().split()))
            arr.append(nums)
        ob = Solution()
        ans = ob.repeatedRows(arr, n, m)
        
        for x in ans:
            print(x, end=" ")
            
        print()
        tc -= 1

# } Driver Code Ends