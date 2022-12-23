#ifndef TYVECTOR_H
#define TYVECTOR_H
/// FCAI – OOP – 2022 - Assignment 3
/// Program Name:  Vector template.cpp
/// Author and ID: Yousef Alaa Rabea 20210476
/// Author and ID: Tasneem Ramadan 20210098

#include <bits/stdc++.h>
#include <iterator>
#include <cstddef>
#include "TYvector.h"
using namespace std;


template<typename t>
class TYVector
{
private:
    t* arr;
    int cap;
    int pos = -1;

public:

    class iterator
    {
    private:
        t* p = nullptr;
    public:
        iterator(t* const ptr)
        {
            p = ptr;
        }
        t& operator*()
        {
            return *p;
        }
        t const& operator*()const
        {
            return *p;
        }
        t* operator->()
        {
            return p;
        }

        iterator& operator++() //prefix
        {
            ++p;
            return *this;
        }
        iterator operator++(t)   //postfix
        {
            iterator temp(*this);
            operator++();
            return temp;
        }
        iterator& operator--() //prefix
        {
            --p;
            return *this;
        }
        iterator operator--(t)
        {
            return p--;
        } //postfix

        iterator& operator+=(t n)
        {
            p += n;
            return *this;
        }
        iterator& operator-=( t n)
        {
            p -= n;
            return *this;
        }

        iterator operator+ (t  n)
        {
            iterator temp(*this);
            temp.p += n;
            return temp;
        }
        iterator operator- (t  n)
        {
            iterator temp(*this);
            temp.p -= n;
            return temp;
        }
        size_t operator- (const iterator&  i)
        {
            return p - i.p;
        }

        bool operator== (const iterator&  i)
        {
            return p == i.p;
        }
        bool operator!= (const iterator&  i)
        {
            return p != i.p;
        }
        bool operator> (const iterator&  i)
        {
            return p > i.p;
        }
        bool operator< (const iterator& i)
        {
            return p < i.p;
        }
        bool operator>= (const iterator& i)
        {
            return p >= i.p;
        }
        bool operator<= (const iterator&  i)
        {
            return p <= i.p;
        }
    };

    iterator begin()
    {
        return iterator(arr);
    }
    iterator end()
    {
        return iterator(arr + pos);
    }

    TYVector(int _cap);
    TYVector (t* arr2, int n ); // Initialize by n items from array
    ~TYVector();
    TYVector (const TYVector& vec_copy);
    TYVector &operator=( TYVector &vec_copy);/// Copy assignment
    TYVector &operator=( TYVector &&vec_copy); /// Move assignment
    t& operator[](int index);
    bool isfull();
    bool isempty();
    bool operator==(const TYVector<t>&vec_copy);
    bool operator< (const TYVector<t>& vec_copy);
    int push_Back(t element);
    t pop_Back();
    void inSert(iterator index, t element); /// Insert item at iterator
    void eraSe(iterator it );
    void eraSe(iterator it1, iterator it2);
    void Clear();
    int siZe();
    int capacity();
    void resiZe(const size_t &newsize);  // Change the size of the vector exactly to "newsize"
    void display();
    template<typename newtype>
    friend ostream& operator << (ostream& out, TYVector<newtype>& vec_copy);

};

template<typename t>
TYVector<t>::TYVector(int _cap)
{
    cout<<"Class is built"<<endl;
    cap = _cap;
    pos = 0;
    arr = new t[cap];
}

template<typename t>
TYVector<t>::TYVector (t* arr2, int n ) // Initialize by n items from array
{
    cout<<"iam here"<<endl;
    pos = n;
    arr = new t[pos];
    for(int i =0 ; i<pos; i++)
    {
        arr[i] = arr2[i];
    }
}

template<typename t>
TYVector<t>::~TYVector()
{
    delete[] arr;
}

template<typename t>
TYVector<t>::TYVector (const TYVector& vec_copy)
{
    cout<<"copy constructor"<<endl;
    cap = vec_copy.cap;
    pos = vec_copy.pos;
    vec_copy.arr = new t[cap];
    *(vec_copy.arr) = *arr;
    for(int i=0; i<cap; i++)
    {
        vec_copy[i] = arr[i];
    }
}

template<typename t>
TYVector<t> &TYVector<t>:: operator=( TYVector &vec_copy)/// Copy assignment
{
    cout<<"copy assignment"<<endl;
    vec_copy.pos = this-> pos;
    vec_copy.cap= this ->cap;
    *(vec_copy.arr) =*arr ;
    for(int i=0; i < pos; i++)
    {
        vec_copy.arr[i] =  arr[i] ;
    }
    return *this;
}

