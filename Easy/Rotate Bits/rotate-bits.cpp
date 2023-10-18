//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
{
    //code here.
    d%=16; // keeping the value of d from 0 to 15

    // shifting left by d digits && right by 16-d digits
    int left = ((n<<d) | (n>>(16-d))) & 65535;

    // shifting right by d digits && left by 16-d digits
    int right = (n>>d) | (n<<(16-d)) & 0xFFFF;
    // here we are doing an & operation with 65535 or 0xFFFF(in Hexa Form) as it is the sum
    // of 2^0 + 2^1 + 2^2 + ...  + 2^15 which represent a 16 bit no value equal to 2^16-1 
    // we are doing this so that our number remains a 16 bit number
    
    return {left,right};
    
}
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends