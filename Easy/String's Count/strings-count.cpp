//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}
// } Driver Code Ends


#define ll long long

long long int countStr(long long int n)
{
    //complete math question
    if(n==1) return 3;
    if(n==2) return 8;
    ll all_a=1;
    ll one_b=n;
    ll one_c=n;
    ll one_b_c=n*1ll*(n-1);
    ll one_b_two_c=(n*1ll*(n-1)*1ll*(n-2))/2;
    ll two_c=(n*1ll*(n-1))/2;
    ll ans= all_a+one_b+one_c+one_b_c+one_b_two_c+two_c;
    return ans;
    
}