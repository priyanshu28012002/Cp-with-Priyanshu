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

class info {
public:
   int open, close, full;
   info(int _open, int _close, int _full) {
      open = _open;
      close = _close;
      full = _full;
   }
   info() {
      open = 0;
      close = 0;
      full = 0;
   }
};

info merge(info left, info right) {
   info ans = info(0, 0, 0);
   ans.full = left.full + right.full + min(left.open, right.close);
   ans.open = left.open + right.open - min(left.open, right.close);
   ans.close = left.close + right.close - min(left.open, right.close);
   return ans;
}

void build(int ind, int low, int high, string s, info seg[]) {
   if (low == high) {
      seg[ind]  = info(s[low]=='(', s[low]==')', 0);
      return;
   }
   int mid = (low + high) / 2;
   build(ind*2+1, low, mid, s, seg);
   build(ind*2+2, mid+1, high, s, seg);
   seg[ind] = merge(seg[2*ind+1], seg[ind*2+2]);
}

info query(int ind, int low, int high, int l,int r,info seg[]){
    if (r <low || high < l) return info(); // no overlap 
   if (low >= l && high <= r) return seg[ind]; // complete overlap
   int mid = (low+high)/2;
         info left =query(2*ind+1,low,mid,l,r,seg); 
       info right  =query(2*ind+2,mid+1,high,l,r,seg);
       return merge(left,right);
       
void problemSolve() {
    inputString(s);
    int n = s.size();
    info seg[4*n];

    build(0, 0, n-1, s, seg);
      in(q);
      while(q--){
         in(l);
         in(r);
         l--;
         r--;
         info ans = query(0,0,n-1,l,r,seg);
         cout<<ans.full*2<<endl;

      }
}

int32_t main() {
    systemAndOnlineJudge();
    problemSolve();
    return 0;
}
