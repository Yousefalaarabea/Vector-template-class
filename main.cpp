/// FCAI – OOP – 2022 - Assignment 3
/// Program Name:  Vector template.cpp
/// Author and ID: Yousef Alaa Rabea 20210476
/// Author and ID: Tasneem Ramadan 20210098

#include <bits/stdc++.h>
#include <iterator>
#include <cstddef>
#include "TYvector.h"
using namespace std;

int main()
{
    int arr[3] = {1, 2, 3};
//    int *ptr = arr;
//    TYVector<int> v2(ptr, 3);

    TYVector<int> v1(5);
    v1.push_Back(12);
    v1.push_Back(25);
    v1.push_Back(5);
    v1.push_Back(4);
    v1.push_Back(9);

    int x=1,y=3;

    v1.inSert(&x, 20);
    cout<<v1;

}
