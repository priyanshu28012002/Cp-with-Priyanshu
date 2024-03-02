https://codeforces.com/contest/339/problem/D

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ll long long
#define rep(i, x, n) for (int i = x; i < n; i++)
#define in(x) int x; cin >> x
#define inputArr(arr,n) int arr[n]; rep(i,0,n) cin >> arr[i]
#define inputVec(v,n)  vector<int> v; rep(i,0,n) {int vectorValueforInput; cin >> vectorValueforInput; v.push_back(vectorValueforInput);}
#define inputString(s) string s ; cin>>s
#define sortarr sort(arr,arr+n)
#define sortav sort(v.begin(),v.end())

void systemAndOnlineJudge() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
    #endif
}

void build(int ind,int low,int high,int arr[],int seg[],bool kya){
   if(low==high){
      seg[ind] = arr[low];
      return;
   }
   int mid = (low + high)/2;
   build(2*ind+1,low,mid,arr,seg,!kya);
   build(2*ind+2,mid+1,high,arr,seg,!kya);
   if(kya){
      seg[ind] = seg[2*ind+1] |seg[2*ind+2];
   }
   else{
      seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
   }
}

void update(int ind,int low,int high,int seg[],int i,int val,bool kya){
   if(low == high){
      seg[ind] = val;
      return;
   }
   int mid= (low+high)/2;
   if(i<=mid){
      update(2*ind+1,low,mid,seg,i,val,!kya);
   }
   else{
      update(2*ind+2,mid+1,high,seg,i,val,!kya);
   }

   if(kya){
      seg[ind] = seg[2*ind+1] | seg[2*ind+2];
   }
   else{
      seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
   }
}

void problemSolve(){
    in(n);
    in(q);
     int el = pow(2,n);
    inputArr(arr,el);
   
    int seg[4*el];
    if(n%2==0){
      build(0,0,el-1,arr,seg,false);
    }
    else{build(0,0,el-1,arr,seg,true);}
    
    while(q--){
      in(i);
      in(val);
      i--;
      
      if(n%2==0){
        update(0,0,el-1,seg,i,val,false);  
      }
      else{
          update(0,0,el-1,seg,i,val,true);
      }
      cout << seg[0] << endl;
    }

    
}

int32_t main() {
    systemAndOnlineJudge();
    problemSolve();
    return 0;
}
