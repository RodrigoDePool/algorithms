#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    string line;
    cin >> t;

    while (t > 0)
    {
        cin >> line;
        if (line.length() > 3)
        {
            cout << 3 << endl;
        }
        else
        {
            int cuenta = 0;
            if (line[0] == 'o')
                cuenta++;
            if (line[1] == 'n')
                cuenta++;
            if (line[2] == 'e')
                cuenta++;
            if (cuenta >= 2)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }

        t--;
    }
}