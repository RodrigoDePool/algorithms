#include <iostream>
using namespace std;
int main()
{
    int n, b, h, w;
    while (!cin.eof() && cin >> n >> b >> h >> w)
    {
        long long minv = 10000000;
        for (int i = 0; i < h; i++)
        {
            long long p;
            int maxplaces = -1;
            cin >> p;
            for (int j = 0; j < w; j++)
            {
                int curr;
                cin >> curr;
                if (curr > maxplaces)
                    maxplaces = curr;
            }
            if (n <= maxplaces && p * n <= b && p * n <= minv)
            {
                minv = p * n;
            }
        }
        if (minv == 10000000)
        {
            cout << "stay home" << endl;
        }
        else
        {
            cout << minv << endl;
        }
    }
    return 0;
}