#include <iostream>
using namespace std;
int main()
{
    int t;
    int n;
    cin >> t;
    while (t > 0)
    {
        cin >> n;
        int vals[n];
        int min = 101;
        int max = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> vals[i];
            if (vals[i] < min)
                min = vals[i];
            if (vals[i] > max)
                max = vals[i];
        }
        cout << (max - min) * 2 << endl;
        t--;
    }
    return 0;
}