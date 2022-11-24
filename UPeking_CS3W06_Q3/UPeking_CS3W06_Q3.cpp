//
//  main.cpp
//  UPeking_CS3W06_Q3
//
//  Created by 山田啓太 on 2022/11/05.
//

/**
For my Text
Coursera 北京大学　CS3 week6 Q3
Author 中国の学生さん
*/

#include <iostream>
using namespace std;
class A {
    private:
        int nVal;
    public:
        void Fun()
        { cout << "A::Fun" << endl; }
        virtual void Do()
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
        { cout << "C::Do" << endl; }
        void Fun()
        { cout << "C::Fun" << endl; }
};
void Call(
// 在此处补充你的代码
A*p
        ) {
    p->Fun(); p->Do();
}
int main() {
    Call( new A() );
    Call( new C() );
    return 0;
}


/**
 
  
 プログラミングの問題＃3
 出典: POJ (Coursera の免責事項: POJ で完了した演習は、Coursera の最終成績にはカウントされません。)

 注: 合計制限時間: 1000ms メモリ制限: 65536kB

 説明
 次のプログラムの出力は次のとおりです。
 


 Programming Problem #1
 Source: POJ (Coursera Disclaimer: Exercises completed on POJ will not count toward your final Coursera grade.)

 Note: Total time limit: 1000ms Memory limit: 65536kB

 The output of the following program is:

 A::Fun

 C::Do

 Please fill in the blank:

 1234567891011121314151617181920212223242526272829303132
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

 enter
 none

 output
 A::Fun

 C::Do

 sample input
 1
 无
 sample output
 12
 A::Fun
 C::Do
 Programming Problem #2
 Source: POJ (Coursera Disclaimer: Exercises completed on POJ will not count toward your final Coursera grade.)

 Note: Total time limit: 1000ms Memory limit: 65536kB

 describe
 The output of the following program is:

 destructor B

 destructor A

 Please write out class A completely. Restriction: You must not write a constructor for class A.

 159101112131434567812
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

 enter
 none

 output
 destructor B

 destructor A

 sample input
 1
 无
 sample output
 12
 destructor B
 destructor A
 Programming Problem #3
 Source: POJ (Coursera Disclaimer: Exercises completed on POJ will not count toward your final Coursera grade.)

 Note: Total time limit: 1000ms Memory limit: 65536kB

 describe
 The output of the following program is:

 A::Fun

 A::Do

 A::Fun

 C::Do
 
 
 #include <iostream>
 using namespace std;
 class A {
     private:
         int nVal;
     public:
         void Fun()
         { cout << "A::Fun" << endl; }
         virtual void Do()
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
         { cout << "C::Do" << endl; }
         void Fun()
         { cout << "C::Fun" << endl; }
 };
 void Call(
 // 在此处补充你的代码
         ) {
     p->Fun(); p->Do();
 }
 int main() {
     Call( new A() );
     Call( new C() );
     return 0;
 }
 
 
 */
