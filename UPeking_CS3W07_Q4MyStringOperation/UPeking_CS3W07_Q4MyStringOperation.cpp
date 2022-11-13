//
//  main.cpp
//  UPeking_CS3W07_Q4StringOperation2
//
//  Created by 山田啓太 on 2022/11/11.
//

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <sstream>

using namespace std;

class StOperation
{
private:
    string ints = "0123456789";
    vector<string>strings;
    deque<string>elems;
    vector<string>printQue;
public:
    StOperation(vector<string>& fs):strings(fs) {}
    
    void GetLine();
    
    string getElm()
    {
        string el = elems.front();
        elems.pop_front();
        return el;
    };
    
    string Copy();
    string Add();
    int Find();
    int rFind();
    void Insert();
    void Reset();
    void Print();
    void PrintAll();
    void Over();
};





int main()
{
    cout << endl;
    vector<string> fs;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        fs.push_back(str);
    }
    StOperation so(fs);
    while(1)
    {
        so.GetLine();
        string el = so.getElm();
        if(el == "insert"){ so.Insert(); }
        else if(el == "reset"){ so.Reset(); }
        else if(el == "print"){ so.Print(); }
        else if(el == "printall"){ so.PrintAll(); }
        else if(el == "over")
        {
            cout << endl;
            so.Over();
            return 0;
        }
    }
    return 0;
}

void StOperation::GetLine()
{
    elems.clear();
    string line;
    getline(cin,line);
    stringstream ss(line);
    string item;
    while(!ss.eof())
    {
        ss >> item;
        elems.push_back(item);
    }
}


string StOperation::Add()
{
    int i1 = -20;
    int i2 = -20;
    string S1 = "";
    string S2 = "";
    
    if(elems.empty()) return "";
    string el1 = elems.front();
    elems.pop_front();
    if(el1 == "add"){ S1 = Add(); }
    else if(el1 == "copy"){ S1 = Copy(); }
    else if(el1 == "find"){ i1 = Find(); }
    else if(el1 == "rfind"){ i1 = rFind(); }
    else if(el1.find_first_not_of(ints) == string::npos){ i1 = stoi(el1); }
    else { S1 = el1; }
    
    
    if(elems.empty()) return "";
    string el2 = elems.front();
    elems.pop_front();
    if(el2 == "add"){ S2 = Add(); }
    else if(el2 == "copy"){ S2 = Copy(); }
    else if(el2 == "find"){ i2 = Find(); }
    else if(el2 == "rfind"){ i2 = rFind(); }
    else if(el2.find_first_not_of(ints) == string::npos){ i2 = stoi(el2); }
    else{ S2 = el2; }
    
    if(S1 != "" && S2 != "")
    {
        if(S1.find_first_not_of(ints) == string::npos && S2.find_first_not_of(ints) == string::npos)
        {
            return to_string(stoi(S1) + stoi(S2));
        }
        return S1 + S2;
    }
    if(i1 >= 0 && i1 <= 99999 && i2 >= 0 && i2 <= 99999)
    {
        int num = i1 + i2;
        return to_string(num);
    }
    
    return "";
}

string StOperation::Copy()
{
   
    int N;
    int X;
    int L;
    
    if(elems.empty()) return "";
    string el1 = elems.front();
    elems.pop_front();
    if(el1.find_first_not_of(ints) == string::npos){ N = stoi(el1); }
    else if(el1 == "find"){ N = Find(); }
    else if(el1 == "rfind"){ N = rFind(); }
    else { return ""; }
    
    if(elems.empty()) return "";
    string el2 = elems.front();
    elems.pop_front();
    if(el2.find_first_not_of(ints) == string::npos){ X = stoi(el2); }
    else if(el2 == "find"){ X = Find(); }
    else if(el2 == "rfind"){ X = rFind(); }
    else{ return ""; }
    
        
    if(elems.empty()) return "";
    string el3 = elems.front();
    elems.pop_front();
    if(el3.find_first_not_of(ints) == string::npos){ L = stoi(el3); }
    else if(el3 == "find"){ L = Find(); }
    else if(el3 == "rfind"){ L = rFind(); }
    else{ return ""; }
    
        
    if(N <= 0 || strings.size() < N) return "";
    string str = strings[N-1];

    if(X < 0 || X + L > str.length()) return "";

    return str.substr(X, L);
}

int StOperation::Find()
{
    string S;
    int N;
    
    if(elems.empty()) return -20;
    string el1 = elems.front();
    elems.pop_front();
    if(el1 == "copy"){ S = Copy(); }
    else if(el1 == "add"){ S = Add(); }
    else { S = el1; }
    
    if(elems.empty()) return -20;
    string el2 = elems.front();
    elems.pop_front();
    if(el2.find_first_not_of(ints) == string::npos){ N = stoi(el2); }
    else if(el2 == "find"){ N = Find(); }
    else if(el2 == "rfind"){ N = rFind(); }
    else{ return -20; }
    
    //if(N <= 0 || N > strings.size()) return -20;
    if(strings[N-1].find(S) != string::npos)
    {
        return strings[N-1].find(S);
    }
    else
    {
        return strings[N-1].length();
    }
       
    return -20;
}

int StOperation::rFind()
{
    string S;
    int N;
    
    if(elems.empty()) return -20;
    string el1 = elems.front();
    elems.pop_front();
    if(el1 == "copy"){ S = Copy(); }
    else if(el1 == "add"){ S = Add(); }
    else { S = el1; }
    
    if(elems.empty()) return -20;
    string el2 = elems.front();
    elems.pop_front();
    if(el2.find_first_not_of(ints) == string::npos){ N = stoi(el2); }
    else if(el2 == "find"){ N = Find(); }
    else if(el2 == "rfind"){ N = rFind(); }
    else{ return -20; }
    
    //if(N <= 0 || N > strings.size()) return -20;
    if(strings[N-1].rfind(S) != string::npos)
    {
        return strings[N-1].rfind(S);
    }
    else
    {
        strings[N-1].length();
    }
       
    return -20;
}

void StOperation::Insert()
{
    string S;
    int N;
    int X;
    
    if(elems.empty()) return;
    string el1 = elems.front();
    elems.pop_front();
    if(el1 == "copy"){ S = Copy(); }
    else if(el1 == "add"){ S = Add(); }
    else{ S = el1; }
    
    if(elems.empty()) return;
    string el2 = elems.front();
    elems.pop_front();
    if(el2.find_first_not_of(ints) == string::npos){ N = stoi(el2); }
    else if(el2 == "find"){ N = Find(); }
    else if(el2 == "rfind"){ N = rFind(); }
    else{ return; }
    
    if(elems.empty()) return;
    string el3 = elems.front();
    elems.pop_front();
    if(el3.find_first_not_of(ints) == string::npos){ X = stoi(el3); }
    else if(el3 == "find"){ X = Find(); }
    else if(el3 == "rfind"){ X = rFind(); }
    else { return; }
    
    
    //if(N <= 0 || N > strings.size()) return;
    //if(X < 0 || X >= strings[N-1].size()) return;

    strings[N-1].insert(X,S);

    
}

void StOperation::Reset()
{
    string S;
    int N;
    
    if(elems.empty()) return;
    string el1 = elems.front();
    elems.pop_front();
    if(el1 == "copy"){ S = Copy(); }
    else if(el1 == "add"){ S = Add(); }
    else{ S = el1; }
    
    if(elems.empty()) return;
    string el2 = elems.front();
    elems.pop_front();
    if(el2.find_first_not_of(ints) == string::npos){ N = stoi(el2); }
    else if(el2 == "find"){ N = Find(); }
    else if(el2 == "rfind"){ N = rFind(); }
    else{ return; }
    
    //if(N <= 0 || N > strings.size()) return;
    strings[N-1] = S;
}

void StOperation::Print()
{
    int N;
    if(elems.empty()) return;
    string el = elems.front();
    elems.pop_front();
    if(el.find_first_not_of(ints) == string::npos){ N = stoi(el); }
    else if(el == "find"){ N = Find(); }
    else if(el == "rfind"){ N = rFind(); }
    else{ return; }
    
    if(N <= 0 || N > strings.size()) return;
    printQue.push_back(strings[N-1]);
    
}

void StOperation::PrintAll()
{
    for(auto it = strings.begin(); it != strings.end(); it++)
    {
        printQue.push_back(*it);
    }
}

void StOperation::Over()
{
    for(auto it = printQue.begin(); it != printQue.end(); it++){
        cout << *it << endl;
    }
}


/**
 プログラミングの質問 #4: 文字列操作
 出典: POJ (Coursera の声明: POJ で完了した問題は、Coursera の最終成績にはカウントされません。)

 注: 合計制限時間: 1000ms メモリ制限: 65536kB

 説明
 n 個の文字列 (1 から数えます) が与えられた場合、各文字列の文字位置は 0 から数えられ、長さは 1 から 500 です。

 copy NXL: N 番目の文字列の X 番目の文字から長さ L の文字列を取り出します。

 add S1 S2: S1 と S2 が 0 から 99999 までの整数かどうかを判定し、そうであれば整数に変換して加算し、そうでなければ文字列加算を行い、戻り値は文字列です。

 find SN: N 番目の文字列の左から S 文字列を検索し、最初に出現した位置を返します. 見つからない場合は文字列の長さを返します.

 rfind SN: N 番目の文字列の右から S 文字列を検索し、最初に出現した位置を返します. 見つからない場合は、文字列の長さを返します.

 insert SNX: N 番目の文字列の X 番目の文字位置に S 文字列を挿入します。

 SN のリセット: N 番目の文字列を S に変更します。

 print N: N 番目の文字列を出力します。

 printall: すべての文字列を出力します。

 over: 操作を終了します。

 このうち、N、X、L は find と rfind の演算式で、S、S1、S2 は copy と add の演算式で構成できます。

 入力
 最初の行は整数 n (n は 1 から 20 の間)

 次の n 行は n 個の文字列であり、文字列にはスペースや操作コマンドは含まれません。

 次のいくつかの動作は、オーバーが終了するまでの一連の操作です。

 出力
 操作プロンプトに従って、対応する文字列を出力します。

 Programming Question #4: String Operations
 Source: POJ (Coursera Statement: Problems completed on POJ will not count towards Coursera's final grade.)

 Note: Total Time Limit: 1000ms Memory Limit: 65536kB

 describe
 Given n strings (numbered from 1), the character positions in each string are numbered from 0, and the length is 1-500. There are several operations as follows:

 copy NXL: Take out the string of length L starting from the Xth character of the Nth string.

 add S1 S2: Determine whether S1 and S2 are integers between 0 and 99999. If so, convert them into integers for addition. If not, perform string addition, and the returned value is a string.

 find SN: Find the S string from the left in the Nth string, and return the position of its first occurrence. If not found, return the length of the string.

 rfind SN: Find the S string from the right in the Nth string, and return the position of its first occurrence. If not found, return the length of the string.

 insert SNX: Insert the S string at the Xth character position of the Nth string.

 reset SN: Change the Nth string to S.

 print N: Print the Nth string.

 printall: print out all strings.

 over: End the operation.

 Among them, N, X, L can be formed by find and rfind operation expressions, and S, S1, S2 can be formed by copy and add operation expressions.

 enter
 The first line is an integer n (n is between 1-20)

 The next n lines are n strings, and the strings do not contain spaces and operation commands.

 The next several behaviors are a series of operations until the over ends.

 output
 Output the corresponding string according to the operation prompt.
 
 入力
 3
 329strjvc
 Opadfk48
 Ifjoqwoqejr
 insert copy 1 find 2 1 2 2 2
 print 2
 reset add copy 1 find 3 1 3 copy 2 find 2 2 2 3
 print 3
 insert a 3 2
 printall
 over
 
 出力
 
 Op29adfk48
 358
 329strjvc
 Op29adfk48
 35a8
 
 */







