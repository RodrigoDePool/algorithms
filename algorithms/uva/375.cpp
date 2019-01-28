#include <cmath>
#include <iostream>
using namespace std;

// Da WA pero va bien con los casos del debug:c
double minv=0.000001;

double get_radio(double b, double h){
    double aux = pow(b,2)/4;
    double hip = sqrt(pow(h,2)+aux);
    return sqrt(aux*(2/(1+b/(2*hip)) - 1));
}

void solve(double b, double h){
    double sum, r;
    r=get_radio(b,h);
    sum = 0;
    while(r>=minv){
	sum += 2*M_PI*r;
	b = b*(h-2*r)/h;	
	h = h-2*r;	
	r=get_radio(b,h);
    }
    printf("%13lf\n", sum);
    //int integer, decimal;
    //integer = sum;
    //decimal = round((sum-integer)*1000000);
    //printf("%6d.%06d\n",integer,decimal);
    return;
}

int main(){
    double cases, h, b;
    cin >> cases;
    for(int i=0; i<cases; i++){
	if(i!=0) cout << endl;
	cin >> b >> h;
	solve(b, h);
    } 
    return 0;
}
