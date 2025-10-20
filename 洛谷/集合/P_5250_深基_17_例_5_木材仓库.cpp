// #include<bits/stdc++.h>
// using namespace std;
// multiset<int>q;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int m;cin>>m;
//     while(m--)
//     {
//         int op,length;cin>>op>>length;
//         if(op==1)
//         {
//             if(q.count(length))cout<<"Already Exist\n";
//             else q.insert(length);
//         }
//         else 
//         {
//             if(q.size()==0)cout<<"Empty\n";
//             else 
//             {
//                 auto it=q.lower_bound(length);
//                 int res=0;//需要删除的元素
//                 //一开始并没有考虑这两种特殊的情况了 导致一个点也通不过
//                 //要将这两种特殊的情况深深记在脑子里
//                if(it==q.end()) //所有元素都小于
//                 {
//                     res=*--it;//删除最大的
//                     cout<<res<<endl;
//                     q.erase(res);
//                 }
//                 else if(it==q.begin())//所有数都大于等于length
//                 {
//                     res=*it;//删除最小的
//                     cout<<res<<endl;
//                     q.erase(res);
//                 }
//                 else
//                 {
//                     int now=*it;int before=*--it;
//                     //注意这里的等号很细节
//                     if(now-length>=length-before)
//                     {
//                         cout<<before<<endl;
//                         q.erase(before);
//                      }
//                      else
//                     {
//                         cout<<now<<endl;
//                         q.erase(now);
//                     }
//                 }
//             }
//         }
//     }
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
int m;
set<int>q;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>m;
    while(m--)
    {
        int op,length;cin>>op>>length;
        auto it=q.lower_bound(length);
        if(op==1)
        {
            if(q.count(length))cout<<"Already Exist\n";
            else
            {
                q.insert(length);
            }
        }
        else
        {
            if(!q.size())
            {
                cout<<"Empty\n";
            }
            //所有的都比length大
            else if(it==q.begin())
            {
                cout<<*q.begin()<<endl;
                q.erase(*q.begin());
            }
            //所有的length小  注意q.end()指向最后一个元素的后一个位置
            else if(it==q.end())
            {
                cout<<*(--it)<<endl;
                q.erase(*it);
            }
            else
            {
                int now=*it;
                int before=*--it;
                if(now-length<length-before)
                {
                    cout<<now<<endl;
                    q.erase(now);
                }
                else
                {
                    cout<<before<<endl;
                    q.erase(before);
                }
            }
        }
    }
    return 0;
}