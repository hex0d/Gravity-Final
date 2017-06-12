#include "TErro.h"
#include <iostream>
using namespace std;
#include <string>

template<class E>
class TErro
{
public:
    TErro(E val)
    {
        if(val == 1)
        {
            cout<<"erro inic Allegro"<<endl;
        }
        else if(val ==1.5)
        {
            cout<<"errinho"<<endl;
        }
    }
    virtual ~TErro(){};

protected:

private:
};