template<typename t>
TYVector<t> &TYVector<t>:: operator=( TYVector &&vec_copy) /// Move assignment
{
    cout<<"MOVE assignment"<<endl;
    pos = std::move(vec_copy.pos);
    cap = std::move(vec_copy.cap);
    delete[] arr;
    arr = vec_copy.arr;
    vec_copy.arr = nullptr;
    return *this;
}

template<typename t>
t& TYVector<t>::operator[](int index)
{
    if(index > (cap-1))
    {
        cout<<"An error has occured, index out of range." << endl;
        exit(-1);
    }
    else
        return arr[index];
}

template<typename t>
bool TYVector<t>::isfull()
{
    if(pos == (cap - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

template<typename t>
bool TYVector<t>::isempty()
{
    if(pos == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

template<typename t>
bool TYVector<t>::operator==(const TYVector<t>&vec_copy) /// Return true if ==
{
    if(cap!=vec_copy.cap || pos!=vec_copy.pos)
    {
        return false;
    }
    else if(cap==vec_copy.cap || pos==vec_copy.pos)
    {
        for(int i=0 ; i<pos; i++)
        {
            if(arr[i] != vec_copy.arr[i])
            {
                return false;
            }
        }
    }
    else
    {
        return true;
    }
}

template<typename t>
bool TYVector<t>::operator< (const TYVector<t>& vec_copy) /// Compares item by item, Return true if first different item in this is < in other
{
    bool flag = false;
    for(int i=0 ; i<pos; i++)
    {
        if(arr[i] < vec_copy.arr[i])
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template<typename t>
int TYVector<t>::push_Back(t element)
{
    if(isfull())
    {
        cout<<"CURRENT POSITION: "<<pos<<endl;
        cout << "Resizing to " << cap*2 << endl;
        t* newarr = new t[cap*2];
        cap *= 2;

        for(int i = 0; i < cap; i++)
        {
            newarr[i] = arr[i];
        }
        delete [] arr;
        arr = newarr;
        newarr = nullptr;
        arr[pos] = element;
        pos++;
        return pos;
    }

    else
    {
        cout<<"Element added"<<endl;
        arr[pos]=element;
        pos++;
        return pos;
    }
}

template<typename t>
t TYVector<t>::pop_Back()
{
    if(isempty())
    {
        cout<<"An error has occured the vector is empty"<<endl;
    }
    else
    {
        pos--;
        return arr[pos];
    }
}

template<typename t>
void TYVector<t>::inSert(iterator index, t element) /// Insert item at iterator
{
    cout<<"Here"<<endl;
    if (pos >= cap)
    {
        cap *= 2;
        t *temparr = new t[cap];
        for (int i = 0; i < cap; i++)
        {
            temparr[i] = arr[i];
        }
        delete[] arr;
        arr = temparr;
    }
    else
    {
        for (iterator i = end(); *i != *index; i--)
        {
            *i = *(i-1);
        }
        arr[*index] = element;
        pos++;
    }
}

template<typename t>
void TYVector<t>::eraSe(iterator it )
{
    for(iterator i = it; i < end() ; i++)
    {
        *i = *(i+1);
    }
    pos--;
}

template<typename t>
void TYVector<t>::eraSe(iterator it1, iterator it2)
{
    cout<<"old pos: "<<pos<<endl;
    if(*it1==*it2)
    {
        cout<<"INVALID"<<endl;
        return;
    }
    for(iterator i = it1 ; *i < *it2; i++)
    {
        eraSe(i);
    }
    cout<<"New pos: "<<pos<<endl;


}

template<typename t>
void TYVector<t>::Clear()
{
    delete []arr;
    pos = 0;
    cap=0;
}

template<typename t>
int TYVector<t>::siZe()
{
    return pos;
}

template<typename t>
int TYVector<t>::capacity()
{
    return cap;
}

template<typename t>
void TYVector<t>::resiZe(const size_t &newsize)  // Change the size of the vector exactly to "newsize"
{
    if(newsize<pos)
    {
        for(size_t i=newsize; i<pos; i++)
        {
            arr[i].~t();
        }
    }
    else if(newsize>cap)
    {
        t* temp=new t[newsize];
        std::copy(arr,arr+cap,temp);
        delete[] arr;
        arr=temp;
        cap=newsize;
    }
    pos = newsize;
}

template<typename t>
void TYVector<t>::display()
{
    for(int i =0; i < pos; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

template<typename newtype>
ostream& operator << (ostream& out, TYVector<newtype>& vec_copy)
{

    for(int i =0 ; i < vec_copy.siZe() ; i++)
    {
        out<<"Element "<<i+1<<" -> "<<vec_copy[i]<<" ";
    out<<endl;
    }
    return out;
}

#endif // TYVECTOR_H
