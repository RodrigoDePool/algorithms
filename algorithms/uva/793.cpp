#include <stack>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <regex>
#include <sstream>
using namespace std;
//TIME LIMIT DFS ES MUY BESTIA, LLEVAR ALGUN TIPO DE MEMORIA?
bool connected(unordered_map<int, vector<int>> grafo, int c1, int c2){
    if(c1==c2) return true;
    set<int> visited;
    stack<int> explore;
    explore.push(c1);
    while(!explore.empty()){
        int curr = explore.top();
        explore.pop();
        if(visited.count(curr)==0){
            visited.insert(curr);
            for(int dest:grafo[curr]){
                if(dest==c2) return true;
                explore.push(dest);
            }
        }
    }
    return false;
}
int main(){
    int cases, n;
    string line;
    char q;
    int c1, c2;
    regex blank("[ ]*");
    cin >> cases;
    cin.ignore();
    getline(cin, line);
    for(int w=0; w<cases;w++){
        if(w!=0) cout << endl;
        unordered_map<int, vector<int>> grafo;
        int succ=0, unsucc=0;
        cin>>n;
        cin.ignore();
        while(true){
            getline(cin, line);
            if(regex_match(line, blank)) break;
            stringstream ss(line);
            ss >> q >> c1 >> c2;
            if(q=='c'){
                grafo[c1].push_back(c2);
                grafo[c2].push_back(c1);
            }else if(connected(grafo, c1, c2)){
                succ++;
            }else{
                unsucc++;
            }
        }
        cout << succ << "," << unsucc << endl;
    }
}
