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

map <int, int> cands;
vector<string>candsnames;
void resolver(vector<queue<int>> entrada, int size){
    do{
        //TODO MAL
    //     int minv=0;
    //     vector<int> minc;
    //     int maxv=0;
    //     vector<int> maxc;
    //     int total=0;
    //     for(auto& val:cands){
    //         total++;
    //         if(val.second>maxv){
    //             maxc.clear();
    //             maxc.push_back(val.first);
    //         }else if(val.second>=maxv){
    //             maxc.push_back(val.first);
    //         }
    //         if(val.second<minv){
    //             minc.clear();
    //             minc.push_back(val.first);
    //         }else if(val.second<=minv){
    //             minc.push_back(val.first);
    //         }
    //     }

    //     if(minv==maxv){
    //         for(auto& num:maxc) cout<<candsnames[num]<<endl;
    //         return;
    //     }
    //     if(double(maxc.size())/double(total) > 0.5){

    //     }
    //     for(queue<int> q: entrada){
    //         // TODO contar bla bla bla
    //     }
    return ;
    }while(true);

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
            cands[j]=0;
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
            int numi=0;
            while(getline(iss, item, ' ')){
                if(numi==0) cands[stoi(item)]++;
                entradas[numvotos].push(stoi(item));
                numi++;
            }
            if(cin){
                getline(cin, line);
            }else{
                line = "";
            }
            numvotos++;
        }
        resolver(entradas, numvotos);
    }
    return 0;
}