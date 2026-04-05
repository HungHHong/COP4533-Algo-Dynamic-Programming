// Author: Nicholas

#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>  
#include <utility>  

# include "dp_solver.cpp"

using namespace std;

int main(){
    for(int f = 1; f<11; f++){

        string inFile = "../data/input" + to_string(f)+".in";
        string outFile = "../data/output" + to_string(f) + ".txt";

        ifstream in(inFile);
        if (!in.is_open()) {
            cout << "Could not open " << inFile << "\n";
            continue;
        }

        // Num of characters in alphabet
        int k;

        in >> k;

        unordered_map<char,long long> mp;

        while(k-->0){
            char c;
            long long v;
            in >> c >> v;

            mp[c] = v;
        }

        string a, b;

        in >> a >> b;

        pair<long long,string> ans = dp_solution(a,b,mp);

        ofstream out(outFile);
        out << ans.first << endl;
        out << ans.second << endl;

        cout << "Generated " << outFile << "\n";
    
    }
    return 0;

}