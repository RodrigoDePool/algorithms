#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        int n;
        cin >> n;

        n = n * 315 + 37460 - 498;
        if (n < 0)
            n = -n;

        n = (n / 10) % 10;

        cout << n << endl;
        t--;
    }
    return 0;
}