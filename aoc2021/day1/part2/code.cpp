#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    int n;
    
    int sum1 = 0, sum2 = 0, temp;
    int count = 0;
    int ans = 0;
    bool flag = false;
    
    cin >> n;
    sum1 += n;

    cin >> n;
    sum1 += n;
    sum2 += n;

    cin >> n;
    sum1 += n;
    sum2 += n;
    temp = n;

    while(cin >> n) {
        sum2 += n;
        if(sum2 > sum1) ans++;
        sum1 = sum2;
        sum2 = temp+n;
        temp = n;
    }
    cout << ans << endl;
}
