#include"convert.h"
#include<vector>
#include<iostream>
#include<fstream>
#include<limits>
void AlcToAlv(const std::string &alc_name, const std::string & alv_name)
{
    AlcData alc;
    std::vector<AlvData> AlVec;
    std::ifstream fi(alc_name);
    fi.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (!fi.eof() && fi>>alc)
        AlVec.push_back(AlvData(alc));
    std::ofstream fo(alv_name);
    for (const AlvData & t:AlVec)
        fo << t;
}
