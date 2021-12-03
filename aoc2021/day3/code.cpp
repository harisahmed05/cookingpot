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

    string gamma = "000000000000";
    string epsilon = "000000000000";
    
    for(int i = 0; i < 12; i++) {
        if(p[i].first > p[i].second) {
            gamma[i] = '0';
            epsilon[i] = '1';
        }
        else if(p[i].first < p[i].second) {
            gamma[i] = '1';
            epsilon[i] = '0';
        }
    }

    int gamma_dec = stoi(gamma, nullptr, 2);
    int epsilon_dec = stoi(epsilon, nullptr, 2);

    cout << gamma_dec*epsilon_dec << endl;
}
