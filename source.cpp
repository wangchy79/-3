#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int i = 0;
int j = 1;
string s;
vector<string> stack;
void GEQ(char a)
{
    int L = stack.size();
    string M1, M2, M3, M4;
    M1 += a;
    M2 = stack[L - 2];
    M3 = stack[L - 1];
    stack.pop_back();
    stack.pop_back();
    M4 += 't';
    string m = to_string(j);
    j += 1;
    M4 += m;
    stack.push_back(M4);
    cout << "( " << M1 << " " << M2 << " " << M3 << " " << M4 << " )" << endl;
}

bool is_zimu(char a)
{
    if (a >= 'a' && a <= 'z')
        return true;
    if (a >= 'A' && a <= 'Z')
        return true;
    return false;
}

void F()
{
    if (is_zimu(s[i]))
    {
        string m;
        m += s[i];
        stack.push_back(m);
    }
    else if (s[i] != '(')
        cout << "error1";
    else
    {
        i += 1;
    // E();
    // T();
    AA:
        F();
        while (1)
        {
            if (s[i] == '*')
            {
                i++;
                F();
                GEQ('*');
            }
            else if (s[i] == '/')
            {
                i++;
                F();
                GEQ('/');
            }
            else
                break;
        }
        while (1)
        {
            if (s[i] == '+')
            {
                i++;
                goto AA;
                GEQ('+');
            }
            else if (s[i] == '-')
            {
                i++;
                goto AA;
                GEQ('-');
            }
            else
                break;
        }
        if (s[i] != ')')
        {
            cout << "error2";
            return;
        }
    }
    i += 1;
    return;
}

void T()
{
    F();
    while (1)
    {
        if (s[i] == '*')
        {
            i++;
            F();
            GEQ('*');
        }
        else if (s[i] == '/')
        {
            i++;
            F();
            GEQ('/');
        }
        else
            return;
    }
}

void E()
{
    T();
    while (1)
    {
        if (s[i] == '+')
        {
            i++;
            T();
            GEQ('+');
        }
        else if (s[i] == '-')
        {
            i++;
            T();
            GEQ('-');
        }
        else
            return;
    }
}

int main()
{
    ifstream fin;
    fin.open("test.txt");
    fin >> s;
    s += '#';
    int len = s.length();
    char next;
    E();
    if (s[i] == '#')
    {
        cout << "success!";
    }
    else
        cout << "error0";
}