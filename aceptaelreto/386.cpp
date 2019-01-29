#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool simular(queue<pair<int,int>> parejas, int micros, int tmax){
    priority_queue<int, vector<int>, greater<int>> used;
    while(!parejas.empty() && micros>used.size()){
        pair<int,int> aux = parejas.front();
        parejas.pop();
        used.push(aux.first+aux.second);
    }
    while(!parejas.empty()){
        pair<int, int> aux = parejas.front();
        parejas.pop();
        if(used.top()-aux.first>tmax){
            return false;          
        }else{
            int start=max(aux.first,used.top());
            used.pop();
            used.push(start+aux.second);
        }
    }
    return true;
}
int main(){
    int n, t;
    cin >> n;
    while(n>0){
        cin >> t; 
        queue<pair<int,int>> p;
        int arr, use;
        for(int i=0; i<n; i++){
            cin >> arr >> use;
            pair<int, int> par(arr,use);
            p.push(par);
        }
        int max=50000, min=1;
        int curr=(max+min)/2;
        while(true){
            if(max==min){
                break;
            }else if(simular(p,curr, t)){
                if(curr==min) break;
                max=curr;
            }else{
                min=curr+1; //curr?
            }
            curr=(max+min)/2;
        }
        cout << curr << endl;
        cin >> n;
    }
    return 0;
}
