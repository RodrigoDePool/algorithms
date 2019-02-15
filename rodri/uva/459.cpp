#include <iostream>
#include <string>
#include <stack>
#include <regex>
#include <unordered_map>
using namespace std;
int connected_components(unordered_map<char,vector<char>> edges, char maxchar){
    int conn = 0;
    int numnodes = maxchar - 'A' + 1;
    vector<bool> visited(numnodes, false);
    for(char aux='A'; aux<=maxchar; aux++){
        if(!visited[aux-'A']){
            conn++;
            stack<char> visitable;
            visitable.push(aux);
            while(!visitable.empty()){
                char curr=visitable.top();
                visitable.pop();
                if(!visited[curr-'A']){
                    visited[curr-'A']=true;
                    for(char dest:edges[curr]){
                        if(!visited[dest-'A'])
                            visitable.push(dest);

                    }
                }
            } 
        }
    }
    return conn;

}
int main(){
    int cases;
    regex blank("[ ]*");
    string line;
    char maxchar;
    cin >> cases;
    cin.ignore();
    getline(cin, line);

    for(int i=0; i<cases;i++){
        if(i!=0) cout << endl;
        unordered_map<char, vector<char>> edges;
        cin >> maxchar;
        cin.ignore();
        while(true){
            getline(cin, line);
            if(regex_match(line, blank)) break;
            edges[line[0]].push_back(line[1]);
            edges[line[1]].push_back(line[0]);
        }
        int num = connected_components(edges, maxchar);
        cout << num << endl;
    }
}
