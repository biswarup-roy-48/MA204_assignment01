#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<ll> vi;

ld func(ld x, ld num){
	return x*x - num;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ld num;
	ld epsilon=0.0000001;
	cin>>num;
	ld a,b;
	cin>>a>>b;
	if(func(a,num)*func(b,num)>0) {
		cout<<"No roots between " << a<<" and "<<b<<"\n";
		return 0;
	}
	ld c;
	while((b-a)>=epsilon){
		
		c=(a+b)/2.0;
		if(func(c,num)==0.0){
			break;
		}

		else if(func(a,num)*func(c,num)<0){
			b = c;
		}
		else{
			a = c;
		}
	}
	

	printf("Root is = %.7f\n", c);



	
	return 0;
}