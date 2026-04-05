// Author: Nicholas

#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>  
#include <utility>  
#include <chrono>

# include "dp_solver.cpp"

using namespace std;

int main(){

    ofstream csv("../experiments/runtimes.csv");
    csv << "file,total_length,runtime_ms,value\n";


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

        int total_len = a.size()+b.size();
        long long mult_len = a.size()*b.size();

        auto start = chrono::high_resolution_clock::now();
        pair<long long,string> ans = dp_solution(a,b,mp);
        auto end = chrono::high_resolution_clock::now();

        double ms = chrono::duration<double, milli>(end - start).count();

        // Write to CSV
        csv << inFile << "," << total_len << "," << mult_len << ","<< ms << "," << ans.first << "\n";

        ofstream out(outFile);
        out << ans.first << endl;
        out << ans.second << endl;

        cout << "Generated " << outFile << "\n";
    
    }
    csv.close();
    cout << "Runtime results written to ../experiments/runtimes.csv\n";
    return 0;

}