// NOT SOLVED YET!!!

#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    int n;
    
    int sum1 = 0, sum2 = 0;
    int count = 0;
    pair<bool, int> flag1, flag2;

    while(cin >> n) {
        if(!flag1.first && !flag2.first) {
            sum1 += n;
            flag1.first = true;
            flag1.second += 1;
            continue;
        }
        if(flag1.second > 1 && !flag2.first) {
            sum2 += n;
            flag2.first = true;
            flag2.second += 1;

            sum1 += n;
            flag1.second += 1;
            continue;
        }

        if(flag1.first && flag2.first) {
            if(flag1.second < 3) {
                sum1 += n;
                flag1.second += 1;
            }
            else {
                sum1 = 0;
                flag1.second = 0;
            }
            if(flag2.second > 3) {
                sum2 += n;
                flag2.second += 1;
            }

        }
    }
}
