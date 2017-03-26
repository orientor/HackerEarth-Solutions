#include <iostream>
#include<utility>
#include<vector>
#include<set>
using namespace std;
vector<int> we(10001,1000000000);
vector<bool> ve(10001,true);
void dj(vector<vector<pair<int,int> > > a)
{
multiset<pair<int,int> > s;
s.insert({0,1});
while(!s.empty())
{
	pair<int,int> e=*s.begin();
	s.erase(s.begin());
	if(ve[e.second]==false)
	continue;
	ve[e.second]=false;
	int xk=e.first;int cd=e.second;
	
    for(unsigned int i=0;i<a[cd].size();i++)
    {
        int lj=a[cd][i].second;int bj=a[cd][i].first;
            if(xk+bj<we[lj])
           {
                we[lj]=xk+bj;
                s.insert({we[lj],lj});
            }
            
    }

}}

int main()
{
    int N,M;
    cin>>N>>M;
    vector<vector<pair<int,int> > > a(N+1);
    for(int i=0;i<M;i++)
    {
        int b,c,d;
        cin>>b>>c>>d;
        a[b].push_back(make_pair(d,c));
    }
    dj(a);
    for(int i=2;i<=N;i++)
    cout<<we[i]<<" ";

    
    return 0;
}