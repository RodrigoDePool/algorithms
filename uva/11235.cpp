#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;
// NO FUNCIONA, NOO. ESTA MAL!!!!
int main(){
    int n,q;
    cin >> n;
    while(n!=0){
        cin >> q;
        unordered_map<int, int> freqs;
        vector<int> differents;
        vector<int> all;

        int prev = INT_MIN;
        int freq = 0;
        for(int i=0; i<n; i++){
            int aux;
            cin >> aux;
            all.push_back(aux);
            if(aux!=prev){
                freq = 0;
                differents.push_back(aux);
            }
            freq++;
            freqs[aux] = freq;
            prev = aux; 
        }
        for(int i=0; i<q;i++){
            int from, to;
            int first, last;
            int firstf, lastf, maxf;
            cin >> from >> to;
            firstf=0;
            first=all[from];
            while(first==all[from] && from+firstf<=to){
                firstf++;
                first=all[from+firstf];
            }
            lastf=0;
            last=all[to];
            while(last==all[to] && to-lastf>=from){
                lastf++;
                last=all[to-lastf];
            }
            if(firstf>lastf) maxf=firstf;
            else maxf=lastf;

            first=all[from];
            last=all[to];
            while(first<last){
                if(freqs[first]>maxf)
                    maxf=freqs[first];
                from++;
                first=all[first];
            } 
            cout << maxf<<endl;
        }
        cin >> n;
    }

}
