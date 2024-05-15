//
AtCoder Beginner Contest 353(D)
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
   node *ar[28] ;
   int cnt[28] ;
   node(){
     for(int i = 0 ; i < 27 ; i++) ar[i] = NULL , cnt[i] = 0 ;
   
   }
}*root;

void build(string a){
    node *temp = root ;
    for(ll i = 0 ; i < (ll)a.size(); i++){
       if(temp->ar[a[i] - 'a'] == NULL){
        temp->ar[a[i] - 'a'] = new node() ;
       }
       temp->cnt[a[i]-'a']+=1 ;
       temp = temp->ar[a[i] - 'a'] ;
    }
    return;
}

ll count(string s){
    ll ans = 0 ;
    node *temp = root ;
    for(ll i = 0 ; i < (ll)s.size(); i++){
            if(temp->ar[s[i] - 'a'] == NULL) break ;
            ans+=temp->cnt[s[i] - 'a'] ;
   
            temp = temp -> ar[s[i] - 'a'] ;
    }
    return ans;
}

void solve(){
     
        root = new node() ;
        ll n ;
        cin >> n ;
        string v[n+1] ;
             for(int i = 0 ; i < n ; i++){
                cin >> v[i] ;
            } 

        ll ans = 0 ;
        for(ll i = n - 1; i >= 0 ; i--){
             ans = ans + count(v[i]) ;
             build(v[i]) ;
        }

        cout << ans << endl;
          

}





int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif 
    int test = 1 ;     //cin >> test;
    while(test--){solve();}
    return 0 ;
}
