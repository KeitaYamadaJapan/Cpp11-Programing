//
//  main.cpp
//  UPeking_CS3W06_Q1
//
//  Created by 山田啓太 on 2022/11/04.
//

/**
Coursera 北京大学　CS3 week6 Q1
My solution
*/



#include <iostream>
using namespace std;
class A {
    private:
        int nVal;
    public:
        void Fun()
        { cout << "A::Fun" << endl; }
        void Do()
        { cout << "A::Do" << endl; }
};
class B:public A {
    public:
        virtual void Do()
        { cout << "B::Do" << endl; }
};
class C:public B {
    public:
    void Do( )
    { cout << "C::Do" <<endl; }
    void Fun()
    { cout << "C::Fun" << endl; }
};
void Call(
// 在此处补充你的代码
B& p
        ) {
    p.Fun(); p.Do();
}
int main() {
    C c; Call(c);
    return 0;
}


/**
 プログラミングの問題＃1
 出典: POJ (Coursera の免責事項: POJ で完了した演習は、Coursera の最終成績にはカウントされません。)

 注: 合計制限時間: 1000ms メモリ制限: 65536kB

 次のプログラムの出力は次のとおりです。

 A::Fun
 C::Do

 空欄に記入してください:
 
 Programming Problem #1
 Source: POJ (Coursera Disclaimer: Exercises completed on POJ will not count toward your final Coursera grade.)

 Note: Total time limit: 1000ms Memory limit: 65536kB

 The output of the following program is:

 A::Fun

 C::Do

 Please fill in the blank:
 
 #include <iostream>
 using namespace std;
 class A {
     private:
         int nVal;
     public:
         void Fun()
         { cout << "A::Fun" << endl; }
         void Do()
         { cout << "A::Do" << endl; }
 };
 class B:public A {
     public:
         virtual void Do()
         { cout << "B::Do" << endl; }
 };
 class C:public B {
     public:
     void Do( )
     { cout << "C::Do" <<endl; }
     void Fun()
     { cout << "C::Fun" << endl; }
 };
 void Call(
 // 在此处补充你的代码
         ) {
     p.Fun(); p.Do();
 }
 int main() {
     C c; Call(c);
     return 0;
 }
 
 */




