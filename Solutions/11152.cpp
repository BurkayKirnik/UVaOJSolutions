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

int r,l,k,m,n,ans;

//-------------END OF DRAFT-------------

double pi = acos(-1);
int main() {
	double c , b , a;
	while(cin>>a>>b>>c) {
		double p = a+b+c;
		double s = p/2;
		double aT = sqrt( s * (s-a) * (s-b) * (s-c));
		
		double rIn = sqrt((s-a)*(s-b)*(s-c)/s);
		double aIn =  pi*rIn*rIn;
		double rCircum = (a*b*c) / (4*aT);
		double aCircum = pi*rCircum*rCircum;
		printf("%.4f %.4f %.4f\n" , aCircum - aT , aT-aIn , aIn);
	}
	return 0;
}
