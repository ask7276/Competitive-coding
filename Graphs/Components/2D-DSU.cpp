const int N = 1e6 + 2005;
ll parent[N];
ll siz[N];
bool vis[N];
void make(ll v)
{
    parent[v] = v;
    siz[v] = 1;
}
 
ll find(ll v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}
 
void merge(ll a, ll b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}
ll n, m;
ll index(ll i, ll j)
{
    return i * (m + 1) + j;
}
int main()
{
    kira;
    cin >> n >> m;
    vector<vector<char>> c(n + 1, vector<char>(m + 1, '0'));
    forz(i, n + 1) forz(j, m + 1) make(index(i, j));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin>>c[i][j];
            if (c[i][j] == c[i - 1][j] && c[i][j] == '.')
                merge(index(i, j), index(i - 1, j));
            if (c[i][j] == c[i][j - 1] && c[i][j] == '.')
                merge(index(i, j), index(i, j - 1));
        }
    }
    ll cnt=0;
    forz(i,n+1)
    {
        forz(j,m+1)
        {
            if(c[i][j]=='.')
            {
                vis[find(index(i,j))]=true;
            }
        }
    }
    forz(i,(n+1)*(m+1))
    {
        if(vis[i])cnt++;
    }
    cout<<cnt;
    return 0;
}