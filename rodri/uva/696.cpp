#include <iostream>
using namespace std;
int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}
// m < n
void solve(int m, int n)
{
    if (m == 1)
    {
        cout << n;
        return;
    }
    else if (m == 2)
    {
        int sol = n / 4;
        cout << (sol * 4 + 2 * min(2, n % 4));
        return;
    }

    if (m % 2 == 0)
    {
        cout << n * m / 2;
        return;
    }
    else
    {
        int aux = m / 2;
        if (n % 2 == 0)
        {
            cout << aux * n / 2 + (aux + 1) * n / 2;
            return;
        }
        else
        {
            cout << aux * (n - 1) / 2 + (aux + 1) * (n - 1) / 2 + (aux + 1);
        }
    }
}
int main()
{
    int m, n;
    cin >> m >> n;
    while (m != 0)
    {
        if (m > n)
            solve(n, m);
        else
            solve(m, n);

        cout << " knights may be placed on a " << m << " row " << n << " column board." << endl;
        cin >> m >> n;
    }

    return 0;
}