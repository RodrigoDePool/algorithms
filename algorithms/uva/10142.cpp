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


void resolver(set<int> cands, vector<string> candsnames, vector<vector<int>> entrada, int size){
    map<int, int> votes;
    //Conteo de votos
    for(set<int>::iterator ptr=cands.begin(); ptr!=cands.end(); ptr++)
        votes[*ptr]=0;
    for(int i=0;i<size;i++){
        vector<int> q = entrada[i];
        int j;
        for(j=0;cands.count(q[j])!=1;j++);
        votes[q[j]]++;
    }
    int total=size;
    int maxv=-1;
    vector<int> maxc;
    int minv=1001;
    vector<int> minc;
    for(map<int, int>::iterator ptr=votes.begin(); ptr!=votes.end(); ptr++){
        if(ptr->second < minv){
            minv = ptr->second;
            minc.clear();
        }
        if(ptr->second == minv)
            minc.push_back(ptr->first);

        if(ptr->second > maxv){
            maxv = ptr->second;
            maxc.clear();
        }
        if(ptr->second == maxv)
            maxc.push_back(ptr->first);
    }
    if(maxv == minv)
        /*Empate, imprimios todos*/
        for(vector<int>:: iterator ptr=minc.begin(); ptr<minc.end(); ptr++){
            cout << candsnames[*ptr] << endl;
        return;
    }
    if(double(maxv)/total > 0.5){
        /*Gana el maximo*/
        cout<<candsnames[maxc[0]]<<endl;
        return;
    }
    /*No gana nadie, eliminamos los minimos*/
    for(vector<int>:: iterator ptr=minc.begin(); ptr<minc.end(); ptr++)
        cands.erase(*ptr);
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

        vector <vector<int>> entradas(1000);
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
                entradas[numvotos].push_back(stoi(item)-1);
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