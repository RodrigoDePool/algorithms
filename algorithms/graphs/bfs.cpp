#include <iostream>
#include <cstdio>
using namespace std;

//INPUT:
// N (num nodes from 0 to N-1)
// E (num of edges from 0 to 1000000)
// src (source of node, from 0 to n-1)
// dst (dst node, from 0 to n-1)
// v1 v2 weight (conection from v1 -> v2 with weigh w)
// ... (E edges)
//OUTPUT:
// d (shortest path distance or "inf")
// src v1 v2 v3 v4 ... dst (path to dst or null)

int graph[1000000][3];
int numnodes, numedges, src, dst;


int main() {
    int  i, v, u, w;
    
    cin >> numnodes;
    cin >> numedges;
    cin >> src;
    cin >> dst;

    for(i=0; i<numedges; i++){
        scanf("%d %d %d",&u, &v, &w);
        graph[i][0] = u;
        graph[i][1] = v;    
        graph[i][2] = w;    
    }
    //BFS
    
    return 0;
}

