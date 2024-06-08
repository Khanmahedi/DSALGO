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
    int key;
    node *left , *right;
}*root;

struct node* newNode(int item){
    node *temp = new node() ;
    temp->key = item ;
    temp->left = NULL ;
    temp-> right = NULL ;
    return temp ;
}

node* insert(node *node, int key){
    if(node == NULL)
        return newNode(key) ;
    if(key < node -> key) node -> left = insert(node->left, key) ;
    else if(key > node->key) node -> right = insert(node->right, key) ;

}

bool siThere(ll key, node *node){
    if(key == node->key) {
        return true ;
    }
    if(key < node->key) if(siThere(key, node->left)) return true ;
    else if(key > node -> key) if(siThere(key , node->right)) return true ;
    return false ;
}
void solve(){
    ll n ;
    cin >> n;
    for( ll i = 0 ; i < n ; i++){
        ll x ; cin >> x ;
        if(i == 0) root = insert(root, x) ;
        else insert(root,x) ;
    }

    ll q ;
    cin >> q ;
    for( ll i = 0 ; i < q ; i++){
        ll x ;
        cin >> x;
        if(siThere(x, root)) cout << "YEs" << endl; 
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
