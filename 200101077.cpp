#include <bits/stdc++.h>
#include <string>
#define ll  long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define base 1000000007
#define rep(i,a,n)    for(ll  i=a;i<n;i++)
#define inf LLONG_MAX
 
using namespace std;
 
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
 
 
vector<ll>v[2000001];
vector<ll>dir(200001);
vector<ll>l_d(2000001);
ll g_d,cap;
ll counter=0;

ll power(ll a,ll b){
    ll s=1;
    for(int x=0;x<b;x++){
        s*=a;
    }
    return s;
}


void insert(ll b){
   ll bits=b%power(2,g_d);
   ll ind=dir[bits];
   if(v[ind].size()<cap){
      v[ind].pb(b);
   }
   else{
     if(l_d[bits]==g_d){
         for(int x=0;x<power(2,g_d);x++){
             dir[power(2,g_d)+x]=dir[x];
         }

         dir[power(2,g_d)+bits]=counter;
         counter++;
         l_d[dir[bits]]++;
         l_d[dir[power(2,g_d)+bits]]=l_d[dir[bits]];
         g_d++;

         vector<ll>temp;
         temp.pb(b);
         for(auto it:v[dir[bits]]){
             temp.pb(it);
         }
         while(v[bits].size()!=0){
             v[bits].pop_back();
         }
         for(auto it:temp){
             ll val=it%power(2,g_d);
             if(v[dir[val]].size()==cap){
                 insert(it);
                 break;
             }
             else
             v[dir[val]].pb(it);
         }
     }
     else{
        vector<ll>temp;
        bits=b%power(2,l_d[dir[bits]]);
        for(auto it:v[dir[bits]]){
            temp.pb(it);
        }
        while(v[dir[bits]].size()!=0){
            v[dir[bits]].pop_back();
        }
        temp.pb(b);

        ll adv=0;
        while(1){
           if(adv*power(2,l_d[dir[bits]])+bits>power(2,g_d)){
               break;
           }
           if(adv%2==0){
               dir[adv*power(2,l_d[dir[bits]])+bits]=dir[bits];
           }
           else{
               dir[adv*power(2,l_d[dir[bits]])+bits]=counter;
           }
           adv++;
        }


        counter++;
        l_d[dir[bits]]++;
        l_d[dir[power(2,l_d[dir[bits]]-1)+bits]]=l_d[dir[bits]];

        
        for(auto it:temp){
             ll val=it%power(2,l_d[bits]);
             if(v[dir[val]].size()==cap){
                 insert(it);
                 break;
             }
             else
             v[dir[val]].pb(it);
         }

     }
   }
}

void search(ll b){
    ll bits=b%power(2,g_d);
    bool t=0;
    for(auto it:v[dir[bits]]){
        if(it==b){
            t=1;
            break;
        }
    }
    if(t==1)
    cout<<"Found "<<b<<endl;
    else
    cout<<"Could not find "<<b<<endl;

}

void delete_val(ll b){
    ll bits=b%power(2,g_d);
    if(find(v[dir[bits]].begin(),v[dir[bits]].end(),b)!=v[dir[bits]].end())
    v[dir[bits]].erase(find(v[dir[bits]].begin(),v[dir[bits]].end(),b));
    else{
        cout<<"Could not delete "<<b<<endl;
    }
}

void display(){
   cout<<g_d<<endl;
   cout<<counter<<endl;
   for(int x=0;x<counter;x++){
       cout<<v[x].size()<<" "<<l_d[x]<<endl;
   }
}


 
 
 
 
 
 
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

 
int  main()
{
    fast();
    cin>>g_d>>cap;
    for(int x=0;x<power(2,g_d);x++){
        dir[x]=x;
        l_d[x]=g_d;
        counter++;
    }
    while(1){
      ll a,b;
      cin>>a;
      if(a==2){
          cin>>b;
          insert(b);
      }
      else if(a==4){
          cin>>b;
          delete_val(b);
      }
      else if(a==5){
          display();
      }
      else if(a==3){
          cin>>b;
          search(b);
      }
      else if(a==6){
          break;
      }
    }

    // cout<<"hi"<<endl;

    // for(int x=0;x<2*counter;x++){
    //     for(auto it:v[x]){
    //       cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int x=0;x<power(2,g_d);x++){
    //    cout<<x<<" "<<dir[x]<<endl;
    // }
    















 
}