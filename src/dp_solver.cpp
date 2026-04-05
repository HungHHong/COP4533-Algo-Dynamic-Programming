//Author: Hung Hong

#include <unordered_map>
#include <string>  
#include <utility>  


#include <vector>
#include <algorithm>

using namespace std;

pair<long long,string> dp_solution(string a, string b, unordered_map<char,long long> mp){

    int m = a.size();
    int n = b.size();

    // DP table: M[i][j] = OPT(i,j)
    vector<vector<long long>> M(m+1, vector<long long>(n+1, 0));
    /* Initialize base cases
    for i = 0 to m:  M[i, 0] = 0
    for j = 0 to n:  M[0, j] = 0
    */

    // Fill DP table (Botton-up approach)
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            
            //Recurrence Equation:
            if(a[i-1] == b[j-1]){ // Case 1: match
                M[i][j] = max({
                    mp[a[i-1]] + M[i-1][j-1],  // take match
                    M[i-1][j],                // skip a
                    M[i][j-1]                 // skip b
                });
            } else { //Case 2: not match
                M[i][j] = max(
                    M[i-1][j],
                    M[i][j-1]
                );
            }
        }
    }

    // Back-Tracking
    int i = m, j = n;
    string res = "";

    while(i > 0 && j > 0){
        //Case 1: matched and take character
        if(a[i-1] == b[j-1] &&
           M[i][j] == M[i-1][j-1] + mp[a[i-1]]){
            
            res.push_back(a[i-1]);
            i--;
            j--;
        }
        // Case 2: notmatch and we skip a[i]
        else if(M[i][j] == M[i-1][j]){
            i--;
        }
        // Case 3: notmatch and we skip b[j]
        else{
            j--;
        }
    }

    reverse(res.begin(), res.end());

    return {M[m][n], res};
}


/* original Pseudocode implementation:

DP_solver(A, B, v):
    m = length(A), n = length(B)

    // Initialize base cases
    for i = 0 to m:  M[i, 0] = 0
    for j = 0 to n:  M[0, j] = 0

    // Fill table bottom-up approach
    for i = 1 to m:
        for j = 1 to n:
            if A[i] = B[j]:
                M[i, j] = max(v(A[i]) + M[i-1, j-1],
                              M[i-1, j],
                              M[i, j-1])
            else:
                M[i, j] = max(M[i-1, j], M[i, j-1])

    return M[m, n]

*/