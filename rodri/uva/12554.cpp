#include <iostream>
#include <string>
using namespace std;
int main()
{
    string song[16] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
    int n;
    cin >> n;
    string names[n];
    for (int i = 0; i < n; i++)
    {
        cin >> names[i];
    }
    int times = n / 16;
    if (n % 16 != 0)
        times++;

    int turn = 0;
    while (times > 0)
    {
        for (int i = 0; i < 16; i++)
        {
            cout << names[turn] << ": " << song[i] << endl;
            turn = (turn + 1) % n;
        }
        times--;
    }
    return 0;
}