//#include <iostream>
//using namespace std;
//
//int main()
//{
//    cin.tie(NULL);
//    ios::sync_with_stdio(false);
//
//    int n = 0, ArrayNum = 0;
//    
//    cin >> n;
//    int Array[n];
//
//    for (int i = 0; i < n; i++)
//    {
//        cin >> ArrayNum;
//        Array[i] = ArrayNum;
//    }
//
//    int Min = Array[0];
//    int Max = Array[0];
//
//    for (int i = 0; i < n; i++)
//    {
//        if (Array[i] < Min) Min = Array[i];
//        if (Array[i] > Max) Max = Array[i];
//    }
//
//    cout << Min << " " << Max;
//    return 0;
//}