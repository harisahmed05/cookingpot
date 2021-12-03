#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    pair<int, int> p[12]; // first indicates zeroes, second indicates ones!

    string line;
    while(cin >> line) {
        for(int i = 0; i < 12; i++) {
            if(line[i] == '0') p[i].first += 1;
            else p[i].second += 1;
        }
    }

    string gamma_bin = "000000000000";
    string epsilon_bin = "000000000000";
    
    for(int i = 0; i < 12; i++) {
        if(p[i].first > p[i].second) {
            gamma_bin[i] = '0';
            epsilon_bin[i] = '1';
        }
        else if(p[i].first < p[i].second) {
            gamma_bin[i] = '1';
            epsilon_bin[i] = '0';
        }
    }

    int gamma_dec = stoi(gamma_bin, nullptr, 2);
    int epsilon_dec = stoi(epsilon_bin, nullptr, 2);

    cout << gamma_dec*epsilon_dec << endl;
}
