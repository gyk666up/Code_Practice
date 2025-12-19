// //easy Hhh
// #include<bits/stdc++.h>
// using namespace std;
// map<string,int>mp;//存名字和分数
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int q;cin>>q;
//     while(q--)
//     {
//         int op;cin>>op;int score;string name;
//         if(op==1)
//         {
//             cin>>name>>score;
//             mp[name]=score;
//             cout<<"OK\n";
//         }
//         else if(op==2)
//         {
//             cin>>name;
//             if(mp.count(name))cout<<mp[name]<<endl;
//             else cout<<"Not found\n";
//         }
//         else if(op==3)
//         {
//             cin>>name;
//             if(mp.count(name))
//             {
//                 mp.erase(name);
//                 cout<<"Deleted successfully\n";
//             }
//             else cout<<"Not found\n";
//         }
//         else 
//         {
//             cout<<mp.size()<<endl;
//         }
//     }
//     return 0;
// }







#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int op,score;string name;
        cin>>op;
        if(op==1)
        {
            cin>>name>>score;
            mp[name]=score;
            cout<<"OK\n";
        }
        else if(op==2)
        {
            cin>>name;
            if(mp.count(name))cout<<mp[name]<<endl;
            else cout<<"Not found\n";
        }
        else if(op==3)
        {
            cin>>name;
            if(mp.count(name))
            {
                mp.erase(name);
                cout<<"Deleted successfully\n";
            }
            else cout<<"Not found\n";;
        }
        else if(op==4)cout<<mp.size();
    }
    return 0;
}


























