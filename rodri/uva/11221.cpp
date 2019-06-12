#include <iostream>
#include <string>
#include <cmath>
using namespace std;
char mat[103][103];

bool isCentral(string s)
{
    int l = s.length();
    bool cent = true;
    for (int i = 0; i < l / 2; i++)
    {
        if (s[i] != s[l - i - 1])
        {
            cent = false;
            break;
        }
    }
    return cent;
}
bool isDiagonal(int k)
{
    bool diag = true;
    for (int i = 0; i < k - 1; i++)
    {
        for (int j = 1; j + i < k; j++)
        {
            if (mat[i][i + j] != mat[i + j][i])
            {
                diag = false;
                break;
            }
        }
        if (!diag)
            break;
    }
    return diag;
}
int main()
{
    int t;
    cin >> t;
    string aa;
    getline(cin, aa);

    for (int x = 0; x < t; x++)
    {
        string inp;
        getline(cin, inp);
        string stripped = "";
        for (int i = 0; i < inp.length(); i++)
        {
            if (inp[i] == ' ' || inp[i] == ',' || inp[i] == '.' || inp[i] == '?' || inp[i] == '!' || inp[i] == '(' || inp[i] == ')')
            {
                continue;
            }
            else
            {
                stripped = stripped + inp[i];
            }
        }
        int l = stripped.length();
        int k = sqrt(l);
        cout << "Case #" << x + 1 << ":" << endl;
        if (k == sqrt(double(l)))
        {
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    mat[i][j] = stripped[k * i + j];
                }
            }
            if (isCentral(stripped) && isDiagonal(k))
                cout << k << endl;
            else
                cout << "No magic :(\n";
        }
        else
        {
            cout << "No magic :(\n";
        }
    }
    return 0;
}