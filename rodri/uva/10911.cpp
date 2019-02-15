#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
double dmin;
double dist(pair<int, int> a, pair<int, int> b){
    double x=double(a.first-b.first);
    double y=double(a.second-b.second);
    return sqrt(x*x+y*y);
}
double greedy(vector<pair<int, int>> v){
    double ret=0;
    while(v.size()>0){
        double min=INT_MAX; 
        int minind;
        for(int i=1; i<v.size(); i++){
            double dst=dist(v[0], v[i]);
            if(dst<min){
                min=dst;
                minind=i;
            }
        }
        ret+=min;
        v.erase(v.begin()+minind);
        v.erase(v.begin());
    }
    return ret;
}
void solve(vector<pair<int, int>> v, double dacc){
    if(dacc>dmin) return;
    if(v.size()==0){
        dmin=dacc;
        return;
    }
    for(int i=1; i<v.size(); i++){
        vector<pair<int,int>> copy=v;
        double daux=dacc+dist(v[0], v[i]);
        copy.erase(copy.begin()+i);
        copy.erase(copy.begin());
        solve(copy, daux);
    }
    return;
}
int main(){
    int n;
    int cas;
    cas=0;
    cin >> n;
    while(n!=0){
        cas++;
        vector<pair<int, int>> v(2*n);
        int x,y;
        string name;
        for(int i=0; i<2*n; i++){
            cin >> name >> x >> y; 
            v[i]=pair<int, int>(x,y);
        }
        dmin = greedy(v);
        solve(v, 0);
        printf("Case %d: %.2f\n",cas, dmin); 
        cin >> n;
    }
    return 0;
}
