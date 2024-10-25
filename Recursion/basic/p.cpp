//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long fact(long long n){
        if(n==0)return 1;
        return n*fact(n-1);
    }
    vector<long long> factorialNumbers(long long n) {
        // Write Your Code here
         vector<long long> ans;
         for(long long i=1;i<=n; i++){
             if(fact(i)<=n)ans.push_back(fact(i));
             else break;
         }
         return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends