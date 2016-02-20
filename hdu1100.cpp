#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define PB push_back

typedef long long ll;

const int maxn=500000000;
vector<ll> sum,tree;

void init() {
    sum.PB(0);
    tree.PB(1);
    while(*sum.rbegin()<maxn) {
        tree.PB(0);
        for(int i=0;i<tree.size()-1;i++)
            *tree.rbegin()+=tree[i]*tree[tree.size()-i-2];
        sum.PB(*sum.rbegin()+*tree.rbegin());
    }
}

void dfs(int p) {
    if(!p)
        return ;
    int m=lower_bound(sum.begin(),sum.end(),p)-sum.begin();
    p-=sum[m-1];//该棵树在相同节点数的树中的序数
    int k=0,lp=1,rp;
    while(p>tree[m-1-k]*tree[k]&&m-1-k-1>=0) {
        p-=tree[m-1-k]*tree[k];
        k++;
    }//求左子树节点数
    if(k) {
        while(p>tree[m-1-k]) {
            p-=tree[m-1-k];
            lp++;
        }
        lp+=sum[k-1];//左子树序数
        printf("(");
        dfs(lp);
        printf(")");
    }
    printf("X");
    if(m-1-k) {
        rp=p+sum[m-1-k-1];//右子树序数
        printf("(");
        dfs(rp);
        printf(")");
    }
}

int main() {
	freopen("test.in", "r", stdin);
    init();
    int n;
    while(cin >> n,n) {
        dfs(n);
        cout << endl;
    }
    return 0;
}
