
#User function Template for python3

class Solution:
    
    #Function to search a given number in row-column sorted matrix.
    def search(self,matrix, n, m, x): 
    	# code here 
    	
    	for i in range(n):
    	    low, high = 0, m-1
        	while(low<=high):
        	    mid = (low+high)//2
        	    if(matrix[i][mid]<x):
        	        low = mid+1
        	    elif(matrix[i][mid]>x):
        	        high = mid-1
        	    else:
        	        return True
    	return False
    	



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	t = int(input())
	for _ in range(t):
		size = input().strip().split()
		r = int(size[0])
		c = int(size[1])
		line = input().strip().split()
		matrix = [ [0 for _ in range(c)] for _ in range(r) ]
		for i in range(r):
			for j in range(c):
				matrix[i][j] = int( line[i*c+j] )
		target = int(input())
		obj = Solution()
		if (obj.search(matrix,r,c,target)): 
			print(1) 
		else: 
			print(0) 


# } Driver Code Ends