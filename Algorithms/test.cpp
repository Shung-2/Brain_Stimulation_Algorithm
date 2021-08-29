//#include <iostream>
//using namespace std;
//
//int main()
//{
//    cin.tie(NULL);
//    ios::sync_with_stdio(false);
//
//    int A, B, C;
//    int Array[10] = { 0 };
//
//    cin >> A >> B >> C;
//    int Result = A * B * C;
//
//    while (Result != 0)
//    {
//        Array[Result % 10] += 1;
//        Result /= 10;
//    }
//
//    for (int i = 0; i < 10; i++)
//    {
//        cout << Array[i] << "\n";
//    }
//
//    return 0;
//}