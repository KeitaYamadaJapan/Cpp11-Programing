//
//  main.cpp
//  Enumuration_Triangle
//
//  Created by 山田啓太 on 2022/07/24.
//
/*
 Explain of this programing is below.
 このプログラムの説明は、末尾。
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

bool operator == (const Point & p1, const Point & p2){
    if(p1.x == p2.x && p1.y == p2.y) return true;
    return false;
}
int main()
{
    cout << endl;
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
    sort(v.begin(), v.end());
    for(i=v.begin(); i != v.end()-1; i++){
        for(j = i+1; j != v.end(); j++){
            if(binary_search(v.begin(), v.end(),Point(i->x, j->y)) && binary_search(v.begin(),v.end(),Point(j->x, i->y)) && i->x != j->x && i->y != j->y){
                nTotalNum++;
            }
        }
    }
    cout << nTotalNum/2 << endl;
return 0;
}

/**
sample input
6
2 3
2 5
4 5
4 4
2 4
4 3

Sample output
3

rogramming Question #1
Source: POJ (Coursera Statement: Problems completed on POJ will not count towards Coursera's final grade.)
Note: Total Time Limit: 1000ms Memory Limit: 65536kB
describe
The following program uses enumeration method to solve the following problems, please fill in the blanks.
A rectangle on the plane, if its sides are parallel to the coordinate axis, we call it a "standard rectangle". Given n non-repeating integer points (points whose horizontal and vertical coordinates are integers), find out how many of the quadrilaterals formed by taking any 4 points from these n points as vertices are standard rectangles.
enter
The first line is the number of points
Each subsequent line represents a point, represented by two integers, the first is the x coordinate and the second is the y coordinate
output
Output the number of standard rectangles



プログラミングの質問＃1
出典：POJ（Courseraステートメント：POJで完了した問題は、Courseraの最終成績にはカウントされません。）
注：合計時間制限：1000msメモリ制限：65536kB
説明
次のプログラムは、列挙法を使用して次の問題を解決します。空欄に記入してください。
平面上の長方形。その辺が座標軸に平行である場合、それを「標準長方形」と呼びます。n個の繰り返されない整数点（水平座標と垂直座標が整数である点）が与えられた場合、これらのn点から任意の4点を頂点として形成された四辺形の数を調べます。

入力
最初の行はポイント数です
後続の各線は、2つの整数で表される点を表し、最初の線はx座標で、2番目の線はy座標です。

出力
標準の長方形の数を出力します

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
return 0;
}



Presentation
The missing code has the form:
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




