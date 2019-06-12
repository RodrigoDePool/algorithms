#include <iostream>
using namespace std;
int main()
{
    int b, n;
    cin >> b >> n;
    while (b != 0 || n != 0)
    {
        int res[b];
        for (int i = 0; i < b; i++)
            cin >> res[i];
        for (int i = 0; i < n; i++)
        {
            int d, c, v;
            cin >> d >> c >> v;
            res[d - 1] -= v;
            res[c - 1] += v;
        }
        bool f = true;
        for (int i = 0; i < b; i++)
        {
            if (res[i] < 0)
            {
                f = false;
                break;
            }
        }
        if (f)
        {
            cout << "S" << endl;
        }
        else
        {
            cout << "N" << endl;
        }

        cin >> b >> n;
    }

    return 0;
}