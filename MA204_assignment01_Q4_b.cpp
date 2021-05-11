#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<ll> vi;

ld func(ld x){
	return exp(x) - (x*x) + (3*x) -2 ;
}

void secant(ld x1, ld x2, ld E) {
   ld n = 0, xm, x0, c;
   if (func(x1) * func(x2) < 0) {
      do {
         //calculating the intermediate value
         x0 = (x1 * func(x2) - x2 * func(x1)) / (func(x2) - func(x1));
         c = func(x1) * func(x0);
         x1 = x2;
         x2 = x0;
         n++;
         if (c == 0)
         break;
         xm = (x1 * func(x2) - x2 * func(x1)) / (func(x2) - func(x1));
      } while (fabs(xm - x0) >= E);
      
      printf("Root (using secant method) = %.5f\n", x0);
      cout << "No. of iterations = " << n << endl;
   } else
   cout << "Can not find a root in the given inteval\n";
}

void regulaFalsi(ld a , ld b,  ld epsilon){
    int n=0;
	if(func(a)*func(b)>0) {
		cout<<"Can not find a root in the given inteval\n";
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
		n++;
	}
	
	printf("Root (using regula falsi method) = %.5f\n", c);
	cout << "No. of iterations = " << n << endl;
} 


int main()
{
	ld epsilon = 0.0001;
	regulaFalsi(0 , 1 , epsilon);
	secant(0, 1 , epsilon);
	
	return 0;
}