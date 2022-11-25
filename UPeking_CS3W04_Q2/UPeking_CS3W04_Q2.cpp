//
//  main.cpp
//  UPeking_CS3W04_Q2
//
//  Created by 山田啓太 on 2022/11/02.
//

/**
 Coursera 北京大学　CS3 week4 Q2
 */

#include <iostream>
using namespace std;
class MyInt {
    int nVal;
    public:
        MyInt(int n) { nVal = n; }
        int ReturnVal() { return nVal; }
// 在此处补充你的代码
    MyInt& operator-(int n)
    /**
        仮にMyInt operator-(int n)なら、出力 8, 6
     */
    {
        nVal -= n;
        return *this;
    }
};
int main () {
    MyInt objInt(10);
    objInt-2-1-3;
    cout << objInt.ReturnVal();
    cout <<",";
    objInt-2-1;
    cout << objInt.ReturnVal();
    cout << endl;
    return 0;
}


/**
 
 プログラミングの質問 #2
 出典: POJ (Coursera の声明: POJ で完了した問題は、Coursera の最終成績にはカウントされません。)

 注: 合計制限時間: 1000ms メモリ制限: 65536kB

 説明
 以下の MyInt クラスには、メンバー変数が 1 つだけあります。MyInt クラス内のコードの一部は隠されています。次のプログラムがコンパイルされ、出力が次のようになったとします。

 4,1

 隠れている部分を書いてください。(記述内容は、MyInt クラスに配置できる必要があります。MyInt のメンバー関数では、静的変数は使用できません)。
 
 Programming Question #2
 Source: POJ (Coursera Statement: Problems completed on POJ will not count towards Coursera's final grade.)

 Note: Total Time Limit: 1000ms Memory Limit: 65536kB

 describe
 The MyInt class below has only one member variable. Part of the code inside the MyInt class is hidden. Suppose the following program compiles and the output is:

 4,1

 Please write the hidden part. (The content you write must be able to be put into the MyInt class. Static variables are not allowed in the member functions of MyInt).
 
 #include <iostream>
 using namespace std;
 class MyInt {
     int nVal;
     public:
         MyInt(int n) { nVal = n; }
         int ReturnVal() { return nVal; }
 // 在此处补充你的代码
 };
 int main () {
     MyInt objInt(10);
     objInt-2-1-3;
     cout << objInt.ReturnVal();
     cout <<",";
     objInt-2-1;
     cout << objInt.ReturnVal();
     return 0;
 }
 */
