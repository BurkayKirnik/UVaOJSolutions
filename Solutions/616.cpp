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

int r,l,k,m,n,ans;

int main() {
    //READ("input")
	while(cin>>n , n>=0) {
         int temp;
         int ans = 0;
         for(int k=2; k<=sqrt(n)+1; k++) {
              temp = n;
              int num;
              for(num = 0; num<k; num++) {
                       temp-=1;
                       if(temp%k != 0) break;
                       temp-=temp/k;
                   }
              if(temp%k == 0 and num == k) ans = k;
              }
         if(ans == 0) {
              cout<<n<<" coconuts, no solution"<<endl; continue;    
              }
         cout<<n<<" coconuts, "<<ans<<" people and 1 monkey"<<endl;
         }
	return 0;
}
