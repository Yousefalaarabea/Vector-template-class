#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename t>
class TYVector
{
private:
    t* arr;
    int cap;
    int pos = -1;
public:
    using iterator = t*;
    TYVector(int _cap)
    {
        cout<<"Class is built"<<endl;
        cap = _cap;
        pos = 0;
        arr = new t[cap];
    }

    TYVector (t* arr2, int n ) // Initialize by n items from array
    {
        cout<<"iam here"<<endl;
        pos = n;
        arr = new t[pos];
        for(int i =0 ;i<pos;i++)
        {
            arr[i] = arr2[i];
        }
    }

    ~TYVector()
    {
        delete[] arr;
    }

    TYVector (const TYVector& vec_copy)
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

    TYVector &operator=( TYVector &vec_copy)/// Copy assignment
    {
        cout<<"copy assignment"<<endl;
        vec_copy.pos = this-> pos;
        vec_copy.cap= this ->cap;
        *(vec_copy.arr) =*arr ;
        for(int i=0; i < pos; i++)
        {
           vec_copy.arr[i] =  arr[i] ;
        }
//        cout<<"COPY pos: "<<vec_copy.pos<<endl;
//        cout<<"COPY CAP: "<<vec_copy.cap<<endl;
        return *this;
    }


    TYVector &operator=( TYVector &&vec_copy) /// Move assignment
    {
        cout<<"MOVE assignment"<<endl;
        pos = std::move(vec_copy.pos);
        cap = std::move(vec_copy.cap);
        delete[] arr;
        arr = vec_copy.arr;
        vec_copy.arr = nullptr;
//        cout<<"COPY pos: "<<vec_copy.pos<<endl;
//        cout<<"COPY CAP: "<<vec_copy.cap<<endl;
        return *this;
    }

    t& operator[](int index)
    {
        if(index > (cap-1))
        {
            cout<<"An error has occured, index out of range." << endl;
            exit(-1);
        }
        else
            return arr[index];
    }


    bool isfull()
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

    bool isempty()
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

    bool operator==(const TYVector<t>&vec_copy) /// Return true if ==
    {
        if(cap!=vec_copy.cap || pos!=vec_copy.pos){
            return false;
        }
        else if(cap==vec_copy.cap || pos==vec_copy.pos){
            for(int i=0 ; i<pos;i++){
                if(arr[i] != vec_copy.arr[i]){
                    return false;
                }
            }
        }
        else{
            return true;
        }
    }

    bool operator< (const TYVector<t>& vec_copy) /// Compares item by item, Return true if first different item in this is < in other
    {
        bool flag = false;
        for(int i=0 ; i<pos;i++){
            if(arr[i] < vec_copy.arr[i]){
                flag = true;
                break;
            }
        }
        return flag;
    }



    int push_Back(t element)
    {
        if(isfull())
        {
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
//            cout<<"CURRENT POSITION: "<<pos<<endl;
            return pos;
        }

        else
        {
            cout<<"Element added"<<endl;
            arr[pos]=element;
            pos++;
//            cout<<"CURRENT POSITION: "<<pos<<endl;
            return pos;
        }
    }

    t pop_Back()
    {
        if(isempty()){
            cout<<"An error has occured the vector is empty"<<endl;
        }
        else{
            pos--;
            return arr[pos];
        }
    }

    void inSert(int index, t element) /// Insert item at iterator
    {
        if(index < 0 || index > cap)
        {
            cout<<"invalid index"<<endl;
        }
        else
        {
            pos++;
            for(int i = pos -1 ; i > index ; i--)
            {
                arr[i] = arr[i-1];
            }
            arr[index] = element;
        }
    }

    void eraSe(iterator newpos )
    {
        for(int i = newpos-1; i < end() ; i++)
        {
            arr[i] = arr[i+1];
        }
        pos--;
    }

    void eraSe(iterator p1, iterator p2)
    {
        if(p1==p2){cout<<"INVALID"<<endl;}
        for(int i = p1-1 ; i < end(); i++)
        {
            eraSe(i);
        }
        pos -= (p2-p1);
    }

    iterator begin() {
        return arr;
    }

    iterator end() {
        return (arr + pos -1);
    }

    void Clear()
    {
        pos = 0;
    }

    int siZe()
    {
        return pos;
    }

    int capacity()
    {
        return cap;
    }

    void resiZe(const size_t &newsize)  // Change the size of the vector exactly to "newsize"
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

    void display(){
        for(int i =0;i<pos;i++){
            cout<<arr[i]<<" ";
        }
    cout<<endl;
    }

    friend ostream& operator << (ostream& out, const TYVector<t>& vec_copy);

};

template<typename t>
ostream& operator << (ostream& out, const TYVector<t>& vec_copy)
{
    for(int i =0 ;i < vec_copy.pos ; i++)
    {
        out<<"Element "<<i+1<<" -> "<<vec_copy[i];
    }
    return out;
}

int main()
{
    int arr[3]={1,2,3};
    int *ptr = arr;
    TYVector<string> v1(5);
    TYVector<int> v2(ptr,3);

//    v1.push_Back("one");
//    v1.push_Back("two");
//    v1.push_Back("three");
//    v1.push_Back("four");

    v2.push_Back(9);
    v2.push_Back(10);
    v2.push_Back(11);

    v2.inSert(2,20);
//
//    v2.pop_Back();
//    v2.pop_Back();
//
//    v2.display();

//    int x =*(v2.begin());
//    int y =*(v2.end());
//    cout<<x<<" "<<y;


    v2.eraSe(2);

    v1.display();

//    cout<<v1;

//    v1=v2;

//    if(v1 < v2)
//    {
//        cout<<"YUP"<<endl;
//    }
//    else{
//        cout<<"LOL"<<endl;
//    }
}
