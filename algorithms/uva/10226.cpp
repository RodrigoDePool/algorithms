#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <cstdio>
using namespace std;


int main(){
    int cases,i;
    string inp;

    cin >> cases;
    cin.ignore();
    getline(cin, inp); // first blank line
    for(i=0;i<cases;i++){
        if(i!=0) cout << endl;
        unordered_map<string, int> amount;
        set<string> trees;
        getline(cin, inp);
        long total=0;
        while(inp.length()>0 && inp[0]!=' '){
            total++;
            if(amount.count(inp)==0){
                amount[inp]=1;
                trees.insert(inp);
            }else{
                amount[inp]++;
            }
            getline(cin, inp);
        }
        for(string tree:trees){
            double per = double(amount[tree]*100)/total;
            cout << tree << " ";
            printf("%.4f\n",  per);
        }


    }

}
