#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    long long n,w;
    cin >> n >> w;
    while(n>0 || w>0){
        vector<long long> ps(n);
        for(long long i=0; i<n; i++)
            cin >> ps[i];
        sort(ps.begin(), ps.end());
        long long count=0;
        for(long long i=0;i<n-1;i++){
            if(ps[i]+ps[i+1]>w) break;
            vector<long long>::iterator it=lower_bound(
                                                 ps.begin()+i+1, 
                                                 ps.end(),
                                                 w-ps[i]);
            while(it!=ps.end() && ps[i]+*it==w)
                it++;

            if(it==ps.end()){
                count+=(ps.end()-ps.begin()-i-1);
            }else{
                count += (it-ps.begin()-i-1);   
            }
        }
        cout << count << endl;
        cin >> n >> w;
    }
    return 0;
}
