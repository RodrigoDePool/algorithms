#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// NO FUNCIONA IDK WHY
int main(){
    long n,w;
    cin >> n >> w;
    while(n>0 || w>0){
        vector<long> ps(n);
        for(long i=0; i<n; i++)
            cin >> ps[i];
        sort(ps.begin(), ps.end());
        long count=0;
        for(long i=0;i<n-1;i++){
            if(ps[i]+ps[i+1]>w) break;
            vector<long>::iterator it=lower_bound(
                                                 ps.begin()+i+1, 
                                                 ps.end(),
                                                 w-ps[i]);
            if(it==ps.end()){
                count+=(ps.end()-ps.begin()-i-1);
            }else if(ps[i]+*it==w){
                count += (it-ps.begin()-i);   
            }else{
                count += (it-ps.begin()-i-1);   
            }
        }
        cout << count << endl;
        cin >> n >> w;
    }
    return 0;
}
