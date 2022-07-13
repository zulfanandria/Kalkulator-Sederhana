#include <iostream>
#include <stack>
#include <math.h>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string InPostfix;

int Operator(char Hitung)
{
    if (Hitung == '^')
    {
        return 3;
    }
    else if (Hitung == '/' || Hitung == '*')
    {
        return 2;
    }
    else if (Hitung == '+' || Hitung == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void InfixKePostfix(string input)
{
    stack<char> iStack;
    for (int i = 0; i < input.length(); i++)
    {
        char Hitung = input[i];
        if (Hitung >= '0' && Hitung <= '9')
            InPostfix += Hitung;
        else if (Hitung == '(')
            iStack.push('(');
        else if (Hitung == ')')
        {
            while (iStack.top() != '(')
            {
                InPostfix += iStack.top();
                iStack.pop();
            }
            iStack.pop();
        }
        else
        {
            while (!iStack.empty() && Operator(input[i]) <= Operator(iStack.top()))
            {
                InPostfix += iStack.top();
                iStack.pop();
            }
            iStack.push(Hitung);
        }
    }
    while (!iStack.empty())
    {
        InPostfix += iStack.top();
        iStack.pop();
    }
}

int CalcuPostfix(string input)
{
    stack<int> jStack;
    int pjg = input.length();
    for (int j = 0; j < pjg; j++)
    {
        if (input[j] >= '0' && input[j] <= '9')
        {
            jStack.push(input[j] - '0');
        }
        else
        {
            int Num1 = jStack.top();
            jStack.pop();
            int Num2 = jStack.top();
            jStack.pop();
            if (input[j] == '+')
            {
                jStack.push(Num1 + Num2);
            }
            else if (input[j] == '-')
            {
                jStack.push(Num2 - Num1);
            }
            else if (input[j] == '/')
            {
                jStack.push(Num2 / Num1);
            }
            else if (input[j] == '*')
            {
                jStack.push(Num2 * Num1);
            }
            else if (input[j] == '^')
            {
                jStack.push(pow(Num2, Num1));
            }
        }
    }
    return jStack.top();
}

int main()
{
    // Input perhitungan ex :1 + 2 * 2 - 3 / 3
    string input;
    getline(cin, input);

    // Menghilangkan spasi menjadi bentuk Infix
    int len = input.length();
    int nSpace = count(input.begin(), input.end(), ' ');
    remove(input.begin(), input.end(), ' ');
    input.resize(len - nSpace);

    // Mengubah Infix menjadi Postfix
    InfixKePostfix(input);

    // Menghitung Postfix
    input = InPostfix;
    CalcuPostfix(input);
    cout << CalcuPostfix(input);

    return 0;
}