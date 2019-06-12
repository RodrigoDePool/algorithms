#include <iostream>
using namespace std;

int resolver(int n, int m)
{
    n = n - 2;
    m = m - 2;
    int solx = n / 3;
    int soly = m / 3;
    if (n % 3 != 0)
        solx++;
    if (m % 3 != 0)
        soly++;
    return solx * soly;
}
int main()
{
    int t;
    int n, m;
    cin >> t;
    while (t > 0)
    {
        cin >> n >> m;
        cout << resolver(n, m) << endl;
        t--;
    }

    return 0;
}