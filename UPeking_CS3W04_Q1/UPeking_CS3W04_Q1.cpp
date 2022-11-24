//
//  main.cpp
//  UPeking_CS3W04_Q1
//
//  Created by 山田啓太 on 2022/11/02.
//

/**
 Coursera 北京大学　CS3 week4 Q1
 My solution
 */


#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
    void operator=(string s)
    {
        int idx = s.find("+");
        r = (double)stoi(s.substr(0,idx));
        i = (double)stoi(s.substr(idx+1));
    }
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}

/**
 
 プログラミングの質問 #1
 出典: POJ (Coursera の声明: POJ で完了した問題は、Coursera の最終成績にはカウントされません。)

 注: 合計制限時間: 1000ms メモリ制限: 65536kB

 説明
 次のプログラムの出力は次のとおりです。

 3+4i

 5+6i

 Complex クラスのメンバー関数を補完してください。メンバー変数は追加できません。
 
 Programming Question #1
 Source: POJ (Coursera Statement: Problems completed on POJ will not count towards Coursera's final grade.)

 Note: Total Time Limit: 1000ms Memory Limit: 65536kB

 describe
 The output of the following program is:

 3+4i

 5+6i

 Please complement the member functions of the Complex class. Member variables cannot be added.
 
 #include <iostream>
 #include <cstring>
 #include <cstdlib>
 using namespace std;
 class Complex {
 private:
     double r,i;
 public:
     void Print() {
         cout << r << "+" << i << "i" << endl;
     }
 // 在此处补充你的代码
 };
 int main() {
     Complex a;
     a = "3+4i"; a.Print();
     a = "5+6i"; a.Print();
     return 0;
 }
 
 */
