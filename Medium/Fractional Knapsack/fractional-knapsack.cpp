//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,int>>p_w;
        for(int i=0;i<n;i++){
            p_w.push_back({(double)arr[i].value/(double)arr[i].weight,i});
        }
        
        sort(p_w.begin(),p_w.end());
        double profit=0;
        for(int i=n-1;i>=0;i--){
            int idx=p_w[i].second;
            if(W>=arr[idx].weight){
               profit+=(double) arr[idx].value; 
               W-=arr[idx].weight;
               if(W==0) return profit;
            }
            
            else{
                profit+=(double) W*p_w[i].first;
                W-=W;
                break;
            }
        }
        
        return profit;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends