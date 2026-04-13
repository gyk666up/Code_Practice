// #include<bits/stdc++.h> 

// using namespace std;

// string s;


// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);
// 	cin>>s;
// 	int ans=0;
// 	int f=0;
// 	int sum=0;
// 	int num=0;
// 	for(int i=0;i<s.size();i++) {
// 		if(s[i]=='(') {
// 			if(f==1) {
// 				num=0;
// 				sum=0;
// 			}
// 			else f=1;
// 		}
// 		else if(s[i]==')') {
// 			f=0;
// 			ans=max(ans,sum);
// 			sum=0;
// 			num=0;
// 		}
// 		else if(s[i]=='.'&&f==1) {
// 			sum+=num;
// 			num=0;
// 		}
// 		else {
// 			if(f==1) {
// 			num=num*10+s[i]-'0';
// 		}
// 		}
// 	}
// 	cout<<ans;
// 	return 0;
// }




#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;cin>>s;
    bool f=0;//f=1表示已经在括号里面了
    int num=0;
    int sum=0;
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
        {
            if(f)
            {
                num=0;
                sum=0;
            }
            else f=1;
        }
        else if(s[i]==')')
        {
            f=0;
            ans=max(ans,sum);
            sum=0;
            num=0;
        }
        else if(s[i]=='.'&&f)
        {
            sum+=num;
            num=0;
        }
        else if(f)
        {
            num=num*10+s[i]-'0';
        }
    }
    cout<<ans;
    return 0;
}