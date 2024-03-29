//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int>ans;
            
            int i =0;
            int idx = txt.find(pat);
            
            while(idx != -1){
                
                ans.push_back(idx+1);
                
                idx = txt.find(pat,idx+1);
            }
            
            return ans.empty()?vector<int>{-1} : ans;
            
            //code here
        }
     
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends