#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pob pop_back
#define st first
#define nd second
#define test printf("test\n");
#define endll printf("\n")
#define mp make_pair
#define sol (node*2)
#define sag ((node*2)*1)
#define orta (bas+son)/2
#define eps 1e-6


#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )

typedef long long ll;
typedef long long int lli;
typedef long long unsigned llu;
typedef pair < int,int > pii;
typedef pair < ll,lli > plli;

const int MAX = 1e5+7, N=1e5+3;

//-------------END OF DRAFT-------------


int main() {
	int n;
	double pi = 2*acos(0);
	cin>>n;
	double d,l;
	double ans;
	double a,b,c;
	for(int i=0; i<n; i++) {
		cin>>d>>l;
		d/=2;
		l/=2;
		a = sqrt(l*l - d*d);
		printf("%.3f\n" , pi*a*l);
	}
	return 0;
}
