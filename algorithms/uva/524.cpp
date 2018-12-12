#include <iostream>
#include <set>
#include <vector>

using namespace std; 
set<int> primos;
vector<vector<int>> sols;

bool isprime(int num){
    int i;
    for(i=2;i<num;i++){
        if(num%i==0)
            return false;
    }
    return true;
}
void setprimes(){
    int num;
    for(num=1; num<37;num++){
        if(isprime(num))
            primos.insert(num);
    }
}

bool in(vector<int> v, int val){
    for(int num:v){
        if(num==val) return true;
    }
    return false;
}

void posibles(vector<int> current, int max){
    int val;
    if(current.size()==0){
        current.push_back(1);
        posibles(current, max);
        return;
    }

    if(current.size()==max){
        val = current.front()+current.back();
        if(primos.count(val)==1)
            sols.push_back(current);
        return;
    }

    int ind;
    for(int primo:primos){
        ind=current.size()-1;
        val = primo-current[ind];
        if(val>0 && val<=max && !in(current, val)){
            vector<int> pos1 = current;
            pos1.push_back(val);
            posibles(pos1, max);
        }
    }
}

int main(){
    int max, cnum;
    cnum=1;
    setprimes();
    // for(int i:primos)
    //     cout << i << " ";
    // cout << endl;
    while(cin >> max){
        if(cnum!=1)
            cout << endl;
        sols.clear();
        vector<int> a;
        posibles(a, max);
        cout << "Case "<<cnum<<":"<<endl;
        for(vector<int> sol:sols){
            for(int val: sol){
                cout << val;
                if(sol.back()!=val)
                    cout << " ";
            }
            cout<<endl;
        }
        cnum++;
    }

    return 0;
}