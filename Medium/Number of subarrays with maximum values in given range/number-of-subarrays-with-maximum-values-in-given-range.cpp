//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int arr[], int N, int L, int R)
    {
        long l=0,r=0, cnt1=0, cnt0=0;
        for(; r<N; ++r) {
            if(arr[r] > R) {
                long n = r-l;
                cnt1 += (n*(n+1))/2;
                l = r+1;
            }
        }
    
        if(r > l) {
            long n = r-l;
            cnt1 += (n*(n+1))/2;
        }
        
        // count for atmost L-1
        r=0,l=0;
        while(r < N) {
            if(arr[r] >= L) {
                long n = r-l;
                cnt0 += (n*(n+1))/2;
                l=r+1;
            }
            ++r;
        }
        
        if(r > l) {
            long n = r-l;
            cnt0 += (n*(n+1))/2;
        }
            
        return cnt1-cnt0;
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends