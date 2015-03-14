#include <iostream>
#include "MillerRabin.h"

using namespace std;

double modpow(double base, long long exp, double modulus);

bool Miller(long long p,int iteration);
int modulo(int a,int b,int c);
long long mulmod(long long a,long long b,long long c);

int main()
{
	
	utk::MillerRabin j;
	long long start,stop;
	j.setiter(60);
	
	cout<<"Define start =";
	cin>>start;
	cout<<"\nDefine stop =";
	cin>>stop;
	j.printprime(start,stop);


	//cout<<endl<<j.testcomposite(9007199254740881,4);
	//cout<<rand()<<endl;
	//long long *a=j.randgen(1000,8);
	//for(int i=0;i<8;i++)
	//{
		//cout<<endl<<a[i];
	//}
	
	//cout<<j.testprime(999999999);
	//cout<<j.modulo(5396,8*562949953,9007199249);
	//cout<<Miller(9007199249,60);
	//cout<<endl<<modpow(5396,45035996273704959,90071992547409913);

	//cout<<j.modulo(2,4,15);
	//cout<<endl<<modpow(2,4,15);
	//cout<<endl<<j.mod(31175,617283957391,1234567914783);
	//cout<<endl<<a;
	//cout<<j.modulo(200899,4798999,15);
   
	//cout<<endl<<j.mod(200899,4798999,15);
	cout<<endl;
	system("pause");
	
}

double modpow(double base, long long exp, double modulus) {
  base =fmod(base,modulus);
  double result = 1;
  while (exp > 0) {
    if (exp & 1) result = fmod((result * base) ,modulus);
    base = fmod((base * base) , modulus);
    exp >>= 1;
  }
  return result;
}

bool Miller(long long p,int iteration){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}

int modulo(int a,int b,int c){
    long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; // squaring the base
        b /= 2;
    }
    return x%c;
}

long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}