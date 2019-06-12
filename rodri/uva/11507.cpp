#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main()
{
    unordered_map<string, int> dict;
    dict["-x"] = 0;
    dict["+x"] = 1;
    dict["-y"] = 2;
    dict["+y"] = 3;
    dict["-z"] = 4;
    dict["+z"] = 5;

    int turns[6][4] = {{3, 2, 5, 4},
                       {2, 3, 4, 5},
                       {0, 1, 2, 2},
                       {1, 0, 3, 3},
                       {4, 4, 0, 1},
                       {5, 5, 1, 0}};

    int l;
    cin >> l;
    while (l != 0)
    {
        int curr;
        string next;
        curr = 1;
        for (int i = 0; i < l - 1; i++)
        {
            cin >> next;
            if (next != "No")
                curr = turns[curr][dict[next] - 2];
        }
        if (curr == 0)
            cout << "-x" << endl;
        else if (curr == 1)
            cout << "+x" << endl;
        else if (curr == 2)
            cout << "-y" << endl;
        else if (curr == 3)
            cout << "+y" << endl;
        else if (curr == 4)
            cout << "-z" << endl;
        else if (curr == 5)
            cout << "+z" << endl;

        cin >> l;
    }

    return 0;
}