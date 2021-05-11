#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<ll> vi;

// assuming the function of question 1 to be x^2 -2
ld func(ld x){
	return x*x - 2;
}
// function 2 is given as 2 - 5*(x)^2 - e^x
ld func2(ld x){
	return 2 - (5*x*x) - exp(x);
}

void regulaFalsi1 ( ld epsilon , ld a , ld b){
	if(func(a)*func(b)>0) {
		cout<<"No roots between " << a<<" and "<<b<<"\n";
		return ;
	}
	ld c;
	while((b-a)>=epsilon){
		
		c = (a*func(b) - b*func(a))/ (func(b) - func(a));
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
	
	printf("Root is = %.7f\n", c);
} 


void regulaFalsi2 ( ld epsilon , ld a , ld b){
	if(func2(a)*func2(b)>0) {
		cout<<"No roots between " << a<<" and "<<b<<"\n";
		return ;
	}
	ld c;
	while((b-a)>=epsilon){
		
		c = (a*func2(b) - b*func2(a))/ (func2(b) - func2(a));
		if(func2(c)==0.0){
			break;
		}

		else if(func2(a)*func2(c)<0){
			b = c;
		}
		else{
			a = c;
		}
	}
	
	printf("Root is = %.5f\n", c);
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ld epsilon1=0.0000001;
	ld epsilon2=0.00001;


	// for question 1
	regulaFalsi1(epsilon1, 1 , 2 );

	// for question 2
	regulaFalsi2(epsilon2, 0 , 1 );


	return 0;
}