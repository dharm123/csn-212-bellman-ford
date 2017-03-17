#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<iomanip>
#include<stdio.h>
#include<limits>
#include<map>
#include<set>
#include<list>
#include<vector>
#include <ctime>
#include<stack>
#define gcd __gcd
#define pb(x) push_back(x)
#define ll long long
#define in(x) scanf("%d",&x)
#define mod 1000000007LL
#define size(x) x.size()
#define mst(x,a) memset(x,a,sizeof(x))
#define pii pair<ll,ll>
#define F first
#define S second
#define m_p make_pair
#define all(v) (v.begin(),v.end())
#define inf 1000000000
using namespace std;
vector<pii> g;
map<pii,int>wt;
void solution(int wer,int n)
{
	int distance[n+1];
	for(int i=1;i<=n;i++)
		distance[i]=inf;
	distance[wer]=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<size(g);j++)
		{
			int u=g[j].F;
			int v=g[j].S;
			if(distance[u]+wt[m_p(u,v)]<distance[v]&&distance[u]!=inf)
				distance[v]=distance[u]+wt[m_p(u,v)];
		}

	}
	for(int i=0;i<size(g);i++)
	{
		int u=g[i].F;
		int v=g[i].S;
		if(distance[u]+wt[m_p(u,v)]<distance[v]&&distance[u]!=inf)
		{
			cout<<"contains negative cycle\n";
			break;
		}
	}
	cout<<"distances from "<<wer<<"------>";
	for(int i=1;i<=n;i++)
	{
			cout<<distance[i]<<" ";
	}
	cout<<endl;
	return;
}
int main()
{
    	
    cout<<"no.of vertices ?\n";
  	int n=100;
  	cin>>n;
  	cout<<"adjacency matrix ?\n";
  	int a[n+1][n+1];
  	for(int i=1;i<=n;i++)
  		for(int j=1;j<=n;j++)
  		{
  			cin>>a[i][j];
  			//a[i][j]=rand()%11;
  			if(a[i][j]!=0&&i!=j)
  			{
  				g.pb(m_p(i,j));
  				wt[m_p(i,j)]=a[i][j];
  			}
  		}
  	int start_s=clock();
  	for(int i=1;i<=n;i++)
  		solution(i,n);
  	int stop_s=clock();
  	cout<<size(g)<<endl;
	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
   return 0;
}
