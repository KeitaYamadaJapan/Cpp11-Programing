//
//  main.cpp
//  UPeking_CS3W09_Q01
//
//  Created by 山田啓太 on 2022/10/30.
//
/**
 Coursera 北京大学 CS3 第9週　Q1 My solution
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Point {
    int x;
    int y;
    Point(int x_,int y_):x(x_),y(y_) { }
};
bool operator < ( const Point & p1, const Point & p2)
{
    if( p1.y < p2.y )
        return true;
    else if( p1.y == p2.y )
        return p1.x < p2.x;
    else
        return false;
}
int main()
{
    cout << endl;// For xcode
    int t;
    int x,y;
    cin >> t;
    vector<Point> v;
    while( t -- ) {
        cin >> x >> y;
        v.push_back(Point(x,y));
    }
    vector<Point>::iterator i,j;
    int nTotalNum = 0;
// 在此处补充你的代码
    sort(v.begin(),v.end());
    for( i = v.begin(); i < v.end() - 1;i ++ )
        for(j = i+1; j < v.end(); j++) {
            if(binary_search(v.begin(),v.end(),Point( j->x, i->y)) &&
                binary_search(v.begin(),v.end(),Point(i->x,j->y)) &&
                i->x != j->x &&
                i->y != j->y )
                nTotalNum ++;
        }
    cout << nTotalNum / 2 << endl;
return 0;
}


/**
 プログラミングの質問 #1
 出典: POJ (Coursera の声明: POJ で完了した問題は、Coursera の最終成績にはカウントされません。)

 注: 合計制限時間: 1000ms メモリ制限: 65536kB

 説明
 次のプログラムは、以下の問題を解決するために列挙法を使用しています。空欄を埋めてください。

 平面上の長方形で、その辺が座標軸に平行な場合、それを「標準長方形」と呼びます。n 個の繰り返しのない整数点 (水平座標と垂直座標が整数である点) が与えられたとき、これらの n 個の点から任意の 4 点を頂点として形成される四角形のうち、標準の長方形であるものがいくつあるかを求めます。
 
 
 Programming Challenge : Engineering Work—STL2
 Passed 90/90 points

 deadline
 The due date for the assignment was March 12, 15:59 JST

 You can submit this assignment until the course is finished.

 Prepare
 Before starting the assignment below, please click here to download the code template .

 Programming Question #1
 Source: POJ (Coursera Statement: Problems completed on POJ will not count towards Coursera's final grade.)

 Note: Total Time Limit: 1000ms Memory Limit: 65536kB

 describe
 The following program uses enumeration method to solve the following problems, please fill in the blanks.

 A rectangle on the plane, if its sides are parallel to the coordinate axis, we call it a "standard rectangle". Given n non-repeating integer points (points whose horizontal and vertical coordinates are integers), find out how many of the quadrilaterals formed by taking any 4 points from these n points as vertices are standard rectangles.
 入力　Input
 6
 2 3
 2 5
 4 5
 4 4
 2 4
 4 3
 
 出力 Output
 3
 
 提示
 不足しているコードの形式は次のとおりです。 Missing Code
 
 _____________________;
 for( i = v.begin(); i < v.end() - 1;i ++ )
     for(_____________; ______________; _____________) {
         if(binary_search(v.begin(),v.end(),Point( j->x, i->y)) &&
             ____________________________________________ &&
             ____________________________________________ &&
             ____________________________________________ )
             nTotalNum ++;
     }
 cout << _________________;
 
  
 
 */

