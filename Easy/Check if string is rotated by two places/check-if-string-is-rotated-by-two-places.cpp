//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string a, string b)
    {
        // Your code here
          if (a.length() != b.length()) {
        return false;  // Strings of different lengths can't be rotated to match.
    }

    string clockwise = a.substr(2) + a.substr(0, 2);  // Rotate clockwise.
    string anticlockwise = a.substr(a.length() - 2) + a.substr(0, a.length() - 2);  // Rotate anticlockwise.

    return (clockwise == b || anticlockwise == b);
    }
};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends