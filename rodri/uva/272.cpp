#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    bool par = true;
    bool primero = true;
    while (!cin.eof())
    {
        if (!primero)
        {
            cout << endl;
        }
        primero = false;
        getline(cin, line);
        for (char ch : line)
        {
            if (ch == '\"')
            {
                if (par)
                {
                    cout << "``";
                    par = false;
                }
                else
                {
                    cout << "''";
                    par = true;
                }
            }
            else
            {
                cout << ch;
            }
        }
    }
    return 0;
}