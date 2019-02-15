#include <cstdio>
#include <tuple>
#include <iostream>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int, int, int, string> stats;

class comp{
    public:
    bool operator()(stats t1, stats t2){
        if(get<0>(t1)<get<0>(t2) ||  get<0>(t1)>get<0>(t2))
            return get<0>(t1)<get<0>(t2);
        else if(get<1>(t1)<get<1>(t2) ||  get<1>(t1)>get<1>(t2))
            return get<1>(t1)<get<1>(t2);
        else if(get<2>(t1)<get<2>(t2) ||  get<2>(t1)>get<2>(t2))
            return get<2>(t1)<get<2>(t2);
        else if(get<3>(t1)<get<3>(t2) ||  get<3>(t1)>get<3>(t2))
            return get<3>(t1)<get<3>(t2);
        else if(get<4>(t1)>get<4>(t2) ||  get<4>(t1)<get<4>(t2))
            return get<4>(t1)>get<4>(t2);
        
        locale loc1;
        locale loc2;
        string t1u, t2u;
        t1u="";
        t2u="";
        for(int i=0; i<get<5>(t1).length();i++)
            t1u+=toupper(get<5>(t1)[i], loc1);
        for(int i=0; i<get<5>(t2).length();i++)
            t2u+=toupper(get<5>(t2)[i], loc2);
        return lexicographical_compare(t1u.begin(),t1u.end(), t2u.begin(), t2u.end());
    }

};


int main(){
    int cases;

    cin >> cases;
    cin.ignore();
    for(int i=0; i< cases; i++){
        if(i!=0) cout << endl;
        string tname;
        unordered_map<string, stats> tourn;
        getline(cin,tname);
        int numt;
        cin >> numt;
        cin.ignore();
        for(int j=0;j<numt;j++){
            string team;
            getline(cin, team);
            stats teamstats = make_tuple(0,0,0,0,0,team);
            tourn[team]=teamstats; 
        }
        int games;
        cin >> games;
        cin.ignore();
        for(int j=0; j< games;j++){
            string game;
            int goals1, goals2;
            string team1, team2, aux;
            getline(cin, game);
            istringstream iss(game);
            getline(iss,team1,'#');
            getline(iss,aux,'@');
            goals1=stoi(aux);
            getline(iss,aux,'#');
            goals2=stoi(aux);
            getline(iss,team2);
            // Update values
            get<2>(tourn[team1])+=(goals1-goals2);
            get<2>(tourn[team2])+=(goals2-goals1);
            get<3>(tourn[team1])+=goals1; 
            get<3>(tourn[team2])+=goals2; 
            get<4>(tourn[team1])++; 
            get<4>(tourn[team2])++; 

            if(goals1>goals2){
                get<0>(tourn[team1])+=3;
                get<1>(tourn[team1])++;
            }else if(goals2>goals1){
                get<0>(tourn[team2])+=3;
                get<1>(tourn[team2])++;
 
            }else{
                get<0>(tourn[team1])++;
                get<0>(tourn[team2])++;            
            }
        }
        priority_queue<stats, vector<stats>, comp> pq;
        for(pair<string, stats> s:tourn){
            pq.push(s.second);
        }
        cout << tname <<endl;
        int rank=1;
        while(!pq.empty()){
            stats info = pq.top();
            pq.pop();
            int against=get<3>(info)-get<2>(info);
            int ties = (get<0>(info)/3)-get<1>(info);
            int loses = get<4>(info) - ties - get<1>(info);
            cout << rank <<") "<<get<5>(info)<<" ";
            printf("%dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
                   get<0>(info),
                   get<4>(info), get<1>(info), ties, loses,
                   get<2>(info), get<3>(info), against);
            rank++;
        
        }
    }
    return 0;
}












