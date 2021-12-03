#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    

    int horizontal = 0;
    int depth = 0;

    string instruction;
    int value;
    
    while(cin >> instruction >> value) {
       if(instruction == "forward") {
            horizontal += value;
       }
       if(instruction == "down") {
            depth += value;
       }
       if(instruction == "up") {
            depth -= value;
       }
    }

    cout << horizontal*depth << endl;
}
