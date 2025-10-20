//!!!
#include<bits/stdc++.h>
using namespace std;
const int N=305;
int dist[N][N];
bool st[N][N];
int fire[N][N];

int m;
typedef pair<int,int>PII;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int bfs(int x,int y)
{
    memset(dist,0x3f,sizeof dist);
    st[x][y]=1;
    dist[x][y]=0;
    queue<PII>q;
    q.push({x,y});
    while(q.size())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx<0||yy<0)continue;
            //新节点已经访问过 或者已经有最短路径
            if(dist[xx][yy]!=0x3f3f3f3f)continue;
            if(st[xx][yy]>0)continue;
            //到达这个地方(xx,yy)的时间晚于(xx,yy)流星砸下来的时间+1!!!
            if(dist[x][y]+1>=fire[xx][yy])continue;

            st[xx][yy]=1;
            dist[xx][yy]=dist[x][y]+1;
            if(fire[xx][yy]>1e9)
            {
                return dist[xx][yy];
            }
            q.push({xx,yy});
        }

    }
    //上述条件不满足的情况 返回-1
    return -1;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>m;
    memset(fire,0x3f,sizeof fire);
    for(int i=0;i<m;i++)
    {
        int x,y,t;cin>>x>>y>>t;
        fire[x][y]=min(t,fire[x][y]);//可能会砸到同一个地方
        for(int j=0;j<4;j++)
        {
            int xx=x+dx[j];
            int yy=y+dy[j];
            //流星最远可以到301   注意流星可以到-1 但人到不了 所以就不用考虑了 另一方面就是数组下标不可以是负数
            //if(xx<-1||xx>301||yy<-1||yy>301)continue;
            if(xx<0||xx>301||yy<0||yy>301)continue;
            fire[xx][yy]=min(fire[xx][yy],t);//可能会有两个流星波及同一个地方 
            
        }
    }
    cout<<bfs(0,0);
    return 0;
}