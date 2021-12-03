#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    

    int aim = 0;
    int horizontal = 0;
    int depth = 0;

    string instruction;
    int value;
    
    while(cin >> instruction >> value) {
       if(instruction == "forward") {
            horizontal += value;
            if(aim != 0) {
                depth += (value*aim);
            }
       }
       if(instruction == "down") {
            aim += value;
       }
       if(instruction == "up") {
            aim -= value;
       }
    }

    cout << horizontal*depth << endl;
}
