//
//  main.cpp
//  UPeking_CS3W07_Q3Text
//
//  Created by 山田啓太 on 2022/11/06.
//

//  编程题＃3： 整数的输出格式
  //  http://blog.csdn.net/nnnnnnnnnnnny/article/details/50409763
 // POJ C++程序设计 编程题＃3 编程作业—文件操作与模板

/**
For my Text
Coursera 北京大学　CS3 week7 Q1
Author 中国の学生さん
*/

  #include <iostream>
  #include <iomanip>
  using namespace std;
  int main() {
      int n;
      cout << endl;
      cin >> n;
      cout<<hex<<n<<endl;
      cout.fill('0');
      cout<<dec<<setw(10)<<n<<endl;
     return 0;
 }

/**
 
 プログラミングの質問 #3: 整数の出力形式
 出典: POJ (Coursera の声明: POJ で完了した問題は、Coursera の最終成績にはカウントされません。)

 注: 合計制限時間: 1000ms メモリ制限: 1000kB

 説明
 ストリーム操作演算子を使用して、整数を入力し、最初に整数を 16 進数で出力し、次に整数を 10 文字幅で出力します。幅が足りない場合は、左に 0 を追加します。

 注: 異なるシステムおよびコンパイラーでの出力形式はわずかに異なりますが、プログラムのデフォルトの形式設定が OJ プラットフォームで正しい結果を取得できることが保証されています。

 入力
 int 型に格納されることが保証されている正の整数。

 出力
 行 1: 整数を 16 進数で出力します。

 2 行目: 10 文字幅の整数を出力します。
 
 Programming Question #3: Output Format of Integers
 Source: POJ (Coursera Statement: Problems completed on POJ will not count towards Coursera's final grade.)

 Note: Total Time Limit: 1000ms Memory Limit: 1000kB

 describe
 Use stream manipulation operator to achieve: Input an integer, first output the integer in hexadecimal, and then output the integer with a width of 10 characters, if the width is insufficient, add 0 to the left.

 Note: The output formats on different systems and compilers are slightly different, but it is guaranteed that the default format settings in the program will be able to obtain correct results on the OJ platform.

 enter
 A positive integer, guaranteed to be stored in the int type.

 output
 Line 1: output the integer in hexadecimal;

 Line 2: Output the integer with a width of 10 characters.
 
 
 サンプル入力
 23
 
 サンプル出力
 17
 0000000023
 
 */







