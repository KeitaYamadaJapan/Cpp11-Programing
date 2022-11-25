//
//  main.cpp
//  UPeking_CS3w03_Q12
//
//  Created by 山田啓太 on 2022/11/25.
//

#include <iostream>
using namespace std;
class A {
public:
    int val;
// 在此处补充你的代码
    A():val(0){}
    int &GetObj(){
        return this->val;
        /**
        return val;　でもOK
         */
    }
};
int main() {
    A a;
    cout << a.val << endl;
    a.GetObj() = 5;
    cout << a.val << endl;
}

/**
 プログラミングの質問 #1
 出典: POJ (Coursera の声明: POJ で完了した問題は、Coursera の最終成績にはカウントされません。)

 注: 合計制限時間: 1000ms メモリ制限: 65536kB

 説明
 次のプログラムの出力は次のとおりです。

 Programming Question #1
 Source: POJ (Coursera Statement: Problems completed on POJ will not count towards Coursera's final grade.)

 Note: Total Time Limit: 1000ms Memory Limit: 65536kB

 describe
 The output of the following program is:
 
 0
 5

 空欄に記入してください:
 Please fill in the blank:
 
 #include <iostream>
 using namespace std;
 class A {
 public:
     int val;
 // 在此处补充你的代码
 };
 main() {
     A a;
     cout << a.val << endl;
     a.GetObj() = 5;
     cout << a.val << endl;
 }
 
 提示
 不足しているコードの形式は次のとおりです。
 
 Presentation
 The missing code has the form:
 
 A(_________________ ){ val = n; }
 ________________ GetObj() {
     return _________________;
 }
 
 */
