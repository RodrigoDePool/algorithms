#include <iostream>
using namespace std;
int main()
{
    int l;
    cin >> l;
    while (l != 0)
    {
        long long mind = 30000000;
        char curr;
        cin >> curr;
        int currindex = 0;
        while (curr == '.')
        {
            currindex++;
            cin >> curr;
        }
        if (curr == 'Z')
            mind = 0;
        char next;
        for (int i = currindex + 1; i < l; i++)
        {
            cin >> next;
            if (next == 'Z')
            {
                mind = 0;
            }
            else if (next != '.')
            {
                if (curr == next)
                {
                    currindex = i;
                }
                else
                {
                    if (i - currindex < mind)
                        mind = i - currindex;
                    currindex = i;
                    curr = next;
                }
            }
        }
        cout << mind << endl;

        cin >> l;
    }
    return 0;
}