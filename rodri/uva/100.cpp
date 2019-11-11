#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;



unordered_map<long long, long long> leng = unordered_map<long long, long long>();

long long cal_l(long long n){
    vector<long long> intermediate = vector<long long>();
    long long n_ini = n;
    while(true) {
        if(leng.count(n)>0){
            int c = intermediate.size();
            for(long long ele:intermediate){
                leng[ele]=leng[n]+c;
                c-=1;
            }
            return leng[n_ini];
        }
        intermediate.push_back(n);
        if(n%2==1)
            n = n*3+1;
        else
            n=n/2;
    }
}

int main(){
    leng[1]=1;

    int  i,j,x;
    long long outp;
    while(!cin.eof()){
        cin >> i >> j;
        outp=-1;
        if(i<=j){
            for(x=i;x<=j;x+=1){
                long long aux=cal_l(x);
                if(aux>outp)
                    outp=aux;
            }
        }else{
            outp = max(cal_l(i), cal_l(j));
        }
        
        cout << i << " " << j << " " << outp << endl;
    }
    return 0;
}