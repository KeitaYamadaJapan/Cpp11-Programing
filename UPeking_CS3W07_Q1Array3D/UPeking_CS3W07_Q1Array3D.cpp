//
//  main.cpp
//  UPeking_CS3W07_Q1Array3D
//
//  Created by 山田啓太 on 2022/11/05.
//

/**
Coursera 北京大学　CS3 week7 Q1
My solution.
*/

#include <iostream>
using namespace std;
// 在此处补充你的代码
template<class T>
class Obj
{
private:
    T *a;
public:
    Obj(int n)
    {
        a = new T[n];
    }
    T &operator[](int k)
    {
        return a[k];
    }
    T &operator=(const T b)
    {
        this->a = b;
        return *this;
    }
    //T *operator[](int k)
    //{
    //    return a + k;
    //}

};

template<class T>
class CArray2D
{
private:
    Obj<T> **obj;
public:
    CArray2D(int n, int k)
    {
        obj = new Obj<T>*[n];
        for(int j = 0; j < n; j++)
        {
            obj[j] = new Obj<T>(k);
        }
    }
    Obj<T> &operator[](int j)
    {
        return *obj[j];
    }
};

template<class T>
class CArray3D
{
private:
    CArray2D<T> **array;
public:
    CArray3D(int m, int n, int k)
    {
        array = new CArray2D<T>*[m];
        for(int i = 0; i < m; i++)
        {
            array[i] = new CArray2D<T>(n, k);
        }
    }
    CArray2D<T> &operator[](int i)
    {
        return *array[i];
    }
};


int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
return 0;
}

/**
 
 プログラミングの質問 #1
 出典: POJ (Coursera の声明: POJ で完了した問題は、Coursera の最終成績にはカウントされません。)

 注: 合計制限時間: 1000ms メモリ制限: 65536kB

 説明
 次のプログラムの出力が次のようになるように、要素が任意の型の変数である 3 次元配列を生成するために使用できる 3 次元配列テンプレート CArray3D を実装します。

 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,

 記述できるクラス テンプレートは 1 つだけであり、複数は記述できないことに注意してください。
 
 
 Programming Question #1
 Source: POJ (Coursera Statement: Problems completed on POJ will not count towards Coursera's final grade.)

 Note: Total Time Limit: 1000ms Memory Limit: 65536kB

 describe
 Implement a three-dimensional array template CArray3D, which can be used to generate three-dimensional arrays whose elements are variables of any type, so that the output of the following program is:

 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24, 25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49, 50,51,52,53,54,55,56,57,58,59,

 Note that only one class template can be written, not more than one.
 
 #include <iostream>
 using namespace std;
 // 在此处补充你的代码
 int main()
 {
     CArray3D<int> a(3,4,5);
     int No = 0;
     for( int i = 0; i < 3; ++ i )
         for( int j = 0; j < 4; ++j )
             for( int k = 0; k < 5; ++k )
                 a[i][j][k] = No ++;
     for( int i = 0; i < 3; ++ i )
         for( int j = 0; j < 4; ++j )
             for( int k = 0; k < 5; ++k )
                 cout << a[i][j][k] << ",";
 return 0;
 }
 
 Presentation
 Tip: Classes can be defined in classes, and class templates can be defined in class templates. E.g:
 
 class A
 {
     class B {

     };
 };

 template
 class S
 {
     T x;
     class K {
         T a;
     };
 };
 
 */

