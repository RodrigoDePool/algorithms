#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, k, aux;
        cin >> m;
        char auxc;
        unordered_map<char, int> pay;
        while (m--)
        {
            cin >> auxc >> aux;
            pay[auxc] = aux;
        }
        cin >> k;

        string line;
        getline(cin, line);

        long long totalcents = 0;
        while (k--)
        {
            getline(cin, line);
            for (char c : line)
            {
                if (pay.count(c) >= 1)
                {
                    totalcents += pay[c];
                }
            }
        }
        printf("%lld.%02lld$\n", totalcents / 100, totalcents % 100);
    }
    return 0;
}