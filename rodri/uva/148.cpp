#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

typedef unordered_map<char, int> lettervalue;
typedef vector<pair<char, int>> letternums;
typedef vector<pair<string, letternums>> dic;
bool isPossible(lettervalue goal, letternums p)
{
    for (auto ele : p)
    {
        if (goal.count(ele.first) == 0)
            return false;
        else if (goal[ele.first] < ele.second)
            return false;
    }
    return true;
}
lettervalue copyGoalWithout(lettervalue goal, letternums p)
{
    lettervalue aux = lettervalue(goal);
    for (auto ele : p)
    {
        aux[ele.first] -= ele.second;
    }
    return aux;
}
dic copyDictWithout(dic dict, int ind)
{
    dic copy;
    for (int i = 0; i < dict.size(); i++)
    {
        if (i != ind)
            copy.push_back(dict[i]);
    }
    return copy;
}

lettervalue createLetterValue(string inp)
{
    lettervalue lv;
    for (auto c : inp)
    {
        if (lv.count(c) > 0)
        {
            lv[c] += 1;
        }
        else
        {
            lv[c] = 1;
        }
    }
    return lv;
}
letternums createLetterNum(string inp)
{
    unordered_map<char, int> already;
    letternums ln;
    for (int i = 0; i < inp.length(); i++)
    {
        if (already.count(inp[i]) > 0)
        {
            ln[already[inp[i]]] = pair<char, int>(inp[i], ln[already[inp[i]]].second + 1);
        }
        else
        {
            ln.push_back(pair<char, int>(inp[i], 1));
            already[inp[i]] = ln.size() - 1;
        }
    }
    return ln;
}

string deleteSpaces(string inp)
{
    string strip = "";
    for (int i = 0; i < inp.length(); i++)
    {
        if (inp[i] != ' ')
        {
            strip += inp[i];
        }
    }
    return strip;
}

void solve(dic dict, lettervalue goal, int left, vector<string> accum, string input)
{
    if (left < 0)
        return;
    if (left == 0)
    {
        cout << input << " =";
        for (int i = 0; i < accum.size(); i++)
        {
            auto p = accum[i];
            cout << " ";
            cout << p;
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < dict.size(); i++)
    {
        auto p = dict[i];
        if (p.first.length() <= left)
        {
            if (isPossible(goal, p.second))
            {
                dic auxdic = copyDictWithout(dict, i);
                lettervalue auxgoal = copyGoalWithout(goal, p.second);
                vector<string> accumaux = vector<string>(accum);
                accumaux.push_back(p.first);
                solve(auxdic, auxgoal, left - p.first.length(), accumaux, input);
            }
        }
    }
}

int main()
{
    string inp;
    int numhashtags = 0;
    dic dict;
    do
    {
        getline(cin, inp);
        if (inp == "#")
        {
            numhashtags++;
            continue;
        }
        if (numhashtags == 0)
        {
            letternums l = createLetterNum(inp);
            dict.push_back(pair<string, letternums>(inp, l));
        }
        else if (numhashtags == 1)
        {
            vector<string> aux;
            lettervalue goal = createLetterValue(deleteSpaces(inp));
            solve(dict, goal, inp.length(), aux, inp);
        }

    } while (numhashtags < 2);
    return 0;
}