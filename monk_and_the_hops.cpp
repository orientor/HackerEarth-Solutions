#include <iostream>
#include<utility>
#include<vector>
#include<set>
using namespace std;
vector<int> we(100001,1000000000);
vector<bool> ve(100001,true);
vector<int> fl(100001,0);
vector<short> kl(100001,4);
void fj(int lj,int cd)
{if(kl[lj]==kl[cd] || kl[cd]==3)
           fl[lj]=fl[cd];
           else
           fl[lj]=(fl[cd]+1);}
void dj(vector<vector<pair<int,int> > > a)
{
	kl[1]=3;
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
           {kl[lj]=bj%2;
           fj(lj,cd);
           
                we[lj]=xk+bj;
                s.insert({we[lj],lj});
                continue;
            }
            else if(xk+bj==we[lj] && fl[lj]>=fl[cd])
            {
            	if(fl[lj]>fl[cd])
            	{fl[lj]=bj%2;
            	fj(lj,cd);
            	continue;
            	}
            	if(bj%2!=kl[lj])
            	kl[lj]=3;
            	
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
        a[c].push_back(make_pair(d,b));
    }
    dj(a);
    cout<<we[N]<<" "<<fl[N];

    
    return 0;
}