//
//  main.cpp
//  SetOperation
//
//  Created by 山田啓太 on 2022/07/26.
//
//  About this program is below.
//  このプログラムの説明については末尾に


#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << endl;
    multiset<int> ms;
    set<int> s;
    vector<vector<int> > vv;
    int n, item;
    string comand;
    cin >> n;
    while(n--){
        cin >> comand >> item;
        if(comand.compare("add")==0){
            ms.insert(item);
            s.insert(item);
            vector<int> v;
            v.push_back(ms.count(item));
            vv.push_back(v);
            //cout << ms.count(item) << endl;
        }else if(comand.compare("ask") == 0){
            int added(s.count(item));
            int num(ms.count(item));
            vector<int> v;
            v.push_back(added);
            v.push_back(num);
            vv.push_back(v);
            //cout << added << " " << num << endl;
        }else if(comand.compare("del")==0){
            //int num(ms.count(item));
            //cout << num << endl;
            vector<int> v;
            v.push_back(ms.count(item));
            vv.push_back(v);
            ms.erase(item);
        }
    }
    for(vector<vector<int> >::iterator it=vv.begin(); it != vv.end(); it++){
        for(vector<int>::iterator j=it->begin(); j != it->end(); j++ ){
            cout << *j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}


/*


 Sample example import
 7
 add 1
 add 1
 ask 1
 ask 2
 del 2
 del 1
 ask 1

 Sample example export

 1
 2
 1 2
 0 0
 0
 2
 1 0

 Program # 3: Set
 Source: POJ (Coursera Statement: Completed Coursera-like final accounting on POJ.)

 Note: Time limit: 5000ms Time limit: 100000kB

 Description
 A collection of current one integers (elements of heavy recovery), the first sky. Operation under our definition:

 add x grab x join set

 del x Owned in the set x Equal element removal

 ask x Opposite elements in the set x

 Opposite type operation, export according to our request.

 x-like number in the set after add import operation

 del x number in the set before export operation

 ask destination export 0 or 1 display x correct / unsubscribed set (0 display unsubscribed), re-export pre-export set x number, medium empty rating open.

 Import
 First line, one integer n, number of display instructions. 0 <= n <= 100000.

 Back n-line command, description in the description.

 Export
 Both n lines, export request for each line.


 Presentation
 Please use STL's set and multiset to finish the task

 プログラミングの質問＃3：Set
 出典：POJ（Courseraステートメント：POJで完了した問題は、Courseraの最終成績にはカウントされません。）

 注：合計時間制限：5000msメモリ制限：100000kB

 説明
 最初は空の整数の既存のセットがあります（繰り返し要素が許可されます）。次の操作を定義します。

 xを追加セットにxを追加

 del xは、xに等しいすべての要素をセットから削除します

 セット内の要素xの状態について質問x質問

 操作ごとに、次の出力が必要です。

 add出力操作後のセット内のxの数

 delは、操作の前にセット内のxの数を出力します

 最初に出力0または1に、xがセットに追加されたかどうかを示すように要求し（0は、xが追加されたことがないことを示します）、次に、スペースで区切られた現在のセットのxの数を出力します。

 入力
 最初の行は、コマンドの数を表す整数nです。0 <= n<=100000。

 説明で説明されている次のn行のコマンド。

 出力
 合計n行あり、必要に応じて各行が出力されます

 */




