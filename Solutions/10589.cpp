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
double pi = cos(-1);
unsigned long long r,l,k,m,n,ans;

//-------------END OF DRAFT-------------

struct point {
	double x , y;
	point() {
		x=y=0;
	}
	point(double _x ,double _y) : x(_x) , y(_y) {}
};

double dist(point p1 , point p2) {
	return sqrt( (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) );
}
int main() {
//	READ("input.txt")
	double a;
	while(cin>>n>>a, n!=0) {
		point p1(0,0) , p2(0,a) , p3(a,0) , p4(a,a);
		unsigned long long m = 0;
		point temp;
		for(int i=0; i<n ; i++) {
			cin>>temp.x>>temp.y;
			if( dist(temp , p1) <= a && dist(temp,p2)<=a && dist(temp , p3) <=a && dist(temp , p4) <=a ) {
				m++;
			}
		}
		printf("%.5f\n",m*a*a/n);
	}
	return 0;
}
