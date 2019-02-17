/**
* @file 504.cpp
* @brief Solution for the 504 problem in aceptaelreto.com
* @author Rodrigo De Pool
* @version 1.0
* @date 2019-02-18
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/**
* To solve the problem we do dijkstra twice:
* The first time it puts weights to 1, this way we find the shortest
* path by number of edges.
* 
* The second time, it uses normal weights and keeps track of the number
* of edges crossed. Later the number of crossed edges is compared with the
* first solution.
* 
* Take into account that the second time we do dijkstra we must always
* keep the solutions with the shortest length, and in case of equal length
* we must compare the number of edges crossed. This way we make sure that
* if there are two optimal paths we take the one with less 'steps'.
* 
* NOTE: This solution is suboptimal, we could have found the shortest path
* by number of edges crossed using BFS.
*/
typedef pair<int, int> pii;
pii dijkstra1(int src, int dst, vector<pii> adj[], int n)
{

    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, INT_MAX);
    vector<int> steps(n + 1, 0);

    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push(make_pair(0, src));
    dist[src] = 0;

    pii node;
    while (!q.empty())
    {
        int a = q.top().second;
        q.pop();
        if (visited[a])
            continue;
        else if (a == dst)
            return pii(dist[dst], steps[dst]);
        visited[a] = true;
        for (auto u : adj[a])
        {
            int b = u.second, weight = 1;
            if (dist[b] > dist[a] + weight)
            {
                steps[b] = steps[a] + 1;
                dist[b] = dist[a] + weight;
                q.push(make_pair(dist[b], b));
            }
        }
    }
    return pii(-1, -1);
}
pii dijkstra(int src, int dst, vector<pii> adj[], int n, int pos)
{

    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, INT_MAX);
    vector<int> steps(n + 1, 0);
    int aux = INT_MAX;

    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push(make_pair(0, src));
    dist[src] = 0;

    pii node;
    while (!q.empty())
    {
        int a = q.top().second;
        q.pop();
        if (visited[a])
            continue;
        else if (a == dst)
        {
            return pii(dist[dst], steps[dst]);
        }
        visited[a] = true;
        for (auto u : adj[a])
        {
            int b = u.second, weight = u.first;
            if (dist[b] > dist[a] + weight || (dist[b] == dist[a] + weight && steps[b] > steps[a] + 1))
            {
                steps[b] = steps[a] + 1;
                dist[b] = dist[a] + weight;
                q.push(make_pair(dist[b], b));
            }
        }
    }
    return pii(-1, -1);
}
int main()
{
    int n;
    while (cin >> n)
    {
        int c, g1, g2, w;
        vector<pii> adj[n + 1];
        cin >> c;
        for (int i = 0; i < c; i++)
        {
            cin >> g1 >> g2 >> w;
            adj[g1].push_back(pair<int, int>(w, g2));
            adj[g2].push_back(pair<int, int>(w, g1));
        }
        int k, src, dst;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> src >> dst;
            pii sol2 = dijkstra1(src, dst, adj, n);
            if (sol2.first == -1)
            {
                cout << "SIN CAMINO" << endl;
            }
            else
            {
                pii sol1 = dijkstra(src, dst, adj, n, sol2.first);
                cout << sol1.first << " ";
                if (sol1.second == sol2.first)
                    cout << "SI" << endl;
                else
                    cout << "NO" << endl;
            }
        }
        cout << "----" << endl;
    }
}
