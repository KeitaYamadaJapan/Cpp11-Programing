//
//  main.cpp
//  UPeking_CS3W08_Q2
//
//  Created by 山田啓太 on 2022/11/26.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    cout << endl;
    vector<vector<int> > pq;
    map<int,vector<int> > m;
    int n;
    cin >> n;
    while(n > 0)
    {
        string command;
        cin >> command;
        if(command == "new")
        {
            int idx;
            cin >> idx;
            vector<int> v;
            m[idx] = v;
        }
        else if(command == "add")
        {
            int idx, num;
            cin >> idx >> num;
            m[idx].push_back(num);
        }
        else if(command == "merge")
        {
            int idx1, idx2;
            cin >> idx1 >> idx2;
            for(vector<int>::iterator it = m[idx2].begin(); it != m[idx2].end(); it++)
            {
                m[idx1].push_back(*it);
            }
            sort(m[idx1].begin(),m[idx1].end());
            m[idx2].clear();
        }
        else if(command == "unique")
        {
            int id;
            cin >> id;
            vector<int> v = m[id];
            vector<int> nv;
            set<int> ck;
            for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
            {
                if(!ck.contains(*it))
                {
                    nv.push_back(*it);
                    ck.insert(*it);
                }
            }
            m[id] = nv;
        }
        else if(command == "out")
        {
            int id;
            cin >> id;
            vector<int> v = m[id];
            pq.push_back(v);
            //for(auto it = v.begin(); it != v.end(); it++)
            //{
            //    cout << *it << " ";
            //}
            //cout << endl;
        }
        n--;
    }
    cout << endl;
    for(vector<int> v : pq)
    {
        for(auto it = v.begin(); it != v.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/**
 
 プログラミング問題 #1 リスト
 出典: POJ (Coursera の免責事項: POJ で完了した演習は、Coursera の最終成績にはカウントされません。)

 注: 合計制限時間: 4000ms メモリ制限: 65536kB

 説明
 次のコマンドを実行するプログラムを作成します。

 new id - 指定された番号を id として新しいシーケンスを作成します (id<10000)

 add id num — 整数 num をシーケンス番号付き ID に追加します

 id1 id2 をマージする - id1 と id2 のシーケンスの数字をマージし、id2 をクリアします。

 一意の ID — シーケンス ID の重複する要素を削除します

 out id - シーケンス番号の付いた id の要素を小さいものから大きいものへとスペースで区切って出力します。

 入力
 最初の行の数字 n は、コマンドの数を示します (n<=200000)。次の n 行では、各行に 1 つのコマンドがあります。

 出力
 トピックの必要に応じて出力します。
 
 
 Programming Problem #1 List
 Source: POJ (Coursera Disclaimer: Exercises completed on POJ will not count toward your final Coursera grade.)

 Note: Total time limit: 4000ms Memory limit: 65536kB

 describe
 Write a program to perform the following commands:

 new id - Create a new sequence with the specified number as id (id<10000)

 add id num——add integer num to the sequence numbered id

 merge id1 id2——Merge the numbers in the sequence id1 and id2, and clear id2

 unique id——remove duplicate elements in the sequence id

 out id——Output the elements in the sequence numbered id from small to large, separated by spaces

 enter
 A number n in the first line indicates how many commands there are (n<=200000). In the next n lines, each line has one command.

 output
 Output as required by the topic.
 
 Sample imput
 
 16
 new 1
 new 2
 add 1 1
 add 1 2
 add 1 3
 add 2 1
 add 2 2
 add 2 3
 add 2 4
 out 1
 out 2
 merge 1 2
 out 1
 out 2
 unique 1
 out 1
 
 Sample output
 
 1 2 3
 1 2 3 4
 1 1 2 2 3 3 4

 1 2 3 4
 
 */

