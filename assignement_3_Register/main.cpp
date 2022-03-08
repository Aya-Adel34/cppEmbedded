#include <iostream>
#include <stdlib.h>

using namespace std;

typedef char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;

template<typename T>
class Register
{
    private:
    T Reg;
    bool RW;
    public:
    Register(bool b):RW(b)
    {

    }
    void ClearBit(int num)
    {
        if(RW)
            Reg = Reg & ~(1 << num);
        else
            cout << "Read Only Register" << endl;
    }
    void SetBit(int num)
    {
        if(RW)
            Reg = Reg |  (1 << num);
        else
            cout << "Read Only Register" << endl;
    }
    T GetBit(int num)
    {
        return (1 & (Reg >> num));
    }
    void setRegisterValue()
    {
        if(RW)
            Reg = (T)~(0);
        else
            cout << "Read Only Register" << endl;
    }
    T getRegisterValue()
    {
        return Reg;
    }
    void display()
    {
        cout << (T)Reg << endl;
    }
};

int main()
{


    return 0;
}