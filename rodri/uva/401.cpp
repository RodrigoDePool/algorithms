#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<char,char> reverse;
    for(int i=0;i<200;i++)
        reverse[i]='.';
    reverse['A']='A';
    reverse['E']='3';
    reverse['3']='E';
    reverse['H']='H';
    reverse['I']='I';
    reverse['J']='L';
    reverse['L']='J';
    reverse['M']='M';
    reverse['O']='O';
    reverse['S']='2';
    reverse['2']='S';
    reverse['T']='T';
    reverse['U']='U';
    reverse['V']='V';
    reverse['W']='W';
    reverse['X']='X';
    reverse['Y']='Y';
    reverse['Z']='5';
    reverse['5']='Z';
    reverse['1']='1';
    reverse['8']='8';

    string s;
    int first=true;
    while(!cin.eof() && cin >> s){
        bool pal=true, mirr=true;
        int l=s.length();
        for(int i=0;i<l/2;i++){
            if(s[i]!=s[l-i-1])
                pal=false;
            if(s[i]!=reverse[s[l-i-1]])
                mirr=false;
        }
        if(l%2!=0){
            int mid=l/2;
            if(s[mid]!=reverse[s[mid]])
                mirr=false;
        }
        cout << s << " -- ";
        if(pal && mirr)
            cout << "is a mirrored palindrome.\n";
        else if(pal && !mirr)
                cout << "is a regular palindrome.\n";
        else if(!pal && mirr)
                cout << "is a mirrored string.\n";
        else
                cout << "is not a palindrome.\n";
        cout << endl;
    }


    return 0;
}
