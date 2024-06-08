#include<bits/stdc++.h>
using namespace std;
#define ll       long long
const ll int INF = 9223372036854775807 , nmax = 2501 , block = 350 , N = 3e6+20, mod = 998244353 ;
ll val = 998244353;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair < ll , ll > , null_type, less<pair <ll , ll > >, rb_tree_tag,
             tree_order_statistics_node_update>
  ordered_set;
 //order_of_key(k) Number of items striclty smaller than k
  //find_by_order(k) K-th element in a set (counting from index zero)

struct node{
    node *c[27];
    int flag[27] ;
    node(){
       for(int i = 0 ; i < 27 ; i++) c[i] = NULL , flag[i] = 0 ;
    }

}*root , *tail;

void build(string s){
    node *temp = root ;
    for(ll i = 0 ; i < (ll)s.size() ; i++){
        if(temp->c[s[i] - 'a'] == NULL) temp->c[s[i] - 'a'] = new node() ;
        temp = temp->c[s[i] - 'a'] ;     
    }
    temp->flag[s[s.size() - 1] - 'a'] = 1 ;
}

bool search(string s){
    node *temp = root ;
    for( ll i = 0 ; i < (ll)s.size() ; i++){
        if(temp->c[s[i] - 'a'] == NULL) return false ;
        temp = temp->c[s[i] - 'a'] ; 
    }
    return (temp->flag[s[s.size() - 1] - 'a'] == 1) ;
}

void solve(){
     root = new node() ;
     ll n , q ;
     cin >> n >> q;
     string s ;
     for( ll i = 0 ; i < n ; i++){
        cin >> s ;
        build(s) ;
     }

     for( ll i = 0 ; i < q ; i++){
        string s ;
        cin >> s ;
        ll ok = search(s) ;
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
     }

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif 
    int test = 1 ;    // cin >> test;
    while(test--){solve();}
    return 0 ;
}
