// Author: Nicholas

#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>  
#include <utility>  


# include "dp_solver.cpp"

using namespace std;

int main(){

    // Num of characters in alphabet
    int k;

    cin >> k;

    unordered_map<char,long long> mp;

    while(k-->0){
        char c;
        long long v;
        cin >> c >> v;

        mp[c] = v;
    }

    string a, b;

    cin >> a >> b;

    pair<long long,string> ans = dp_solution(a,b,mp);

    cout << ans.first << endl;
    cout << ans.second << endl;

    return 0;

}