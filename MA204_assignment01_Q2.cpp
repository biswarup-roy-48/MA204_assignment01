#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<ll> vi;

ld func(ld x){
	return 2 - (5*x*x) - exp(x);
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ld num;
	ld epsilon=0.00001;
	ld a=0;
	ld b=1; 
	
	
	if(func(a)*func(b)>0) {
		cout<<"No roots between " << a<<" and "<<b<<"\n";
		return 0;
	}
	ld c;
	while((b-a) >= epsilon){
		
		c=(a+b)/2.0;
		if(func(c)==0.0){
			break;
		}

		else if(func(a)*func(c)<0){
			b = c;
		}
		else{
			a = c;
		}
	}
	
	// cout<<"Root is = "<<c<<"\n";
	printf("Root is = %.5f\n", c);



	
	return 0;
}