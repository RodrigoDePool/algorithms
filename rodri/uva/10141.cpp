#include <cfloat>
#include <string>
#include <iostream>

using namespace std;
int main()
{
    int n, p;
    cin >> n >> p;

    int num = 0;
    while (n != 0 || p != 0)
    {
        num++;

        string props[p];
        int comps[p];
        float prices[p];
        float min = FLT_MAX;
        int maxcomp = -1;

        char a;
        cin >> a;
        string aux;
        for (int i = 0; i < n; i++)
            getline(cin, aux);

        for (int i = 0; i < p; i++)
        {
            getline(cin, props[i]);
            cin >> prices[i] >> comps[i];
            cin >> a;
            for (int j = 0; j < comps[i]; j++)
                getline(cin, aux);
            if (comps[i] > maxcomp)
                maxcomp = comps[i];
            if (comps[i] == n && prices[i] < min)
            {
                min = prices[i];
                aux = props[i];
            }
        }
        if (num != 1)
            cout << endl;
        cout << "RFP #" << num << endl;

        if (min != FLT_MAX)
        {
            cout << aux << endl;
        }
        else
        {
            min = FLT_MAX;
            for (int i = 0; i < p; i++)
            {
                if (comps[i] == maxcomp && prices[i] < min)
                {
                    min = prices[i];
                    aux = props[i];
                }
            }
            cout << aux << endl;
        }

        cin >> n >> p;
    }

    return 0;
}