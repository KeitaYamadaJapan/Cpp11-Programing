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
