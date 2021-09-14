#include <iostream>
using namespace std;

//int Find_Hansu(int Num)
//{
//    int Count = 0;
//
//    for (int i = 0; i < Num; i++)
//    {
//        int First_Num = Num / 100;
//        int Second_Num = Num % 100 / 10;
//        int Third_Num = Num % 100 % 10;
//
//        if (Num < 99)
//        {
//            Count++;
//        }
//        else
//        {
//            if ((Third_Num - Second_Num) == (Second_Num - First_Num))
//            {
//                Count++;
//            }
//        }
//    }
//
//    return Count;
//}

bool Hansu(int Num)
{
    if (Num < 100)
        return true;

    int First_Num = Num / 100;
    int Second_Num = Num % 100 / 10;
    int Third_Num = Num % 100 % 10;

    if ((Third_Num - Second_Num) == (Second_Num - First_Num))
        return true;

    return false;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    //int N = 0, Result = 0;
    //cin >> N;
    //Result = Find_Hansu(N);
    //cout << Result;

    int N = 0, Count = 0;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        if (Hansu(i))
        {
            Count++;
        }
    }
    
    cout << Count;

    return 0;
}