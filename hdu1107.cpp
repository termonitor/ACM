#include <iostream> //1107 武林
#include <vector>
using namespace std;

int map[13][13]={0},ss[13][13]={0},ww[13][13]={0},ee[13][13]={0};

struct SL//少林弟子
{
	int x,y,nl,wy,life,force;//行号 列号 内力 武艺 生命力
	bool back;
	void setForce( )
	{ force= (0.5 * nl + 0.5 * wy) * (life + 10) / 100;}
	void walk( )
	{
		map[x][y]--;   ss[x][y]--;
		if(x==12) back=true;   else if(x==1) back=false;
		if(back) x--;   else x++;
		map[x][y]++;  ss[x][y]++;
	}
};

struct WD//武当弟子
{
	int x,y,nl,wy,life,force;//行号 列号 内力 武艺 生命力
	bool back;
	void setForce( )
	{ force= (0.8 * nl + 0.2 * wy) * (life + 10) / 100;}
	void walk( )
	{
		map[x][y]--;     ww[x][y]--;
		if(y==12) back=true;   else if(y==1) back=false;
		if(back) y--;   else y++;
		map[x][y]++;   ww[x][y]++;
	}
};

struct EM//峨眉弟子
{
	int x,y,nl,wy,life,force;//行号 列号 内力 武艺 生命力
	bool back;
	void setForce( )
	{ force= (0.2 * nl + 0.8 * wy) * (life + 10) / 100;}
	void walk( )
	{
		if( (x==1&&y==12) || (x==12&&y==1) ) return ;
		map[x][y]--;  ee[x][y]--;
		if(x==12 || y==12) back=true;  else if(x==1 || y==1) back=false;
		if(back) {x--;y--;}   else {x++;y++;}
		map[x][y]++;   ee[x][y]++;
	}
};
//放置三个容器保存各派弟子
vector<SL> s;
vector<WD> w;
vector<EM> e;

void action(int x,int y)
{
	vector<SL>::iterator sit=s.begin();
	vector<WD>::iterator wit=w.begin();
	vector<EM>::iterator eit=e.begin();
	while( sit !=s.end() )
	{	if(sit->x==x && sit->y==y)  break;   sit++;}
	while( wit !=w.end() )
	{	if(wit->x==x && wit->y==y) break;  wit++;}
	while( eit !=e.end() )
	{	if(eit->x==x && eit->y==y) break;   eit++;}
	//发生战斗
	if( sit==s.end() )
	{
		wit->life-=int(eit->force);
		eit->life-=int(wit->force);
		if(wit->life<=0) {ww[wit->x][wit->y]--; map[wit->x][wit->y]--;  w.erase(wit); }
		else wit->setForce( );//更新攻击力
		if(eit->life<=0) {ee[eit->x][eit->y]--; map[eit->x][eit->y]--;  e.erase(eit); }
		else eit->setForce( );//更新攻击力
	}
	else if(wit==w.end() )
	{
		sit->life-=int(eit->force);
		eit->life-=int(sit->force);
		if(sit->life<=0) {ss[sit->x][sit->y]--; map[sit->x][sit->y]--; s.erase(sit); }
		else sit->setForce( );//如果没死。。更新攻击力
		if(eit->life<=0) {ee[eit->x][eit->y]--; map[eit->x][eit->y]--; e.erase(eit); }
		else eit->setForce( );//更新攻击力
	}
	else
	{
		sit->life-=int(wit->force);
		wit->life-=int(sit->force);
		if(wit->life<=0) {ww[wit->x][wit->y]--; map[wit->x][wit->y]--; w.erase(wit); }
		else wit->setForce( );//更新攻击力
		if(sit->life<=0)  {ss[sit->x][sit->y]--; map[sit->x][sit->y]--; s.erase(sit); }
		else sit->setForce( );//更新攻击力
	}
}

int main()
{
	int i,n,bx,by,a,b,c;
	char ch;
	cin>>i;
	while(i--)
	{
		cin>>n;
		while(cin>>ch,ch!='0')
		{
			cin>>bx>>by>>a>>b>>c;
			map[bx][by]++;
			switch(ch)
			{
			case 'W':
				WD tmp;
				tmp.x=bx; tmp.y=by; 
				tmp.back= (bx==12);
				tmp.nl=a; tmp.wy=b; tmp.life=c;
				tmp.setForce( );
				ww[bx][by]++;
				w.push_back(tmp);
				break;
			case 'S':
				SL tmp2;
				tmp2.x=bx; tmp2.y=by; 
				tmp2.back= (by==12);
				tmp2.nl=a; tmp2.wy=b; tmp2.life=c;
				tmp2.setForce( );
				ss[bx][by]++;
				s.push_back(tmp2);
				break;
			case 'E':
				EM tmp3;
				tmp3.x=bx; tmp3.y=by; 
				tmp3.back= (bx==12 || by==12);
				tmp3.nl=a; tmp3.wy=b; tmp3.life=c;
				tmp3.setForce( );
				ee[bx][by]++;
				e.push_back(tmp3);
				break;
			}
		}
		//控制每一步移动
		for(int j=1;j<=n;j++)
		{
			for(int m=1;m<=12;m++)
				for(int n=1;n<=12;n++)
					if(map[m][n]==2 && ( ss[m][n]!=2 && ww[m][n]!=2 && ee[m][n]!=2 ) ) action(m,n);
			vector<SL>::iterator sit=s.begin();
			vector<WD>::iterator wit=w.begin();
			vector<EM>::iterator eit=e.begin();
			while( sit !=s.end() )
			{sit->walk();sit++;}
			while( wit !=w.end() )
			{wit->walk();wit++;}
			while( eit !=e.end() )
			{eit->walk();eit++;}
		}
		//结束统计
		int sum=0;
		for(int j=0;j<s.size();j++) sum+=s[j].life;
		cout<<s.size()<<" "<<sum<<endl;
		sum=0;
		for(int j=0;j<w.size();j++) sum+=w[j].life;
		cout<<w.size()<<" "<<sum<<endl;
		sum=0;
		for(int j=0;j<e.size();j++) sum+=e[j].life;
		cout<<e.size()<<" "<<sum<<endl<<"***"<<endl;
		//重新初始化
		s.clear();  w.clear();  e.clear();
		for(int m=1;m<=12;m++)
			for(int n=1;n<=12;n++)
			{	map[m][n]=0;ss[m][n]=0,ww[m][n]=0,ee[m][n]=0;}
	}
	return 0;
}