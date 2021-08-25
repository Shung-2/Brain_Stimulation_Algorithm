//#include <iostream>
//using namespace std;
//
//int main()
//{
//    cin.tie(NULL);
//    ios::sync_with_stdio(false);
//
//    int num, numTemp, count = 0;
//    int firstNum, secondNum, sumNum = 0;
//
//    cin >> num;
//    if (10 > num)
//        num *= 10;
//
//    numTemp = num;
//
//    while (true)
//    {
//        firstNum = numTemp / 10;
//        secondNum = numTemp % 10;
//        sumNum = (firstNum + secondNum) % 10;
//        numTemp = (secondNum * 10) + sumNum;
//        count++;
//        if (num == numTemp)
//            break;
//    }
//    cout << count;
//
//    return 0;
//}