//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	void recursion(string S,vector<string> &ans,string &temp,vector<int> &vis){
	    if(S.length()==temp.length()){
	        if(find(ans.begin(),ans.end(),temp)==ans.end())
	            ans.push_back(temp);
	        return;
	    }
	    for(int i=0;i<S.length();i++){
	        if(!vis[i]){
	            temp+=S[i];
	            vis[i]=1;
	            recursion(S,ans,temp,vis);
	            vis[i]=0;
	            temp.pop_back();
	        }
	    }
	}
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string>ans;
		    string temp = "";
		    vector<int>vis(S.length(),0);
		    recursion(S,ans,temp,vis);
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends