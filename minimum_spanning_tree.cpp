#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int id[10001];
int edges;
void initialize(int n)
{
	for(int i=0;i<(n+1);i++)
	id[i]=i;
}
int root(int i)#include <iostream>
#in
{
	while(id[i]!=i)
	{
		id[i]=id[id[i]];
		i=id[i];
	}
	return i;
}
void unixo(int x,int y)
{
	int p=root(x);
	int q=root(y);
	id[p]=id[q];
}
int kruskal(vector<pair<int ,pair<int ,int > > > a)
{int x,y;
	long long min=0,cost;
	for(int i=0;i<edges;i++)
	{
		cost=a[i].first;
		x=a[i].second.first;
	    y=a[i].second.second;
	    if(root(x)!=root(y))
	    {
	    	min+=cost;
	    	unixo(x,y);
	    }
	}
	return min;
}

int main()
{
    int n;
    
    cin>>n>>edges;
    initialize(n);
    vector<pair<int ,pair<int ,int > > > a;
    for(int i=0;i<edges;i++)
    {
    	int d,b,c;
    	cin>>b>>c>>d;
    	a.push_back(make_pair(d,make_pair(b,c)));
    	}
    	sort(a.begin(),a.end());
    	
    int	minxd=kruskal(a);
    	cout<<minxd;
    return 0;
}

