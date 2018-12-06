#include <iostream>
#include <map>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
typedef pair<int, int> par;

vector <vector<char>> tab(8);
par wking;
par bking;

string bcheck = "black king is in check.";
string wcheck = "white king is in check.";
string ncheck = "no king is in check.";

void resolver(int num){
    string sol;
    int x,y;
    

    cout << "Game #"<<num<<": "<<sol<<endl;
    return;
}

bool leertablero(){    
    bool end=true;
    for(int i=0; i<8;i++){
        for(int j=0;j<8;j++){
            cin >> tab[i][j];
            if(tab[i][j]!='.') end=false;
            if(tab[i][j]=='k'){
                bking.first=i;
                bking.second=j;
            }else if(tab[i][j]=='K'){
                wking.first=i;
                wking.second=j;
            }
        }
    }
    return !end;
}

int main(){
    for(int i=0; i<8; i++){
        tab[i].resize(8);
    }
    int i=1;
    while(leertablero()){
        resolver(i);
        i++;
    }
    return 0;
}