#include <iostream>
#include <map>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;
typedef tuple<int, int, int> tupla;

int minaux;
int maxv;
int maxcand;
set<int> mincands;
unordered_map<int, int> contarVotos(set<int> cands, vector<queue<int>>entrada, int size){
    unordered_map<int, int> votes;
    // Conteo de votos, ademas saca los maxvs y minvs
    // Deja en maxcand uno de los maximos  
    for(set<int>::iterator ptr=cands.begin(); ptr!=cands.end(); ptr++)
        votes[*ptr]=0;
    maxv=-1;
    for(int i=0;i<size;i++){
        queue<int> q = entrada[i];
        while(cands.count(q.front())!=1)
            q.pop();
        votes[q.front()]++;
        if(votes[q.front()]>maxv){
            maxv=votes[q.front()];
            maxcand=q.front();
        }
        if(i==0 || votes[q.front()]<votes[minaux]){
            minaux=q.front();
            mincands.clear();
        }
        if(votes[q.front()]==votes[minaux])
            mincands.insert(i);
    }
    return votes;
}

void resolver(set<int> cands, vector<string> candsnames, vector<queue<int>> entrada, int size){
    unordered_map<int, int> votes = contarVotos(cands, entrada, size);
    int total=size;
    if(maxv == votes[minaux]){
        /*Empate, imprimios todos*/
        for(set<int>:: iterator ptr=cands.begin(); ptr!=cands.end(); ptr++)
            cout << candsnames[*ptr] << endl;
        return;
    }
    if(double(maxv)/total > 0.5){
        /*Gana el maximo*/
        cout<<candsnames[maxcand]<<endl;
        return;
    }
    // No hay ganador, eliminamos a los minimos
    for(int i:mincands){
        queue<int> q = entrada[i];
        // Eliminamos el candidato de los votos y la lista de cands
        cands.erase(q.front());
        q.pop();
    }
    mincands.clear();
    return resolver(cands, candsnames, entrada, size);
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
        set<int> cands;
        vector<string>candsnames(n);
        for(int j=0; j<n; j++){
            getline(cin, candsnames[j]);
            cands.insert(j);
            // cout<< j << " " << candsnames[j] << endl;
        }

        vector <queue<int>> entradas(1000);
        int numvotos=0;
        string line;
        if(cin)
            getline(cin, line);
        else
            line = "";
        while(line.length()>0){
            istringstream iss(line);
            string item;
            while(getline(iss, item, ' ')){
                entradas[numvotos].push(stoi(item)-1);
                // cout << item << " ";
            }
            // cout << endl;
            if(cin && !cin.eof()){
                getline(cin, line);
            }else{
                line = "";
            }
            numvotos++;
        }
        resolver(cands,  candsnames, entradas, numvotos);
    }
    return 0;
}