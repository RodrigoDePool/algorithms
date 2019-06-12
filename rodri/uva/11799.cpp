#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int num = 0;
    while (t > 0)
    {
        num++;
        t--;
        int n;
        cin >> n;
        int max = -1;
        for (int i = 0; i < n; i++)
        {
            int v;
            cin >> v;
            if (v > max)
                max = v;
        }
        cout << "Case " << num << ": " << max << endl;
    }
    return 0;
}