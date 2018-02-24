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

// -------END OF DRAFT--------

unsigned long long r,l,k,m,n,ans;

int coins[] = {1,5,10,25,50};

long long memo[7][30004];

unsigned long long ways(int type , int money) {
    if(money == 0) return 1;
    if(money < 0) return 0;
    if(type == n) return 0;

    if(memo[type][money] != -1) return memo[type][money];
    return memo[type][money] = ways(type+1 , money) + ways(type , money - coins[type]);
    }

int main() {
//	READ("input.txt")
    memset(memo,-1, sizeof memo);
    n=5;
    unsigned long long total;
    while(cin>>total) {
         ans = ways(0,total);
         if(ans == 1) {
              cout<<"There is only 1 way to produce "<<total<<" cents change."<<endl;
              
              }
         else {
              cout<<"There are "<<ans<<" ways to produce "<<total<<" cents change."<<endl;
              }
         }
	return 0;
}
