//includes 
#include  <ctime>
#include <iostream>
#include <math.h> 
#include<string>
#include <array>

//

bool isNum(char i){return 48>i|| i< 57;}
//to number
//@param __str transformint
int strto(const char* __str)
{
    //returning
    int returning =0;
    //forloop
    for (size_t i = 0; i < sizeof(i)/sizeof(char); i++)
    {
        //error
         if(!isNum(__str[i])){throw __str;}
         //
         int adding = int(__str[i])-48;
         //  
         returning+=pow(10,i)*adding;
    }
    return returning;
} 
//timer that create time;
struct _time
{
    private:
    //self
    time_t t;
    public:
    _time  (){t=0;}
    //that create timer from starter
    //@param st that that start it
    _time(time_t st):t(st ){}
    //that creat time for
    //@param t that date start it
    _time(struct tm t) {_time(  time_t(  mktime(&t)) );}
    //formate
    //@param s second
    //@param m minute
    //@param h heure
    //@param d days
    //@param w week 
    //@param \n  mouth
    //@param y years
    _time(const char* format )
    { 
        //vars
        const size_t s=sizeof(format)/2*sizeof(char) ;
        size_t sizeofNum=0;
        time_t returning=0; 
        char *strnum;  
        size_t __per;
        //forloop
        for (size_t i =s  ; i >=0   ; i --)
        { 
            std::cout<<format[s-i]<<std::endl;
          /*num*/  if (isNum(format[i]))  {strnum[s-i]=format[i];}
          //mins
          else
          {
            switch (format[i])
            {
            default:
                throw format;
                break;
            case 's':
                   __per=1 ;
                break;
            case 'm':
            __per=60;break;
            case 'h':
            __per =3600;break;
            case 'd':
            __per= 86400;break;
            case 'w':
            __per=604800;break;
            case '\n':
            __per =18144000;break;
            case 'y':
            __per =220752000;break;  
            }
            
            returning+=strto(strnum)*__per;
          }
        std::cout<<returning<<std::endl;
          
        } 
        t=returning; 
    } 
   //operator
   //
   _time operator+(_time s){_time returning; returning.t=s.t+t;return returning;}
   //
   _time operator-(){_time returning;returning.t=-t;return returning;}
   //
   _time operator-(_time s){return *this+(-s);}
   //
   _time operator*(size_t s){_time returning;returning.t*=s;return returning;}
   //
   _time operator/(size_t s){_time returnig;returnig.t/=s;return returnig;}
   //
   void operator+=(_time s){*this=operator+(s);}
   void operator-=(_time s){*this=operator-(s);}
   void operator*=(size_t s){*this=operator*(s);}
   void operator/=(size_t s){*this=operator/(s); }
};  

//
class timer 
{
    //vars
private:
_time begin;
public:
//
timer(){begin = _time(time(NULL));}
//
_time t(){return _time(  time(nullptr));}
};

