#ifndef ACLDATA_H
#define ACLDATA_H
#include<iostream>
struct AlcData
{
    double measure_time;
    int cycle_number;
    double force;
    double dummy1;
    double displacement;
    double temperatures[4];
    friend std::istream & operator >> (std::istream &, AlcData &);
    friend std::ostream & operator << (std::ostream &, const AlcData &);
};

struct AlvData
{
    double measure_time;
    int cycle_number;
    int halfcycle_number;
    double stress;
    double deformation;
    double temperature;
    static constexpr double d0 = 4.37;
    static constexpr double l0 = 12.5;
    AlvData():
        measure_time(0),
        cycle_number(0),
        halfcycle_number(0),
        stress(0),
        deformation(0),
        temperature(0)
    {

    }
    AlvData(const AlcData & alc);
    friend std::istream & operator >> (std::istream &, AlvData &);
    friend std::ostream & operator << (std::ostream &, const AlvData &);
};
#endif // ACLDATA_H
