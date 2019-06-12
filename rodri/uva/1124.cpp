#include <iostream>
#include <string>
using namespace std;
int main()
{
    string line;
    bool primer = true;
    while (!cin.eof())
    {
        if (!primer)
            cout << endl;
        primer = false;
        getline(cin, line);
        cout << line;
    }

    return 0;
}