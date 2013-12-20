#include<iostream>
using namespace std;
const int Max = 30;
const int max_cost = 100;

int n,result;
int arcs[Max][Max], lowcost[Max];

int min(int a, int b)
{
    return a < b ? a : b;
}

void prim()
{
    int i, j, ver, min_ver, min_cost;
    for(i = 1; i <= n; i ++)
        lowcost[i] = max_cost;
    ver = 1;
    result = 0;
    for(i = 1; i < n; i ++)
    {
        lowcost[ver] = 0;
        min_cost = max_cost;
        for(j = 1; j <= n; j ++)
            if(ver != j && lowcost[j] > 0)
            {
                lowcost[j] = min(lowcost[j], arcs[ver][j]);
                if(lowcost[j] < min_cost)
                {
                    min_cost = lowcost[j];
                    min_ver = j;
                }
            }
            ver = min_ver;
            result += min_cost;
    }
}

int main()
{
    int i, j, num, cost;
    char u, v;
    while(cin >> n && n != 0)
    {
        for(i = 1; i <= n; i ++)
            for(j = 1; j <= n; j ++)
                arcs[i][j] = max_cost;
for(i = 1; i < n; i ++)
            {
              cin>>u>>num;   
              while(num --)
                {
                 cin>>v>>cost;
                 arcs[u-'A'+1][v-'A'+1] = cost;
                 arcs[v-'A'+1][u-'A'+1] = cost;
                }
            }
            prim();
            cout<<result<<endl;
    }
    return 0;
}
