//
//  main.cpp
//  UPeking_CS3W06_Q2
//
//  Created by 山田啓太 on 2022/11/05.
//

/**
For my text
Coursera 北京大学　CS3 week6 Q2
Author 中国の学生さん
*/


#include <iostream>
using namespace std;
class A {
// 在此处补充你的代码
public:
    //~B() {cout << "destructor B" << endl;}
    ~A() {
        cout << "destructor B" << endl;
        cout << "destructor A" << endl;
    }
    
};
class B:public A {
    public:
        ~B() { cout << "destructor B" << endl; }
};
int main() {
    A * pa;
    pa = new B;
    delete pa;
    return 0;
}

/**
 
 プログラミングの問題＃2
 出典: POJ (Coursera の免責事項: POJ で完了した演習は、Coursera の最終成績にはカウントされません。)

 注: 合計制限時間: 1000ms メモリ制限: 65536kB

 説明
 次のプログラムの出力は次のとおりです。

 destructor B

 destructor A

 クラス A を完全に記述してください。制限: クラス A のコンストラクターを記述してはなりません。
 
 Programming Problem #2
 Source: POJ (Coursera Disclaimer: Exercises completed on POJ will not count toward your final Coursera grade.)

 Note: Total time limit: 1000ms Memory limit: 65536kB

 describe
 The output of the following program is:

 destructor B

 destructor A

 Please write out class A completely. Restriction: You must not write a constructor for class A.
 
 #include <iostream>
 using namespace std;
 class A {
 // 在此处补充你的代码
 };
 class B:public A {
     public:
         ~B() { cout << "destructor B" << endl; }
 };
 int main() {
     A * pa;
     pa = new B;
     delete pa;
     return 0;
 }
 
 
 */



