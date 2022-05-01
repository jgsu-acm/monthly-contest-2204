#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
using namespace std;
const int maxn = 1e5+5;
const double eps = 1e-8;
int n;
int a[maxn], b[maxn];
double c[maxn];
bool check(double m)
{
    for(int i=1;i<=n;i++) c[i] = a[i]-m*b[i];
    sort(c+1, c+1+n, greater<double>());
    return accumulate(c+1, c+1+5, 0.0)>0;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    double l=0, r=5e7;
    while(r-l>eps)
    {
        double mid = (l+r)/2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout<<fixed<<setprecision(6)<<l<<endl;
    return 0;
}
