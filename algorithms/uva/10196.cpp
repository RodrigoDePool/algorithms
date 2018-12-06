#include <iostream>
#include <map>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
using namespace std;
typedef pair<int, int> par;

vector <vector<char>> tab(8);
par wking;
par bking;
set <char> wdiags = {'b', 'q'};
set <char> bdiags = {'B', 'Q'};
set <char> wstraight = {'r', 'q'};
set <char> bstraight = {'R', 'Q'};


string bcheck = "black king is in check.";
string wcheck = "white king is in check.";
string ncheck = "no king is in check.";


bool brd(int i, int j, set<char> diag){
    if(i>7 || j>7) return false;
    if(diag.count(tab[i][j])==1) return true;
    if(tab[i][j]!='.') return false;
    return brd(i+1,j+1, diag);
}
bool tld(int i, int j, set<char> diag){
    if(i<0 || j<0) return false;
    if(diag.count(tab[i][j])==1) return true;
    if(tab[i][j]!='.') return false;
    return tld(i-1,j-1, diag);
}

bool trd(int i, int j, set<char> diag){
    if(i<0 || j>7) return false;
    if(diag.count(tab[i][j])==1) return true;
    if(tab[i][j]!='.') return false;
    return trd(i-1,j+1, diag);
}

bool bld(int i, int j, set<char> diag){
    if(i>7 || j<0) return false;
    if(diag.count(tab[i][j])==1) return true;
    if(tab[i][j]!='.') return false;
    return bld(i+1,j-1, diag);
}

bool st(int i, int j, set<char> stra){
    if(i<0) return false;
    if(stra.count(tab[i][j]) == 1) return true;
    if(tab[i][j]!='.')return false;
    return st(i-1, j, stra);
}

bool sb(int i, int j, set<char> stra){
    if(i>7) return false;
    if(stra.count(tab[i][j]) == 1) return true;
    if(tab[i][j]!='.')return false;
    return sb(i+1, j, stra);
}



bool sl(int i, int j, set<char> stra){
    if(j<0) return false;
    if(stra.count(tab[i][j]) == 1) return true;
    if(tab[i][j]!='.')return false;
    return sl(i, j-1, stra);
}

bool sr(int i, int j, set<char> stra){
    if(j>7) return false;
    if(stra.count(tab[i][j]) == 1) return true;
    if(tab[i][j]!='.')return false;
    return sr(i, j+1, stra);
}

bool cp(int i, int j, char p){
    if(p=='p' && i-1>0){
        if(j-1>=0 && tab[i-1][j-1] == p) return true;
        if(j+1<8 && tab[i-1][j+1] == p) return true;
    }
    if(p=='P' && i+1<8){
        if(j-1>=0 && tab[i+1][j-1] == p) return true;
        if(j+1<8 && tab[i+1][j+1] == p) return true;
    }
    return false;
}
bool ck(int i, int j, char k){
    int jk;
    jk = j-2;
    if(jk >= 0){
        if(i-1>=0 && tab[i-1][jk] == k) return true;
        if(i+1<8 && tab[i+1][jk] == k) return true;
    }
    jk = j-1;
    if(jk >= 0){
        if(i-2>=0 && tab[i-2][jk] == k) return true;
        if(i+2<8 && tab[i+2][jk] == k) return true;
    }
    jk = j+2;
    if(jk < 8){
        if(i-1>=0 && tab[i-1][jk] == k) return true;
        if(i+1<8 && tab[i+1][jk] == k) return true;
    }
    jk = j+1;
    if(jk < 8){
        if(i-2>=0 && tab[i-2][jk] == k) return true;
        if(i+2<8 && tab[i+2][jk] == k) return true;
    }
    return false;
}

bool check(char wb){
    int i,j;
    set <char> diags;
    set <char> straight;
    char pawn, knight;
    if(wb == 'w'){
        i = wking.first;
        j = wking.second;
        diags = wdiags;
        straight = wstraight;
        pawn = 'p';
        knight = 'n';
    }else{
        i = bking.first;
        j = bking.second;
        diags = bdiags;
        straight = bstraight;
        pawn = 'P';
        knight = 'N';
    }

    if(trd(i-1,j+1,diags)) return true;
    if(tld(i-1,j-1,diags)) return true;
    if(brd(i+1,j+1,diags)) return true;
    if(bld(i+1,j-1,diags)) return true;
    if(st(i-1,j,straight)) return true;
    if(sb(i+1,j,straight)) return true;
    if(sl(i,j-1,straight)) return true;
    if(sr(i,j+1,straight)) return true;
    if(cp(i,j,pawn)) return true;
    if(ck(i,j, knight)) return true;
    return false;
}



void resolver(int num){
    string sol;
    if(check('w'))
        sol = wcheck;
    else if(check('b'))
        sol = bcheck;
    else
        sol = ncheck;
    

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
            // cout << tab[i][j];
        }
        // cout << endl;
    }
    // cout << endl;

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