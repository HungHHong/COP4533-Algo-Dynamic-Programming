
#include <string>
#include <vector>
#include <iostream>
#include <fstream>  
#include <utility>  
#include <unordered_map>
#include <algorithm>
#include <random>

using namespace std;

// Creates a random strng of size equal to n
string random_string(int n, const vector<char>& alphabet) {
    string s;
    s.reserve(n);
    for (int i = 0; i < n; i++) {
        s.push_back(alphabet[rand() % alphabet.size()]);
    }
    return s;
}

// Creates a random alphabet of size k
vector<char> random_alphabet(int k) {
    vector<char> letters;
    vector<char> all = {
        'a','b','c','d','e','f','g','h','i','j',
        'k','l','m','n','o','p','q','r','s','t',
        'u','v','w','x','y','z'
    };

    random_device rd;
    mt19937 rng(rd());

    shuffle(all.begin(), all.end(), rng);

    for (int i = 0; i < k; i++) {
        letters.push_back(all[i]);
    }
    return letters;
}


int main() {

    srand(time(nullptr));

    int numFiles = 10;
    int minLen = 25; // String have to be at least 25 long
    int maxLen = 60; // We will have upper bound of 60

    // Assign random values 1–10 to each character
    for (int f = 1; f <= numFiles; f++) {

        // Random k between 3 and 10
        int k = 3 + rand() % 8;

        // Random alphabet of size k
        vector<char> alphabet = random_alphabet(k);

        // Random values for each character
        unordered_map<char,int> value;
        for (char c : alphabet) {
            value[c] = 1 + rand() % 20;  // values 1–20
        }

        // Random lengths
        int lenA = minLen + rand() % (maxLen - minLen + 1);
        int lenB = minLen + rand() % (maxLen - minLen + 1);

        string A = random_string(lenA, alphabet);
        string B = random_string(lenB, alphabet);

        // Output file
        string filename = "../data/input" + to_string(f) + ".in";
        ofstream out(filename);

        out << k << "\n";
        for (char c : alphabet) {
            out << c << " " << value[c] << "\n";
        }

        out << A << "\n";
        out << B << "\n";

        out.close();
        cout << "Generated " << filename << " (K=" << k << ")\n";
    }


    return 0;
}
