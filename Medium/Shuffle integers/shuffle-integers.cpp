//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    private:
    int maxi(int arr[], int n){
        int _maxi = INT_MIN;
        for(int i=0;i<n;i++){
            _maxi = max(_maxi, arr[i]);
        }
        return _maxi+1;
    }
    public:
    void shuffleArray(int arr[],int n)
    {
        int i = 0, j = (n)/2;
        int mod = maxi(arr,n);
       
        for(int k=0;k<n;k++)
        {
            if(k%2 == 0){
                arr[k] = arr[k] + (arr[i]%mod)*mod;
                i++;
            }
            else{
                arr[k] = arr[k] + (arr[j]%mod)*mod;
                j++;
            }
        }
        for(int i=0;i<n;i++)
        {
            arr[i] = arr[i] / mod;
        }
    }
};

//{ Driver Code Starts.


int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends