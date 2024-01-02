//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:    
    #define ll long long int
    ll st[400001] ; 
    void build(ll node, ll low, ll high,ll arr[]) {
        if(low==high) {
            st[node]=arr[low] ; 
            return ; 
        }
        ll mid=(low+high)/2; 
        build(2*node, low, mid, arr); 
        build(2*node+1,mid+1,high,arr)  ; 
        st[node]=min(st[2*node],st[2*node+1]) ; 
    }
    ll rangequery(ll node, ll low, ll high, ll l, ll r) {
        if(l>high or r<low) return 1e12;
        if(low>=l and high<=r) {
            return st[node] ; 
        }
        ll mid=(low+high)/2; 
        ll lst=rangequery(2*node, low, mid, l, r) ; 
        ll rst=rangequery(2*node+1, mid+1, high, l, r) ;
        return min(lst, rst) ; 
    }
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        for(ll i=1; i<n; i++) a[i]+=a[i-1] ; 
        build(1,0,n-1,a) ; 
        ll res=a[k-1] ; 
        for(ll i=k; i<n; i++) {
           res=max(res, a[i]) ; 
           ll l=0; 
           ll r=i-k; 
           ll cur=rangequery(1,0,n-1,l,r) ; 
           res=max(res, a[i]-cur) ; 
        }
        return res; 
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends