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
    node *next ;
    int val ;
    node(){
        next = NULL ;
        val = 0 ;
    }

}*root , *tail;

 void insert(ll x){
     if(tail == NULL){
        tail = root ;
        tail->val = x ;
        return ;
    }
     node *newNode = new node() ;
     newNode -> val = x ;
     tail -> next = newNode ;
     tail  = tail -> next ;
 }

 void print(){
    node *temp = root ;
    while(temp != NULL){
        cout << temp->val << " " ;
        temp = temp -> next ;
    }
    cout << endl;
    return;
 }

void solve(){
     root = new node() ;
     tail = NULL ;
     ll n ;
     cin >> n ;
     for( ll i = 0 ; i < n ; i++){
        ll x ;
        cin >> x ;
        insert(x) ;
        print() ;
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
