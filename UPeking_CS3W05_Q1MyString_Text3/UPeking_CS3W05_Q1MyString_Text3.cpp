//
//  main.cpp
//  UPeking_CS3W05_Q1MyString_Text3
//
//  Created by 山田啓太 on 2022/11/04.
//

/**
 Coursera 北京大学 CS3 week5 Q1
 Author　中国の学生さんです。 
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
// 在此处补充你的代码

#include <string>
class MyString{
public:
    string myString;
public:
    MyString():myString(){}
    MyString(string str):myString(str){}
    MyString(const char *st):myString(st) {};
    MyString(MyString const& ms):myString(ms.myString){}

    friend ostream& operator << (ostream& os,const MyString& ms);
    //MyString operator+(MyString & ms);
    //MyString operator+(string & str);
    //MyString operator=(string & str);
    MyString operator=(const MyString & ms);
    bool operator<(MyString & ms);
    bool operator==(MyString & ms);
    bool operator>(MyString & ms);
    char& operator[](int i);
    MyString operator+=(const string& str);

    MyString operator+(const MyString& ms);
    MyString operator+(const char *str);

    MyString operator()(int m,int n){
        return MyString(myString.substr(m,n));
    }


};

ostream& operator << (ostream& os, const MyString & ms){
    os << ms.myString ;
    return os;
}

//MyString &operator+(const MyString & ms1,const MyString &ms2){
//    return *new MyString(ms1.myString + ms2.myString);
//}

//MyString &operator+(const MyString & ms,string & str){
//    return *new MyString(ms.myString + str);
//}

MyString &operator+(const char *str,const MyString & ms){
   return *new MyString(str + ms.myString);
}

//void operator=(char &a, char &b){
//    a = b;
//}

//MyString MyString::operator=(string & str){
//    myString = str;
//    return *this;
//}

MyString MyString::operator=(const MyString & ms){
    myString = ms.myString;
    return *this;
}

MyString MyString::operator+(const MyString & ms){
    return *new MyString(myString + ms.myString);
}

MyString MyString::operator+(const char *str){
    return *new MyString(myString + str);
}

bool MyString::operator<(MyString & ms){
    return myString < ms.myString;
}

bool MyString::operator==(MyString & ms){
    return myString == ms.myString;
}

bool MyString::operator>(MyString & ms){
    return myString > ms.myString;
}

char& MyString::operator[](int i){
    return myString[i];
}

MyString MyString::operator+=(const string& str){
    myString += str;
    return *this;
}

int CompareString(const void * e1, const void * e2)
{
    MyString * s1 = (MyString *)e1;
    MyString * s2 = (MyString *)e2;
    if( *s1 < *s2 )     return -1;
    else if( *s1 == *s2 ) return 0;
    //else if( *s1 > *s2 ) return 1;
    return 1;
}
int main() {
    MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
    MyString SArray[4] = {"big","me","about","take"};
    cout << "1. " << s1 << s2 << s3<< s4<< endl;
    s4 = s3; s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1; s1 = "ijkl-";
    s1[2] = 'A' ;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray,4,sizeof(MyString), CompareString);
    for( int i = 0;i < 4;++i )
        cout << SArray[i] << endl;
    //输出s1从下标0开始长度为4的子串
    cout << s1(0,4) << endl;
    //输出s1从下标为5开始长度为10的子串
    cout << s1(5,10) << endl;
    return 0;
}

/**
 プログラミングの質問 #1
 出典: POJ (Coursera の声明: POJ で完了した問題は、Coursera の最終成績にはカウントされません。)

 注: 合計制限時間: 1000ms メモリ制限: 65536kB

 説明
 次のプログラムの出力が次のようになるようにクラス MyString を記述します。


 
 Editing #1
 Origin: POJ (Coursera statement: Completed the course at POJ without a meeting at the end of Coursera.)

 Note: Time limit: 1000ms Life limit: 65536kB

 description
 A copy of the MyString type, using the lower side of the export result is:
 1. abcd-efgh-abcd-
 2.abcd-
 3.
 4.abcd-efgh-
 5. efgh-
 6.c
 7.abcd-
 8. ijAl-
 9. ijAl-mnop
 10.qrst-abcd-
 11.abcd-qrst-abcd-uvw xyz
 about
 big
 me
 take
 abcd
 qrst-abcd-
 
 要件: MyString クラスは、C++ 標準文字列クラスから派生する必要があります。
 ヒント 1: プログラム内のすべての "MyString" を "string"
 に置き換えると、問題のプログラムは最後の2つのステートメントを除いて
 コンパイルできなくなり、他のステートメントは正常になり、出力は以前の結果。
 つまり、MyString クラスから string クラスへの機能拡張は、最後の 2つのステートメントに
 のみ反映されます。ヒント 2: 文字列クラスにはメンバー関数 string substr(int start, int length); があり、開始位置から始まる長さの部分文字列を見つけることができます
 
 Requirement: MyString must be derived from C++ standard string. Suggestion 1: As a result, the "string" replacement 
 for "MyString" in the beginning of the process, the purpose of the procedure was removed after the end of the second sentence, 
 and the other words had no problems, and the export and the front result anastomosis. In other words, MyString type vs. string 
 type function is only filled in at the top of the last two sentences. Suggestion 2: string type has one component function string 
 substr(int start,int length);
 
 
 プログラム
 
 #include <iostream>
 #include <cstring>
 #include <cstdlib>
 using namespace std;
 // 在此处补充你的代码　Your code here.
 int CompareString( const void * e1, const void * e2) {
     MyString * s1 = (MyString * ) e1;
     MyString * s2 = (MyString * ) e2;
     if( *s1 < *s2 ) return -1;
     else if( *s1 == *s2 ) return 0;
     else if( *s1 > *s2 ) return 1;
 }
 int main() {
     MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
     MyString SArray[4] = {"big","me","about","take"};
     cout << "1. " << s1 << s2 << s3<< s4<< endl;
     s4 = s3; s3 = s1 + s3;
     cout << "2. " << s1 << endl;
     cout << "3. " << s2 << endl;
     cout << "4. " << s3 << endl;
     cout << "5. " << s4 << endl;
     cout << "6. " << s1[2] << endl;
     s2 = s1; s1 = "ijkl-";
     s1[2] = 'A' ;
     cout << "7. " << s2 << endl;
     cout << "8. " << s1 << endl;
     s1 += "mnop";
     cout << "9. " << s1 << endl;
     s4 = "qrst-" + s2;
     cout << "10. " << s4 << endl;
     s1 = s2 + s4 + " uvw " + "xyz";
     cout << "11. " << s1 << endl;
     qsort(SArray,4,sizeof(MyString), CompareString);
     for( int i = 0;i < 4;++i )
         cout << SArray[i] << endl;
     //输出s1从下标0开始长度为4的子串
     cout << s1(0,4) << endl;
     //输出s1从下标为5开始长度为10的子串
     cout << s1(5,10) << endl;
     return 0;
 }

 出力
 
 1. abcd-efgh-abcd-
 2. abcd-
 3.
 4. abcd-efgh-
 5. efgh-
 6. c
 7. abcd-
 8. ijAl-
 9. ijAl-mnop
 10. qrst-abcd-
 11. abcd-qrst-abcd- uvw xyz
 about
 big
 me
 take
 abcd
 qrst-abcd-
 
 */
