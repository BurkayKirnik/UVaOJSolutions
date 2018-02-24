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
int ans[500003];
int main() {
	//READ("input.txt")
	ans[1] = 1;
	ans[2] = 2; 
	for(int i=3; i<=500000; i++) {
		ans[i] = ans[i-1]+2;
		if(ans[i]>i) ans[i] = 2;
	}
	while(cin>>n, n!= 0) {
		cout<<ans[n]<<endl;
	}
	return 0;
}
