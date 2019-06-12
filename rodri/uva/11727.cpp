#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int cas = 0;
    while (t > 0)
    {
        cas++;
        int a, b, c;
        cin >> a >> b >> c;
        if ((a > b && b > c) || (c > b && b > a))
        {
            cout << "Case " << cas << ": " << b << endl;
        }
        else if ((b > a && a > c) || (c > a && a > b))
        {
            cout << "Case " << cas << ": " << a << endl;
        }
        else
        {
            cout << "Case " << cas << ": " << c << endl;
        }
        t--;
    }

    return 0;
}