#include <iostream>

using namespace std;

int main()
{
    int i, j, N, M, n[100001], d, s, q;
    char o;
    cin >> N >> M;
    for(i = 0; i < N; i++)
    {
        cin >> n[i];
    }
    for(i = 0; i < M; i++)
    {
        cin >> o;
        cin >> d;
        if(o == 'C')
        {
            for(j = 0; j < N; j++)
            {
                n[j] += d;
                n[j] %= 65536;
            }
        }
        else if(o == 'Q')
        {
            s = 0;
            for(j = 0; j < N; j++)
            {
                q = n[j] >> d;
                if(q % 2 == 1)
                {
                    s++;
                }
            }
            cout << s << endl;
        }
    }
    return 0;
}
