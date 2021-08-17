//#include <iostream>
//using namespace std;
//
//int main()
//{
//    cin.tie(NULL);
//    ios::sync_with_stdio(false);
//
//    int num, numTemp, cycle, count = 0;
//    int firstNum, SecondNum, SumNum;
//    cin >> num;
//
//    if (10 > num)
//        num *= 10;
//
//    numTemp = num;
//
//    while (true)
//    {
//        firstNum = numTemp / 10;
//        SecondNum = numTemp % 10;
//        SumNum = firstNum + SecondNum;
//        numTemp = (SecondNum * 10) + (SumNum % 10);
//        count++;
//        if (num == numTemp)
//            break;
//    }
//    cout << count;
//
//    return 0;
//}