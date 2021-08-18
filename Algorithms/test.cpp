#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int Case, N;
    int Score[1000] = { 0, };
    double Count = 0, Avg = 0;

    cin >> Case;
    for (int i = 0; i < Case; i++)
    {
        cin >> N;

        for (int j = 0; j < N; j++)
        {
            cin >> Score[j];
            Avg += Score[j];
        }

        Avg /= N;

        for (int k = 0; k < N; k++)
        {
            if (Avg < Score[k])
                Count++;
        }

        cout << fixed;
        cout.precision(3);
        cout << Count / N * 100 * 1000 / 1000 << "%" << "\n";
        Avg = 0, Count = 0;
    }

    return 0;
}