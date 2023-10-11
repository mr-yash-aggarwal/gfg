//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s)
    {
        reverse(s.begin(),s.end());
        int i=s.size()-1,j=i;
        while(i>=0){
            if(j==0 && i==j)            //extreme condition for if input is a.b.c.d.e.f
                break;
            if(s[j]!='.'){
                j--;
                if(j==0){
                    reverse(s.begin()+j , s.begin()+i+1);
                    break;
                }
            }
            else{
                reverse(s.begin()+j+1 , s.begin()+i+1);
                i=j-1;
                j=i;
            }
        }
        
        return s;
    }
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends