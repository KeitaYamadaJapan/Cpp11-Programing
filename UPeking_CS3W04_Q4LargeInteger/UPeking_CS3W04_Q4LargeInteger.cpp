//
//  main.cpp
//  UPeking_CS3W04_Q4LargeInteger_DivB
//
//  Created by 山田啓太 on 2022/11/21.
//

/**
Cousera 北京大学　CS3 week4 Q1
My solution
*/

#include <iostream>
#include <string>
#include <deque>
#include <vector>

using namespace std;

deque<long long> lintQue;
const long long llMax = 1000000000;
const long long    N9 = 100000000;
const int e1 = 12;
const int e2 = 24;


class largeInteger
{
private:
    string flag;
    long long largeInt[e2+1];
    
public:
    largeInteger()
    {
        fill_n(largeInt,e2+1,0);
        flag = "+";
    }
    largeInteger(largeInteger& other)
    :flag(other.Flag())
    {
        for(int i = 0; i < e2+1; i++)
        {
            largeInt[i] = other.lInt(i);
        }
    }
       
    void setInteger(const string& str);
    
    long long& lInt(int l)
    {
        long long num = largeInt[l];
        return num;
    }
    void setVal(int idx, long long val)
    {
        largeInt[idx] = val;
    }
    
    string Flag(){ return flag; }
    
    void Print();
    
    void Add(largeInteger& lg1, largeInteger& lg2);
    void Add(largeInteger& lg);
    void Sub(largeInteger& lg1, largeInteger& lg2);
    void SubNoPrint(largeInteger& lg1, largeInteger& lg2);
    void Sub(largeInteger& lg);
    void exSub(largeInteger& lgl, largeInteger& lgs);
    void Mult(largeInteger& lg1, largeInteger& lg2);
    void MultNoPrint(largeInteger& lg1, largeInteger& lg2);
    void Mult(largeInteger& lg);
    void Div(largeInteger& lg1, largeInteger& lg2);
    
    int getIdx()
    {
        int p = e2;
        while(largeInt[p] == 0)
        {
            p--;
        }
        return p;
    }
    
    void operator =(largeInteger& lg);
    void Copy(largeInteger& lg);
    
    void disp()
    {
        for(int i = 0; i <= e2; i++)
        {
            cout << largeInt[i] << endl;
        }
    }
};

//largeInteger fCK;

int compLL(const largeInteger& lg1, const largeInteger& lg2);


int main(){
    cout << endl;
    largeInteger lg1;
    largeInteger lg2;
    largeInteger RS;
    string str1,op,str2;
    cin >> str1;
    cin >> op;
    cin >> str2;
    
    lg1.setInteger(str1);
    lg2.setInteger(str2);
    
    cout << endl;
    if(op == "+"){ RS.Add(lg1,lg2); }
    else if(op == "-"){ RS.Sub(lg1,lg2); }
    else if(op == "*"){ RS.Mult(lg1,lg2); }
    else if(op == "/"){ RS.Div(lg1,lg2); }
    
    return 0;
}



int compLL(largeInteger& lg1, largeInteger& lg2)
{
    for(int i = e1+1; i >= 0; i--)
    {
        if(lg1.lInt(i) > lg2.lInt(i)) return 1;
        if(lg1.lInt(i) < lg2.lInt(i)) return 2;
    }
    return 0;
}


void largeInteger::operator= (largeInteger& lg)
{
    for(int i = 0; i < e2+1; i++)
    {
        largeInt[i] = lg.lInt(i);
    }
}

void largeInteger::Copy(largeInteger& lg)
{
    for(int i = 0; i < e2+1; i++)
    {
        largeInt[i] = lg.lInt(i);
    }
}

void largeInteger::Print()
{
    int tp = -1;
    vector<string> pQ;
    if(flag == "-") pQ.push_back(flag);
    for(int k = e2; k >= 0; k--)
    {
        if(largeInt[k] > 0)
        {
            tp = k;
            pQ.push_back(to_string(largeInt[tp]));
            break;
        }
    }
    for(int k = tp-1; k >= 0; k--)
    {
        long long num = largeInt[k];
        string zs = "000000000";
        string s = to_string(num);
        string ts = zs.substr(0,9-s.length()) + s;
        pQ.push_back(ts);
    }
    
    
    for(auto it = pQ.begin(); it != pQ.end(); it++)
    {
        cout << *it;
    }
    cout << endl;
}

void largeInteger::Add(largeInteger& lg1, largeInteger& lg2)
{
    for(int i = 0; i < e1; i++)
    {
        long long r = lg1.lInt(i) + lg2.lInt(i);
        largeInt[i+1] += r/llMax;
        largeInt[i] += r%llMax;
    }
    for(int j = 0; j < e2; j++)
    {
        long long r2 = largeInt[j];
        largeInt[j] = r2%llMax;
        largeInt[j+1] += r2/llMax;
    }
    Print();
}

void largeInteger::Add(largeInteger& lg)
{
    for(int i = 0; i < e2; i++)
    {
        largeInt[i] += lg.lInt(i);
    }
    for(int i = 0; i < e2; i++)
    {
        long long val = largeInt[i];
        largeInt[i] = val%llMax;
        largeInt[i+1] += val/llMax;
    }
}

void largeInteger::Sub(largeInteger& lg)
{
    for(int i = 0; i < e2; i++)
    {
        largeInt[i] -= lg.lInt(i);
    }
    for(int i = 0; i < e2; i++)
    {
        if(largeInt[i] < 0)
        {
            largeInt[i] += llMax;
            largeInt[i+1] -= 1;
        }
    }
}

void largeInteger::Sub(largeInteger& lg1, largeInteger& lg2)
{
    int flg = compLL(lg1, lg2);
    if(flg == 0)
    {
        cout << "0" << endl;
        return;
    }
    
    if(flg == 1){ exSub(lg1,lg2); }
    else if(flg == 2)
    {
        flag = "-";
        exSub(lg2,lg1);
    }
    Print();
}

void largeInteger::SubNoPrint(largeInteger& lg1, largeInteger& lg2)
{
    int flg = compLL(lg1, lg2);
    if(flg == 0)
    {
        cout << "0" << endl;
        return;
    }
    
    if(flg == 1){ exSub(lg1,lg2); }
    else if(flg == 2)
    {
        flag = "-";
        exSub(lg2,lg1);
    }
}
    
void largeInteger::exSub(largeInteger& lgl, largeInteger& lgs)
{
    for(int i = 0; i < e1; i++)
    {
        largeInt[i] += lgl.lInt(i);
        largeInt[i] -= lgs.lInt(i);
  
    }
    for(int i = 0; i < e1; i++)
    {
        if(largeInt[i] < 0)
        {
            largeInt[i] += llMax;
            largeInt[i+1] -= 1;
        }
    }
}

void largeInteger::Mult(largeInteger& lg1, largeInteger& lg2)
{
    for(int i = 0; i < e1; i++)
    {
        for(int j = 0; j < e1; j++)
        {
            long long val = largeInt[i+j] + lg1.lInt(i) * lg2.lInt(j);
            largeInt[i+j] = val%llMax;
            largeInt[i+j+1] += val/llMax;
        }
    }
    for(int k = 0; k < e2; k++)
    {
        long long val = largeInt[k];
        largeInt[k] = val%llMax;
        largeInt[k+1] += val/llMax;
    }
    Print();
}

void largeInteger::MultNoPrint(largeInteger& lg1, largeInteger& lg2)
{
    for(int i = 0; i < e1; i++)
    {
        for(int j = 0; j < e1; j++)
        {
            long long val = largeInt[i+j] + lg1.lInt(i) * lg2.lInt(j);
            largeInt[i+j] = val%llMax;
            largeInt[i+j+1] += val/llMax;
        }
    }
    for(int k = 0; k < e2; k++)
    {
        long long val = largeInt[k];
        largeInt[k] = val%llMax;
        largeInt[k+1] += val/llMax;
    }
}

void largeInteger::Div(largeInteger& lg1, largeInteger& lg2)
{
    int larger = compLL(lg1,lg2);
    if(larger == 2)
    {
        cout << "0" << endl;
        return;
    }
    if(larger == 0)
    {
        cout << "1" << endl;
        return;
    }
    
    largeInteger lgB(lg1);
    largeInteger lgS(lg2);
    
    
    bool isEnd = false;
    
    while(isEnd == false)
    {
        largeInteger lgPro, lgQuo, lgRem;
        int p = lgB.getIdx();
        int q = lgS.getIdx();
        long long vB = lgB.lInt(p);
        long long vS = lgS.lInt(q);
        if(vB < vS){
            vB = vB*llMax + lgB.lInt(p-1);
            p--;
        }
        long long quo = vB/vS;

        lgQuo.setVal(p-q,quo);
        lgPro.MultNoPrint(lgQuo, lgS);

        Add(lgQuo);
        lgRem.SubNoPrint(lgB,lgPro);
        lgB.Copy(lgRem);
        if(compLL(lgB,lgS) == 2)
        {
            isEnd = true;
        }
    }
    Print();
    return;
}


void largeInteger::setInteger(const string& bigint0)
{
    string bigint;
    if(bigint0[0] == '-')
    {
        flag = "-";
        bigint = bigint0.substr(1);
    }else{
        flag = "+";
        bigint = bigint0;
    }
    
    int sz = bigint.length();
    if(sz <= 9)
    {
        largeInt[0] = stoull(bigint);
    }else if(sz <= 18)
    {
        largeInt[0] = stoull(bigint.substr(sz-9));
        largeInt[1] = stoull(bigint.substr(0,sz-9));
    }
    else if(sz <= 27)
    {
        largeInt[0] = stoull(bigint.substr(sz-9));
        largeInt[1] = stoull(bigint.substr(sz-18,9));
        largeInt[2] = stoull(bigint.substr(0,sz-18));
    }
    else if(sz <= 36)
    {
        largeInt[0] = stoull(bigint.substr(sz-9));
        largeInt[1] = stoull(bigint.substr(sz-18,9));
        largeInt[2] = stoull(bigint.substr(sz-27,9));
        largeInt[3] = stoull(bigint.substr(0,sz-27));
    }
    else if(sz <= 45)
    {
        largeInt[0] = stoull(bigint.substr(sz-9));
        largeInt[1] = stoull(bigint.substr(sz-18,9));
        largeInt[2] = stoull(bigint.substr(sz-27,9));
        largeInt[3] = stoull(bigint.substr(sz-36,9));
        largeInt[4] = stoull(bigint.substr(0, sz-36));
    }
    else if(sz <= 54)
    {
        largeInt[0] = stoull(bigint.substr(sz-9));
        largeInt[1] = stoull(bigint.substr(sz-18,9));
        largeInt[2] = stoull(bigint.substr(sz-27,9));
        largeInt[3] = stoull(bigint.substr(sz-36,9));
        largeInt[4] = stoull(bigint.substr(sz-45,9));
        largeInt[5] = stoull(bigint.substr(0,sz-45));
    }
    else if(sz <= 63)
    {
        largeInt[0] = stoull(bigint.substr(sz-9));
        largeInt[1] = stoull(bigint.substr(sz-18,9));
        largeInt[2] = stoull(bigint.substr(sz-27,9));
        largeInt[3] = stoull(bigint.substr(sz-36,9));
        largeInt[4] = stoull(bigint.substr(sz-45,9));
        largeInt[5] = stoull(bigint.substr(sz-54,9));
        largeInt[6] = stoull(bigint.substr(0,sz-54));
    }
    else if(sz <= 72)
    {
        largeInt[0] = stoull(bigint.substr(sz-9));
        largeInt[1] = stoull(bigint.substr(sz-18,9));
        largeInt[2] = stoull(bigint.substr(sz-27,9));
        largeInt[3] = stoull(bigint.substr(sz-36,9));
        largeInt[4] = stoull(bigint.substr(sz-45,9));
        largeInt[5] = stoull(bigint.substr(sz-54,9));
        largeInt[6] = stoull(bigint.substr(sz-63,9));
        largeInt[7] = stoull(bigint.substr(0,sz-63));
    }
    else if(sz <= 81)
    {
        largeInt[0] = stoull(bigint.substr(sz-9));
        largeInt[1] = stoull(bigint.substr(sz-18,9));
        largeInt[2] = stoull(bigint.substr(sz-27,9));
        largeInt[3] = stoull(bigint.substr(sz-36,9));
        largeInt[4] = stoull(bigint.substr(sz-45,9));
        largeInt[5] = stoull(bigint.substr(sz-54,9));
        largeInt[6] = stoull(bigint.substr(sz-63,9));
        largeInt[7] = stoull(bigint.substr(sz-72,9));
        largeInt[8] = stoull(bigint.substr(0,sz-72));
    }
    else if(sz <= 90)
    {
        largeInt[0] = stoull(bigint.substr(sz-9));
        largeInt[1] = stoull(bigint.substr(sz-18,9));
        largeInt[2] = stoull(bigint.substr(sz-27,9));
        largeInt[3] = stoull(bigint.substr(sz-36,9));
        largeInt[4] = stoull(bigint.substr(sz-45,9));
        largeInt[5] = stoull(bigint.substr(sz-54,9));
        largeInt[6] = stoull(bigint.substr(sz-63,9));
        largeInt[7] = stoull(bigint.substr(sz-72,9));
        largeInt[8] = stoull(bigint.substr(sz-81,9));
        largeInt[9] = stoull(bigint.substr(0,sz-81));
    }
    else if(sz <= 99)
    {
        largeInt[0] = stoull(bigint.substr(sz-9));
        largeInt[1] = stoull(bigint.substr(sz-18,9));
        largeInt[2] = stoull(bigint.substr(sz-27,9));
        largeInt[3] = stoull(bigint.substr(sz-36,9));
        largeInt[4] = stoull(bigint.substr(sz-45,9));
        largeInt[5] = stoull(bigint.substr(sz-54,9));
        largeInt[6] = stoull(bigint.substr(sz-63,9));
        largeInt[7] = stoull(bigint.substr(sz-72,9));
        largeInt[8] = stoull(bigint.substr(sz-81,9));
        largeInt[9] = stoull(bigint.substr(sz-90,9));
        largeInt[10] = stoull(bigint.substr(0,sz-90));
    }
    else
    {
        largeInt[0] = stoull(bigint.substr(sz-9));
        largeInt[1] = stoull(bigint.substr(sz-18,9));
        largeInt[2] = stoull(bigint.substr(sz-27,9));
        largeInt[3] = stoull(bigint.substr(sz-36,9));
        largeInt[4] = stoull(bigint.substr(sz-45,9));
        largeInt[5] = stoull(bigint.substr(sz-54,9));
        largeInt[6] = stoull(bigint.substr(sz-63,9));
        largeInt[7] = stoull(bigint.substr(sz-72,9));
        largeInt[8] = stoull(bigint.substr(sz-81,9));
        largeInt[9] = stoull(bigint.substr(sz-90,9));
        largeInt[10] = stoull(bigint.substr(sz-99,9));
        largeInt[11] = stoull(bigint.substr(0,sz-99));
    }
    
    //for(int i = 0; i < e1; i++)
    //{
    //    cout << largeInt[i] << "  ";
    //}
    //cout << endl;
    
}


/**
 
 コーディングの問題 #4: 大きな整数の足し算、引き算、掛け算、割り算
 出典: POJ (Coursera の免責事項: POJ で完了した演習は、Coursera の最終成績にはカウントされません。)

 注: 合計制限時間: 1000ms メモリ制限: 65536kB

 説明
 2 つの正の整数と 4 つの算術演算子 (+ - * /) を指定して、演算の結果を見つけます。

 入力
 最初の行: 正の整数 a、長さが 100 を超えない

 2 行目: 4 つの算術演算子 o、o は「+」、「-」、「*」、「/」のいずれかです

 3 行目: 正の整数 b、長さが 100 を超えない

 入力に余分なスペースやその他の文字が含まれていないことを確認してください

 出力
 1 行: 式 "aob" の値。

 補足:

 1. 減算結果が負の場合がある

 2. 除算結果は切り捨て

 3.出力は、余分な0、スペース、またはその他の文字なしで、毎日の書き方の習慣に準拠しています


 Coding problem #4: Addition, subtraction, multiplication and division of large integers
 Source: POJ (Coursera Disclaimer: Exercises completed on POJ will not count toward your final Coursera grade.)

 Note: Total time limit: 1000ms Memory limit: 65536kB

 describe
 Given two positive integers and the four arithmetic operators (+ - * /), find the result of the operation.

 enter
 The first line: positive integer a, the length does not exceed 100

 The second line: four arithmetic operators o, o is one of "+", "-", "*", "/"

 The third line: positive integer b, the length does not exceed 100

 Ensure that the input does not contain extra spaces or other characters

 output
 One line: the value of the expression "aob".

 Supplementary note:

 1. The subtraction result may be negative

 2. The division result is rounded down

 3. The output conforms to daily writing habits, without extra 0, spaces or other characters

 sample input
 
 9876543210
 +
 9876543210
 
 output
 
 19753086420
 */


/**
 
 12345678901234567890123456
 +
 12345678901234567890123456
 
 1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
 +
 1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
 
 12345678901234567890123456
 -
 12345678901234567890123456
 
 1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
 -
 12345678901234567890123456789012345678901234567890123456789012345678901234567890123
*
 1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
 
 7894123653200026589
 -
 23549687569756859
 
 7894123653200026589
 *
 23549687569756859
 
 963569879685
 *
 56749
 
 1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
/
7890123456789012345678901234567890123456789012345678901234567890123456789012345678901
 
 */


