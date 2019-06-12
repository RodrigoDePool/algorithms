#include <iostream>
using namespace std;
bool dec(int x, int y)
{
    return x > y;
}
bool cre(int x, int y)
{
    return x < y;
}

int main()
{
    int n;
    cin >> n;
    cout << "Lumberjacks:" << endl;
    for (int i = 0; i < n; i++)
    {
        int curr, next;
        bool decreasing = true;
        cin >> curr >> next;
        if (curr < next)
            decreasing = false;
        bool ordered = true;
        for (int j = 2; j < 10; j++)
        {
            cin >> next;
            if (decreasing && !dec(curr, next))
            {
                ordered = false;
            }
            else if (!decreasing && !cre(curr, next))
            {
                ordered = false;
            }
            curr = next;
        }
        if (ordered)
            cout << "Ordered" << endl;
        else
            cout << "Unordered" << endl;
    }

    return 0;
}