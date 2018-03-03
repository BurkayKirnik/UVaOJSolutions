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

int r,l,k,m,n;

//-------------END OF DRAFT-------------

double pi = acos(-1);

double deg_to_rad(double deg) {
	return (deg*pi/180);
}
int main() {
	//READ("input.txt")
	double area , l,w,h,theta;
	double ans;
	while(cin>>l>>w>>h>>theta) {
		double capacity = l*w*h;
		double hpose = tan(deg_to_rad(theta))*l;
		if(hpose <= h) {
			area = w*hpose*l/2;
			ans = capacity - area;
		}
		else {
			theta = 90-theta;
			double lpose = h*tan(deg_to_rad(theta));
			ans = w*h*lpose/2;
		}
		printf("%.3f mL\n",ans);
	}
	return 0;
}
