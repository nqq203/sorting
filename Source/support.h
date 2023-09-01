#pragma once

//LIBRARY INCLUSION
#include <iostream>
#include <time.h>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

//SUPPORTING FUNCTIONS
bool isNumber(string a) {
    for (int i = 0, n = a.length(); i < n; i++) {
        if (!isdigit(a[i]))
            return 0;
    }
    return 1;
}

void swap(int& a, int& b) {
    int k = a;
    a = b;
    b = k;
}

void copyarray(int* a, int* b, int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}

int* dynamicArray(int n) {
    int* a = new int[n+1];
    a[n] = '\0';
    return a;
}

string sortName(string typesort) {
    typesort[0] += 'A' - 'a';

    for (int i = 1, n = typesort.length(); i < n; i++) {
        if (typesort[i] == '-') {
            typesort[i] = ' ';
            typesort[i + 1] += 'A' - 'a';
            break;
        }
    }
    return typesort;
}

void writingFile(int* a, int n)
{
    ofstream out;
    out.open("output.txt");
    out << n << endl;
    for (int i = 0; i < n; i++)
    {
        out << a[i] << " ";
    }
}

void writinginputFile(int* a, int n)
{
    ofstream out;
    out.open("input.txt");
    out << n << endl;
    for (int i = 0; i < n; i++)
    {
        out << a[i] << " ";
    }
}

void writingFileCommand3(string input, int* a, int n)
{
    ofstream out;
    out.open(input);
    out << n << endl;
    for (int i = 0; i < n; i++)
    {
        out << a[i] << " ";
    }
    out.close();
}

void readFile(int* a, int& n, string inputgiven)
{
    ifstream in;
    int i = 0;
    in.open(inputgiven);
    if (in) {
        string line;
        getline(in, line);
        n = stoi(line);
        while (i < n)
        {
            getline(in, line, ' ');
            a[i] = stoi(line);
            i++;
        }
    }
    else cout << "error";
    in.close();
}

void readInputsize(int& n, string inputgiven)
{
    ifstream in(inputgiven);
    if (in.is_open())
    {
        cout << "input sized\n";
        in >> n;
    }
    else
        cout << "ERROR LOADING INPUT\n";
    in.close();
}