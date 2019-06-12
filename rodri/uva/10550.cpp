#include <iostream>
using namespace std;
// POR ALGUNA RAZON EL ENUNCIADO LO DICE AL REVES DE LO QUE ES ??

int counter(int start, int end)
{
    if (end <= start)
    {
        return start - end;
    }
    else
    {
        return start + 40 - end;
    }
}

int normal(int start, int end)
{
    if (start <= end)
    {
        return end - start;
    }
    else
    {
        return 40 - start + end;
    }
}
int main()
{
    int ini, pri, seg, ter;
    int res;
    cin >> ini >> pri >> seg >> ter;
    while (ini != 0 || pri != 0 || seg != 0 || ter != 0)
    {
        res = 120;
        res += counter(ini, pri);
        res += normal(pri, seg);
        res += counter(seg, ter);

        cout << res * 9 << endl;
        cin >> ini >> pri >> seg >> ter;
    }
    return 0;
}