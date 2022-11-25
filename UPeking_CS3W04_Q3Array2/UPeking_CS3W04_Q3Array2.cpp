//
//  main.cpp
//  UPeking_CS3W04_Q3Array2
//
//  Created by 山田啓太 on 2022/11/03.
//

/**
 Coursera 北京大学　CS3 week4 Q3
 My solution
 */

#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
class Array2{
private:
    int **array2;
public:
    Array2(){}
    Array2(int m, int n)
    {
        array2 = new int*[m];
        for(int i = 0; i < m; i++)
        {
            array2[i] = new int[n];
        }
    }
    int *operator[](int k){
        return array2[k];
    }
    int operator()(int k, int l){
        return array2[k][l];
    }
};

int main() {
    Array2 a(3,4);
    int i,j;
    for( i = 0;i < 3; ++i )
        for( j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for( i = 0;i < 3; ++i ) {
        for( j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b; b = a;
    for( i = 0;i < 3; ++i ) {
        for( j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}

/**
 プログラミングの質問 #3
 出典: POJ (Coursera の声明: POJ で完了した問題は、Coursera の最終成績にはカウントされません。)

 注: 合計制限時間: 1000ms メモリ制限: 65536kB

 説明
 次のプログラムの出力が次のようになるように、2 次元配列クラス Array2 を作成します。

 0,1,2,3,
 4,5,6,7,
 8,9,10,11,
 next
 0,1,2,3,
 4,5,6,7,
 8,9,10,11,
 プログラム：


 Programming Question #3
 Source: POJ (Coursera Statement: Problems completed on POJ will not count towards Coursera's final grade.)

 Note: Total Time Limit: 1000ms Memory Limit: 65536kB

 describe
 Write a two-dimensional array class Array2 so that the output of the following program is:

 0,1,2,3,
 4,5,6,7,
 8,9,10,11,
 next
 0,1,2,3,
 4,5,6,7,
 8,9,10,11,

 program:
 
 #include <iostream>
 #include <cstring>
 using namespace std;
 // 在此处补充你的代码
 int main() {
     Array2 a(3,4);
     int i,j;
     for( i = 0;i < 3; ++i )
         for( j = 0; j < 4; j ++ )
             a[i][j] = i * 4 + j;
     for( i = 0;i < 3; ++i ) {
         for( j = 0; j < 4; j ++ ) {
             cout << a(i,j) << ",";
         }
         cout << endl;
     }
     cout << "next" << endl;
     Array2 b; b = a;
     for( i = 0;i < 3; ++i ) {
         for( j = 0; j < 4; j ++ ) {
             cout << b[i][j] << ",";
         }
         cout << endl;
     }
     return 0;
 }
 */
