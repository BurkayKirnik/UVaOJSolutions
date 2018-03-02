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

struct point {
	double x;
	double y;
	
	point() {
		x=y=0;
	}
	
	point(double _x , double _y) : x(_x), y(_y) {}
	
	bool operator==(point other) {
		return (fabs(x-other.x) < eps && fabs(y-other.y) <eps);
	}
};

struct line {
	
	double a,b,c;
};

double dist(point p1 , point p2) {
	return fabs( sqrt( (p1.x - p2.x) * (p1.x - p2.x ) + (p1.y - p2.y) * (p1.y - p2.y) ) );
}

bool areParallel(line l1 , line l2) {
	return ( fabs(l1.a - l2.a) < eps && fabs(l1.b - l2.b) < eps );
}

bool interp(line l1, line l2, point &p) {
	if(areParallel(l1 , l2)) return false;
	
	p.x = ( l1.c * l1.b - l2.c *l2.b) / (l2.a *l1.b - l1.a * l2.b);
	
	if(fabs(l1.b) >eps) {
		p.y = -(l1.a * p.x + l1.c);
	}
	else {
		p.y = -(l2.a * p.x + l2.c);
	}
	return true;
}

bool spoint(point p1 , point p2) {
	if(p1.x != p2.x) {
		return p1.x>p2.x;
	}
	else {
		return p1.y>p2.y;
	}
}

line toline(point p1 , point p2) {
	line l;
	if(fabs(p1.x- p2.x) < eps) {
		l.a = 1 , l.b = 0 , l.c = -p1.x;
		return l;
	}
	l.b = 1;
	l.a = -(p1.y - p2.y) / (p1.x - p2.x);
	l.c = -(l.a * p1.x) - p1.y;
	return l;
}

int main() {
	//READ("input.txt")
	int TC;
	cin>>TC;
	while(TC--) {
		int number;
		cin>>number;
		vector<point> points; 
		point p;
		
		for(int i=0; i<number; i++) {
			cin>>p.x>>p.y;
			points.pb(p);
		}
		sort(points.begin() , points.end() , spoint);
		
		
		line yline = toline(point(0,0) , points[0]);
		point inters_p;
		double ans=0;
		for(int i=1; i<points.size() ; i++) {
			point startp = points[i-1] , endp = points[i];
			point lowery = (startp.y > endp.y) ? endp : startp;
			point uppery = (startp.y > endp.y) ? startp : endp;
			if(interp(toline(startp , endp) , yline , inters_p)) {	
				if(inters_p.y <= uppery.y) {
					ans += dist(uppery , (inters_p.y > lowery.y) ? inters_p : lowery );
				}
			}
			if(uppery.y > yline.c * -1) {
				yline.c = -uppery.y;
			}
		}
		printf("%.2f\n" , ans);
	}
	return 0;
}
