#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    while (!cin.eof() && cin >> n)
    {
        int curr, next;
        bool jolly = false;
        if (n == 1)
        {
            cin >> curr;
            jolly = true;
        }
        else
        {
            unordered_map<int, bool> checklist;
            cin >> curr;
            int abs;
            for (int i = 1; i < n; i++)
            {
                cin >> next;
                abs = curr - next;
                if (abs < 0)
                    abs = -abs;
                if (abs >= 1 && abs <= n - 1)
                    checklist[abs] = true;
                curr = next;
            }
            if (checklist.size() == n - 1)
                jolly = true;
        }
        if (jolly)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
    }
    return 0;
}