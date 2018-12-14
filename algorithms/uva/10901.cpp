#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
typedef pair<int, int> par;

int main(){
    int cases;
    cin >> cases;
    cin.ignore();
    for(int ii=0; ii<cases; ii++){
        int n,m;
        int t;
        cin >> n >> t >> m;
        
        queue<par> left, right;
        for(int i=0; i<m; i++){
            int time;
            string place;
            cin >> time >> place;
            par tid = {time, i};
            if(place=="left"){
                left.push(tid);
            }else{
                right.push(tid);
            }
        }
        
        int currtime=0;
        int currside = "left";
        while(!left.empty() || !right.empty(){
            
        
        }



    }

}
