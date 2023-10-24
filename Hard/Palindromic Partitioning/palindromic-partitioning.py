#User function Template for python3

class Solution:
    def palindromicPartition(self, string):
        n = len(string)
        cuts = [0] * n
        def is_palindrome(s, start, end):
            while start < end:
                if s[start] != s[end]:
                    return False
                start += 1
                end -= 1
            return True
        for i in range(n):
            min_cuts = i  
            
            for j in range(i, -1, -1):
                if is_palindrome(string, j, i):
                    if j == 0:
                        min_cuts = 0
                    else:
                        min_cuts = min(min_cuts, 1 + cuts[j - 1])
            cuts[i] = min_cuts
        return cuts[n - 1]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range (t):
        string = input()
        
        ob = Solution()
        print(ob.palindromicPartition(string))
# } Driver Code Ends