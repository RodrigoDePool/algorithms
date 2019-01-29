#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int tam;
    cin >> tam;
    while(tam>0){
        vector<float> nums(tam, 0);
        float min, total, curr;
        int day;
        total = 0;
        for(int i=0; i<tam;i++){
            cin >> nums[i];
            total += nums[i];
        }
        day = 0;
        curr = 0;
        min = abs(total);
        for(int i=0; i<tam; i++){
            curr += nums[i];
            if(abs(total - 2*curr) < min){
                min = abs(total - 2*curr);
                day = i+1;
            }
        }
        cout << day << endl;
        cin >> tam;
    }
    return 0;
}
