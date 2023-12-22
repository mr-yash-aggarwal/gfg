//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int n,vector<int> &s,vector<int> &f){
        vector<int>ans;
        priority_queue<int,vector<pair<int,int>>,greater<pair<int,int>>>v;
        for(int i=0;i<n;i++){
            v.push({f[i],i});
        }
        int d=v.top().first;
        ans.push_back(v.top().second+1);
        v.pop();
        while(!v.empty()){
            int j=v.top().second;
            if(s[j]>d){
                d=v.top().first;
                ans.push_back(j+1);
            }
            v.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends