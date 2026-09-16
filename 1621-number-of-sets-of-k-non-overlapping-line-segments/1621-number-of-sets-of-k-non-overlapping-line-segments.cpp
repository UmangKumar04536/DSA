class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long M=1e9+7;
        vector<long long> a(n),b(n);
        fill(a.begin(),a.end(),1);

        for(int j=1;j<=k;j++){
            long long s=0;
            for(int i=1;i<n;i++){
                s=(s+a[i-1])%M;
                b[i]=(b[i-1]+s)%M;
            }
            a=b;
            fill(b.begin(),b.end(),0);
        }
        return a[n-1];
    }
};