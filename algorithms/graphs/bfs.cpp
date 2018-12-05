#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>
using namespace std;
typedef tuple<int, int, vector<int>> node_weight_path;

map <int, vector<pair<int,int>>> grafo;//origin->(dst, weight)
int nnodes, nedges, src, dst;
bool hassolution = false;
vector<int> solpath; // Solution path (src, v1, ..., dst)
int solweight = 0; // weight of path
    
int main() {
    cin >> nnodes >> nedges >> src >> dst;
    int v, u, w;
    for(int i=0; i<nedges; i++){
        scanf("%d\n%d\n%d",&u, &v, &w);
        grafo[u].push_back(pair<int,int>(v,w));   
    }
    //BFS
    vector<bool> visited(nnodes, false);
    queue<node_weight_path> q;
    q.push(node_weight_path(src, 0, {}));
    while(!q.empty()){
        node_weight_path ele = q.front();
        q.pop();
        int current = get<0>(ele);
        int weight = get<1>(ele);
        vector<int> path = get<2>(ele);
        if(visited[current] == false){
            visited[current] = true;
            vector<int> next_path = path;
            next_path.push_back(current);
            if(current == dst){
                hassolution = true;
                solpath = next_path;
                solweight = weight;
                break;
            }
            for(pair<int, int> edge:grafo[current]){
                if(visited[get<0>(edge)] == false)
                    q.push(make_tuple(get<0>(edge), 
                           weight+get<1>(edge), 
                           next_path));
            }
        }
    }
    if(hassolution){
        for(int way:solpath)
        cout << way << " ";
        cout << endl << "Con peso " << solweight;
    }else
        cout << "Sin camino";
    cout << endl;
    return 0;
}

