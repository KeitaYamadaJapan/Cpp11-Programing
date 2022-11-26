//
//  main.cpp
//  UPeking_CS3W03_Q3
//
//  Created by 山田啓太 on 2022/11/02.
//

/**
 Coursera 北京大学 CS3 week3 Q3
 */

#include <iostream>
using namespace std;
class Base {
public:
    int k;
    Base(int n):k(n) { }
};
class Big {
public:
    int v; Base b;
// 在此处补充你的代码
    Big(int n):v(n),b(n){}
};
int main() {
    Big a1(5); Big a2 = a1;
    cout << a1.v << "," << a1.b.k << endl;
    cout << a2.v << "," << a2.b.k << endl;
    return 0;
}

/**
 
 プログラミングの質問 #3
 出典: POJ (Coursera の声明: POJ で完了した問題は、Coursera の最終成績にはカウントされません。)

 注: 合計制限時間: 1000ms メモリ制限: 65536kB

 説明
 次のプログラムの出力は次のとおりです。

 5,5

 5,5

 空欄に記入してください:
 
 Programming Question #3
 Source: POJ (Coursera Statement: Problems completed on POJ will not count towards Coursera's final grade.)

 Note: Total Time Limit: 1000ms Memory Limit: 65536kB

 describe
 The output of the following program is:

 5,5

 5,5

 Please fill in the blank:

 #include <iostream>
 using namespace std;
 class Base {
 public:
     int k;
     Base(int n):k(n) { }
 };
 class Big {
 public:
     int v; Base b;
 // 在此处补充你的代码
 };
 int main() {
     Big a1(5); Big a2 = a1;
     cout << a1.v << "," << a1.b.k << endl;
     cout << a2.v << "," << a2.b.k << endl;
     return 0;
 }
 */
