#include <cstdio>
#include <cstdlib>
#include <climits>


const int MAX = 550;

//�洢11�����͵����أ���ά�е�0 1 2 3�ֱ�����������͵����ص���������
//Ϊ1��ʾ��������нӿڣ�Ϊ0��ʾ�������û�нӿ�
const int type[11][4]={{1,1,0,0},{0,1,1,0},
						{1,0,0,1},{0,0,1,1},
						{0,1,0,1},{1,0,1,0},
						{1,1,1,0},{1,1,0,1},
						{1,0,1,1},{0,1,1,1},
						{1,1,1,1}
						};

const bool VERTICAL = true;

//pre������������Ĳ��鼯�����ã������ںϲ���ʱ��Ҫע�⽫��ά����ת����һά�ı�ţ��˴���������
int pre[MAX*MAX+1],cnt,m,n;
char farm[MAX][MAX];



void init(int n){
	int i;
	for(i=1;i<=n;++i){
		pre[i] = i;
	}
	cnt = n;
}

int root(int x){
	if(x!=pre[x]){
		pre[x] = root(pre[x]);
	}
	return pre[x];
}

void merge(int ax,int ay,int bx,int by,bool dir){
	if(bx>n || by>m)return;//������ͼ�Ĳ��ֲ����кϲ�
	bool mark = false;//��ʶ������Ƿ����
	int ta,tb;//���������ֵ0-10

	ta = farm[ax][ay]-'A';
	tb = farm[bx][by]-'A';

	if(dir){//��ֱ�����жϿ�����
		if(type[ta][3] && type[tb][1])mark = true;
	}else{//ˮƽ�����жϿ�����
		if(type[ta][2] && type[tb][0])mark = true;
	}

	if(mark){//ֻҪ�����ͺϲ�������������Ĳ��鼯��
		int fx = root((ax-1)*m+ay);
		int fy = root((bx-1)*m+by);
		if(fx!=fy){
			pre[fy] = fx;
			--cnt;
		}
	}
}


int main(){
	//freopen("in.txt","r",stdin);
	int i,j;
	while(scanf("%d %d",&n,&m)!=EOF){
		if(n==-1 && m==-1)break;
		init(n*m);
		for(i=1;i<=n;++i){
			scanf("%s",farm[i]+1);
		}
		for(i=1;i<=n;++i){
			for(j=1;j<=m;++j){
				merge(i,j,i+1,j,VERTICAL);
				merge(i,j,i,j+1,!VERTICAL);
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
