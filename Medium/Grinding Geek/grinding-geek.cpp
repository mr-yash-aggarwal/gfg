//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int t[1001][1001];
    int solve(int i,int total , vector<int>&costs){
             if(i==costs.size()){
                return 0;
             }
             if(t[i][total] !=-1) return t[i][total];
             int nottake = solve(i+1,total,costs);
             int take=INT_MIN;
             if(total>=costs[i]) take = 1+solve(i+1,total-costs[i]+floor((costs[i]*90)/100),costs);
             
             return t[i][total]=max(take,nottake);
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
             memset(t,-1,sizeof(t));
             return solve(0,total,cost);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends