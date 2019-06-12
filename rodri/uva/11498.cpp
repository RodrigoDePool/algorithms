#include <iostream>
using namespace std;
int main()
{
    int nqs;
    cin >> nqs;
    while (nqs != 0)
    {
        int divx, divy;
        cin >> divx >> divy;
        for (int i = 0; i < nqs; i++)
        {
            int x, y;
            cin >> x >> y;
            if (x == divx || y == divy)
            {
                cout << "divisa\n";
            }
            else if (x > divx && y > divy)
            {
                cout << "NE\n";
            }
            else if (x < divx && y > divy)
            {
                cout << "NO\n";
            }
            else if (x < divx && y < divy)
            {
                cout << "SO\n";
            }
            else
            {
                cout << "SE\n";
            }
        }

        cin >> nqs;
    }

    return 0;
}