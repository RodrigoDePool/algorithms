#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<char, int>> getDic(string inp)
{
    int diff = 'A' - 'a';

    vector<pair<char, int>> dic;

    for (char i = 'a'; i <= 'z'; i++)
    {
        pair<char, int> aux = pair<char, int>(i + diff, 0);
        dic.push_back(aux);
        aux = pair<char, int>(i, 0);
        dic.push_back(aux);
    }

    for (int i = 0; i < inp.length(); i++)
    {
        int ind;
        if (inp[i] >= 'A' && inp[i] <= 'Z')
        {
            ind = (inp[i] - 'A') * 2;
            auto p = dic[ind];
            dic[ind] = pair<char, int>(inp[i], p.second + 1);
        }
        else
        {
            ind = (inp[i] - 'a') * 2 + 1;
            auto p = dic[ind];
            dic[ind] = pair<char, int>(inp[i], p.second + 1);
        }
    }
    return dic;
}

void solve(vector<pair<char, int>> dic, string accum)
{
    string n;
    bool empty = true;
    for (int i = 0; i < 52; i++)
    {
        auto p = dic[i];
        if (p.second > 0)
        {
            empty = false;
            vector<pair<char, int>> aux = vector<pair<char, int>>(dic);
            aux[i] = pair<char, int>(p.first, p.second - 1);
            n = accum + p.first;
            solve(aux, n);
        }
    }
    if (empty)
        cout << accum << endl;
}

int main()
{
    int t;
    cin >> t;

    for (int pp = 0; pp < t; pp++)
    {
        string inp;
        cin >> inp;
        auto dic = getDic(inp);
        solve(dic, "");
    }

    return 0;
}