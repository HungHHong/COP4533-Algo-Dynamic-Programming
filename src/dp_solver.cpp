Author: Hung Hong

#include <unordered_map>
#include <string>  
#include <utility>  

using namespace std;

pair<long long,string> dp_solution(string a, string b, unordered_map<char,long long> mp){

    pair<long long,string> pr;

    // TODO: SOLUTION WILL BE IMPLEMENTED HERE

    return pr;
}

/* original Pseudocode implementation:

DP_solver(A, B, v):
    m = length(A), n = length(B)

    // Initialize base cases
    for i = 0 to m:  M[i, 0] = 0
    for j = 0 to n:  M[0, j] = 0

    // Fill table bottom-up
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