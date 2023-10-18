//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;
        int prev=mp.begin()->first;
        int count=1,max_len=0;
        for(auto i=++mp.begin();i!=mp.end();i++){
             int curr=i->first;
             if(curr-1==prev) {
                 count++;
             }
             else {
                 max_len=max(max_len,count);
                 
                 count=1;
             }
             max_len=max(max_len,count);
             prev=curr;
        }
        max_len=max(max_len,count);
        return max_len;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends