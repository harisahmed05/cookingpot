#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    
    int n, previous;
    int ans = 0;

    cin >> n;
    previous = n;

    while(cin >> n) {
        if(n > previous) ans++;
        previous = n;
    }
    cout << ans << endl;
}
