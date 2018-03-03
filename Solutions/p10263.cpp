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

const int MAX = 1e8, N=1e5+3;

int r,l,k,n;

struct point {
	double x,y;
	point() { x=y=0;
	}
	
	point(double _x , double _y) : x(_x) , y(_y) {}
	
	bool operator==(point other) const {
		return ( fabs(other.x - x)<=eps && fabs(other.y - y) <= eps );
	}
};

struct segment {
	point p1 , p2;
	segment(point _p1 ,point _p2) : p1(_p1) , p2(_p2) {}
};

struct line {
	double a, b , c;
};

struct vec {
	double x , y;
	vec(double _x , double _y) : x(_x) , y(_y) {}
};

vec toVec(point p1 , point p2) {
	return vec(p2.x - p1.x , p2.y - p1.y);
}

vec scale(vec v, double s) {
	return vec(v.x * s , v.y * s);
}

double dot(vec a , vec b) {
	return a.x*b.x + a.y *b.y;
}


point translate(point p , vec v) {
	return point(p.x + v.x , p.y + v.y);
}

bool in_box(segment s , point p) {
	
	return (p.y <= max(s.p1.y , s.p2.y) and (p.y >= min(s.p1.y , s.p2.y)) and (p.x <= max(s.p1.x , s.p2.x)) and (p.x >= min(s.p1.x , s.p2.x)));
	
}

bool p_to_line(point p1 , point p2 , line &l) {
	
	if(fabs(p1.x - p2.x) < eps) {
		l.b = 0;
		l.a = 1;
		l.c = -p1.x;
		return true;
	}
	
	l.b = 1;
	l.a = -(p1.x - p2.x) / (p1.y - p2.y);
	l.c = -(p1.x * l.a + p1.y );
	return true;
}

double dist(point p1 , point p2) {
	return sqrt( (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) );
}


double dist_to_segment(segment s , point p, point &c) {
	vec ab = toVec(s.p1, s.p2), ap = toVec(s.p1 , p);
	double u = dot(ab , ap) / dot(ab,ab);
	if(u<0.0) {
		c = point(s.p1.x , s.p1.y);
		return dist(c, p);
	}
	if(u > 1.0) {
		c = point(s.p2.x , s.p2.y);
		return dist(c, p);
	}
	c = translate( s.p1 , scale(ab , u));
	return dist(p,c);
}
int main() {
	//READ("input.txt")
	point m;
	while(cin>>m.x>>m.y) {
		cin>>n;
		vector<point> points;
		point temp;
		cin>>temp.x>>temp.y;
		points.pb(temp);
		point c , ans;
		double ansdist = MAX;
		double dist=0;
		for(int i=1; i<=n ; i++) {
			cin>>temp.x >>temp.y;
			points.pb(temp);
			dist = dist_to_segment(segment(points[i-1] , points[i]) , m , c);
			//cout<<c.x<<' '<<c.y<<' '<<dist<<endl;
			if(dist<ansdist) {
				ansdist = dist;
				ans = c;
			}
		}
		printf("%.4f\n%.4f\n" , ans.x , ans.y);
	}
	return 0;
}
