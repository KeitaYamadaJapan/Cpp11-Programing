//
//  main.cpp
//  UPeking_CS3W03_Q2
//
//  Created by 山田啓太 on 2022/11/25.
//

/**
 Coursera 北京大学　CS3 week3 Q2
 My solution
 */

#include <iostream>
using namespace std;
class Sample{
public:
    int v;
    Sample(int n):v(n) { }
// 在此处补充你的代码
    //Sample(){}
    //Sample operator=(Sample& other){
        //this->v = other.v * 2;
        //return *this;
    //}
    Sample(Sample& other):v(2*other.v){}
};
int main() {
    Sample a(5);
    Sample b = a;
    cout << b.v << endl;
    return 0;
}

/**
 
 プログラミングの質問 #2
 出典: POJ (Coursera の声明: POJ で完了した問題は、Coursera の最終成績にはカウントされません。)

 注: 合計制限時間: 1000ms メモリ制限: 65536kB

 説明
 次のプログラムの出力は次のとおりです。

 10

 Sampleクラスのメンバー関数を完成させてください。メンバー変数は追加できません。
 
 Programming Question #2
 Source: POJ (Coursera Statement: Problems completed on POJ will not count towards Coursera's final grade.)

 Note: Total Time Limit: 1000ms Memory Limit: 65536kB

 describe
 The output of the following program is:
 10
 
 Please complete the member functions of the Sample class. Member variables cannot be added.
 
 #include <iostream>
 using namespace std;
 class Sample{
 public:
     int v;
     Sample(int n):v(n) { }
 // 在此处补充你的代码
 };
 int main() {
     Sample a(5);
     Sample b = a;
     cout << b.v;
     return 0;
 }
 
 
 */



