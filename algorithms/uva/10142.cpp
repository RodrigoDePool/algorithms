#include <iostream>
#include <map>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <unordered_map>
using namespace std;
typedef tuple<int, int, int> tupla;

map <string, int> cands;
vector<string>candsnames;
void resolver(vector<queue<int>> entrada){
    do{
        int min=0;
        int max=0;
        vector<string> mincands;
        for(queue<int> q: entrada){
            // TODO contar bla bla bla
        }
    }while();

    return;
}


int main(){
    int cases;
    int aux[3];
    char a;
    cin >> cases;
    int n;
    for(int i=0; i<cases; i++){
        if(i!=0) cout<<endl;

        cin >> n;
        cin.ignore();
        cands.clear();
        candsnames.resize(n);
        for(int j=0; j<n; j++){
            getline(cin, candsnames[j]);
            cands[candsnames[j]]=0;
            // cout<< j << cands[j] << endl;
        }

        vector <queue<int>> entradas(1000);
        int numvotos=0;
        string line;
        if(cin){
                getline(cin, line);
        }else{
            line = "";
        }
        while(line.length()>0){
            istringstream iss(line);
            string item;
            while(getline(iss, item, ' ')){
                entradas[numvotos].push(stoi(item));
            }
            if(cin){
                getline(cin, line);
            }else{
                line = "";
            }
            numvotos++;
        }

        
        resolver(entradas);
    }
    return 0;
}