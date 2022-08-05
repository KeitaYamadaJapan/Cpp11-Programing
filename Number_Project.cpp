/*
 * Number_Project.cpp
 *
 *  Created on: 2022/08/05
 *      Author: yamadakeita
 */
#include<iostream>
using namespace std;

class Number {
public:
    int num;
    Number(int n=0): num(n) {}
// 在此处补充你的代码
    void operator=(int num){
        this->num = num;
    }
    int operator *(Number &o){
        int a;
        a = this->num * o.num;
        return a;
    }
    operator int(){
        return num;
    }

    int operator+(Number &o){
        return this->num + o.num;
    }

    int operator-(Number &o){
        return this->num - o.num;
    }

    double operator/(Number &o){
        return double(this->num) / o.num;
    }

};

int main() {
    Number n1(10), n2(20);
    Number n3;n3 = n1*n2;
    cout << int(n3) << endl;

    n3 = n1+n2;
    cout << int(n3) << endl;
    n3 = n1-n2;
    cout << int(n3) << endl;
    n3 = n1/n2;
    cout << int(n3) << endl;
    double n4 = n1/n2;
    cout << n4 << endl;

    return 0;
}
/*


Programming Question #1: Output 200
Source: POJ, Peking University Online Program Evaluation System (Coursera Statement: Exercises completed on POJ will not be counted into Coursera's final grade.)

Total Time Limit: 1000ms Memory Limit: 1024kB

describe
Make the following code output a result of 200.

 プログラミングの質問 #1: 出力 200
出典: POJ、北京大学オンライン プログラム評価システム (Coursera の声明: POJ で完了した演習は、Coursera の最終成績にはカウントされません。)

総時間制限: 1000ms メモリ制限: 1024kB

説明
次のコードで結果が 200 になるようにします。


 #include<iostream>
using namespace std;
class Number {
public:
    int num;
    Number(int n=0): num(n) {}
// 在此处补充你的代码
};

int main() {
    Number n1(10), n2(20);
    Number n3;n3 = n1*n2;
    cout << int(n3) << endl;
    return 0;
}
 */



