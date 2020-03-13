#include"alcdata.h"
#include<string>
#include<cstdio>
#include<cmath>
template<typename T, int n> T max(const T (&arr)[n])
{
    T ret = arr[0];
    for ( T x: arr)
        if (x > ret )
            ret = x;
    return ret;
}
bool getNextDouble(std::istream & in, double & res)
{
    if (!in.good())
            return false;
    std::string str;
    getline(in, str, ';');
    if (!in.good())
            return false;
    if (sscanf(str.c_str(),"%lf",&res) != 1)
        in.setstate(std::ios::failbit);
    return in.good();
}
bool getNextInt(std::istream & in, int & res)
{
    if (!in.good())
            return false;
    std::string str;
    getline(in, str, ';');
    if (!in.good())
            return false;
    if (sscanf(str.c_str(),"%d",&res) != 1)
        in.setstate(std::ios::failbit);
    return in.good();
}
std::istream & operator >> (std::istream & in, AlcData & a)
{
    if ( !getNextDouble(in,a.measure_time) ||
         !getNextInt(in,a.cycle_number) ||
         !getNextDouble(in,a.force) ||
         !getNextDouble(in,a.dummy1) ||
         !getNextDouble(in,a.displacement))
        return in;
    for (double & t: a.temperatures)
         if (!getNextDouble(in,t))
             return in;
    return in;
}
std::ostream & operator << (std::ostream & out, const AlcData & a)
{
    out <<a.measure_time<<';'
        <<a.cycle_number<<';'
        <<a.force<<';'
        <<a.dummy1<<';'
        <<a.displacement<<';';
    for (double t: a.temperatures)
        out << t <<';';
    return out<< std::endl;
}
std::istream & operator >> (std::istream & in, AlvData & a)
{
    return in
        >>a.measure_time
        >>a.cycle_number
        >>a.halfcycle_number
        >>a.stress
        >>a.deformation
        >>a.temperature;
}
std::ostream & operator << (std::ostream & out, const AlvData & a)
{
    return out
        <<a.measure_time<<'\t'
        <<a.cycle_number<<'\t'
        <<a.halfcycle_number<<'\t'
        <<a.stress<<'\t'
        <<a.deformation<<'\t'
        <<a.temperature<<std::endl;
}
AlvData::AlvData(const AlcData &a)
{
    measure_time = a.measure_time;
    cycle_number = a.cycle_number;
    halfcycle_number = 2*cycle_number+1;
    stress = a.force*4/(M_PI*d0*d0);
    deformation = a.displacement/l0;
    temperature = max(a.temperatures);
}
