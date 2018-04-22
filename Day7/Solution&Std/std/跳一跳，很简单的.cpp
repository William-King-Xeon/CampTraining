#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std ;
typedef unsigned long long ull ;
const int maxn = 1e5 + 10 ;

int T , n ;
struct Pedge
{
    int p , k ;
    char aph ;
}P[maxn] ;

//建树
int head[maxn] , len ;
struct Edge
{
    int to , next ;
    Edge(){}
    Edge( int t , int n ) : to( t ) , next( n ) {}
}e[maxn] ;

void init()
{
    memset( head , -1 , sizeof( head ) ) ;
    len = 0 ;
}

void add_edge( int u , int v )
{
    e[len] = Edge( v , head[u] ) ;
    head[u] = len++ ;
}

//树的处理
int par[maxn][20] ;
void par_pre()
{
    par[1][0] = 1 ;
    for( int j = 1 ; j < 20 ; ++j )
    {
        for( int i = 1 ; i <= n ; ++i )
        {
            par[i][j] = par[par[i][j - 1]][j - 1] ;
        }
    }
}
//u节点向上走k步
int goback_k( int u , int k )
{
    for( int j = 19 ; j >= 0 ; --j )
    {
        if( k & ( 1 << j ) )
        {
            k -= ( 1 << j ) ;
            u = par[u][j] ;
        }
    }

    return u ;
}


//hash
ull Hash[maxn][26] , pow_base[maxn] ;
const ull base = 131 ;
const ull mod = 1e9 + 7 ;

char change( char c , long long k , long long t )
{
    k %= 26 ;
    t *= k ;
    t %= 26 ;

    return ( c - 'a' + t ) % 26 + 'a' ;
}

void dfs_hash( int u , int t )
{
    char aph = change( P[u].aph , P[u].k , t ) ;
    Hash[u][t] = ( Hash[P[u].p][t] * base % mod + (aph - 'a') % mod ) % mod ;

    for( int i = head[u] ; ~i ; i = e[i].next )
    {
        printf( "%d\n" , i ) ;
        dfs_hash( e[i].to , t ) ;
    }
}

void bfs_hash( int t )
{
    queue<int> que ;
    que.push( 1 ) ;


    while( que.size() )
    {
        int u = que.front() ; que.pop() ;

        for( int i = head[u] ; ~i ; i = e[i].next )
        {
            int to = e[i].to ;
            char aph = change( P[to].aph , P[to].k , t ) ;
            Hash[to][t] = ( Hash[u][t] * base % mod + (aph - 'a') % mod ) % mod ;
            que.push( to ) ;
        }
    }

}

void init_hash()
{
    for( int i = 0 ; i < 26 ; ++i )
    {
        //dfs_hash( 1 , i ) ;
        bfs_hash( i ) ;
    }

    pow_base[0] = 1;
    for(int i = 1; i <= 100001; i++ )
    {
        pow_base[i] = pow_base[i - 1] * base % mod ;
    }
}

bool hash_cmp( int u , int v , int len , int t )
{
    int fu = goback_k( u , len - 1 ) ;
    int fv = goback_k( v , len - 1 ) ;
    if( fu == 1 || fv == 1 ) return false ;
    ull hash1 = ( Hash[u][t] - Hash[par[fu][0]][t] * pow_base[len] % mod + mod ) % mod ;
    ull hash2 = ( Hash[v][t] - Hash[par[fv][0]][t] * pow_base[len] % mod + mod ) % mod ;

    return hash1 == hash2 ;
}

//解决
char solve( int u , int v , int t )
{
    if( change( P[u].aph , P[u].k , t ) > change( P[v].aph , P[v].k , t ) )
    {
        return '>' ;
    }
    if( change( P[u].aph , P[u].k , t ) < change( P[v].aph , P[v].k , t ) )
    {
        return '<' ;
    }
    int l , r ;
    l = 1 ; r = n + 1 ;

    while( r - l > 1 )
    {
        int mid = ( l + r ) >> 1 ;
        if( hash_cmp( u , v , mid , t ) )
            l = mid ;
        else r = mid ;
    }

    int fu = goback_k( u , l ) ;
    int fv = goback_k( v , l ) ;
    if( change( P[fu].aph , P[fu].k , t ) > change( P[fv].aph , P[fv].k , t ) )
    {
        return '>' ;
    }
    if( change( P[fu].aph , P[fu].k , t ) < change( P[fv].aph , P[fv].k , t ) )
    {
        return '<' ;
    }
    return '=' ;
}
string s1 = "" , s2 = "" ;

int main( )
{
    freopen( "jump10.in" , "r" , stdin ) ;
    freopen( "jump10.out" , "w" , stdout ) ;

    P[1].p = 0 , P[1].aph = 0 , P[1].k = 0 ;
    P[0].p = 0 , P[0].aph = 0 , P[0].k = 0 ;
 

        scanf( "%d" , &n ) ;
        init() ;
        //输入
        for( int i = 2 ; i <= n ; ++i )
        {
            scanf( "%d%*c%c%d" , &P[i].p , &P[i].aph , &P[i].k ) ;
            add_edge( P[i].p , i ) ;
            par[i][0] = P[i].p ;
        }

        par_pre() ;
        init_hash() ;

        int Q ;
        scanf( "%d" , &Q ) ;

        for( int i = 0 ; i < Q ; ++i )
        {
            s1 = "" ; s2 = "" ;
            int u , v , t ;
            scanf( "%d %d %d" , &u , &v , &t ) ;
            printf( "%c\n" , solve( u , v , t % 26 ) ) ;
//            char c2 = solve( u , v , t % 26 ) ;
//
//            while( u != 1 )
//            {
//                s1 += change( P[u].aph , P[u].k , t ) ;
//                u = P[u].p ;
//            }
//            while( v != 1 )
//            {
//                s2 += change( P[v].aph , P[v].k , t ) ;
//                v = P[v].p ;
//            }
//            char cmp ;
//
//            if( s1 == s2 ) cmp = '=' ;
//            if( s1 < s2 ) cmp = '<' ;
//            if( s1 > s2 ) cmp = '>' ;
//            if( cmp != c2 )
//            {
//                printf( "i = %d \n" , i ) ;
//                break ;
//            }
            //cout << s1 << "\n" << s2 << endl ;
        }
  
    return 0 ;
}
