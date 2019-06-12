#include <iostream>
using namespace std;
int main()
{
    int h, u, d, f;
    cin >> h;
    while (h != 0)
    {
        cin >> u >> d >> f;
        // Para trabajar directamente en enteros (con respecto al factor)
        h *= 100;
        u *= 100;
        d *= 100;

        int curr = 0;
        int day = 0;
        while (curr >= 0)
        {
            day++;
            if (u - u * f * (day - 1) / 100 > 0)
                curr += u - u * f * (day - 1) / 100;

            if (curr > h)
                break;
            curr -= d;
        }
        if (curr > 0)
            cout << "success on day ";
        else
            cout << "failure on day ";
        cout << day << endl;

        cin >> h;
    }
    return 0;
}