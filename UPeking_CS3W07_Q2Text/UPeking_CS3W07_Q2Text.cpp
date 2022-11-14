//
//  main.cpp
//  UPeking_CS3W07_Q2Text
//
//  Created by 山田啓太 on 2022/11/06.
//

//  编程作业—文件操作与模板
//  https://www.bbsmax.com/A/qVde2WmgzP/
// 实数的输出格式（C++程序设计第7周）
#include <iostream>
using namespace std;

int main()
{
    double num;
    cout<<endl;
    cin >> num;
    cout.setf(ios::fixed);//makes cout print floats with a fixed number of decimals
    cout.precision(5);//sets this number to be five
    cout << num << endl;
    cout.unsetf(ios::fixed);//remove the setf(ios::fixed)
    cout.setf(ios::scientific);
    cout.precision(7);
    cout << num << endl;
    return 0;
}

/**
 
 プログラミングの質問 #2: 実数の出力形式
 出典: POJ (Coursera の声明: POJ で完了した問題は、Coursera の最終成績にはカウントされません。)

 注: 合計制限時間: 1000ms メモリ制限: 1000kB

 説明
 ストリーム演算子を使用して実現する: 実数を入力し、最初に非科学的表記で出力し、小数点以下 5 桁の有効数字を保持し、次に科学表記法で出力し、小数点以下 7 桁を保持します。

 注: 異なるシステムおよびコンパイラーでの出力形式はわずかに異なりますが、プログラムのデフォルトの形式設定が OJ プラットフォームで正しい結果を取得できることが保証されています。

 入力
 double 型で格納されることが保証されている非科学表記の正の実数。

 出力
 最初の行: 小数点以下 5 桁の非科学表記法で実数を出力します。

 2 行目: 小数点以下 7 桁の科学表記法で実数を出力します。


 
 Programming Question #2: Output Format of Real Numbers
 Source: POJ (Coursera Statement: Problems completed on POJ will not count towards Coursera's final grade.)
 
 Note: Total Time Limit: 1000ms Memory Limit: 1000kB
 
 describe
 Using stream operator to achieve: Input a real number, first output it in non-scientific notation, keep 5 significant figures after the decimal point; then output it in scientific notation, keep 7 significant figures after the decimal point.
 
 Note: The output formats on different systems and compilers are slightly different, but it is guaranteed that the default format settings in the program will be able to obtain correct results on the OJ platform.
 
 enter
 A positive real number in non-scientific notation, guaranteed to be stored in double type.
 
 output
 The first line: output the real number in non-scientific notation, with 5 significant digits after the decimal point;
 
 The second line: output the real number in scientific notation, with 7 significant digits after the decimal point.
 
 sample input
 12.34
 
 Sample output
 12.34000
 1.2340000e+01
 
 */
 

