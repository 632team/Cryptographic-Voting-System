#ifndef FHE_SOLVE_H
#define FHE_SOLVE_H
#include "fhe_can.h"
#include <QString>
#include <QDebug>

class FHE_SOLVE{
public:

    const int can_num = 1;
    std::string path;
    std::vector<FHE_CAN> fhe_list;
    FHE_SOLVE(std::string _path):path(_path){
        for(int i = 0; i < can_num; ++i){
            fhe_list.push_back(FHE_CAN(path, i));
        }
    }
    QString Encode(const std::vector<long>& v){

        return fhe_list[0].Encode(v);
    }
    std::vector<long> calSum(const std::vector<QString>& vt){
//        assert(vt.size()>0);
        QString str = fhe_list[0].calSum(vt);
//        assert(str.size()>0);
        std::vector<long> res = fhe_list[0].Decode(str);
        for (int i = 0; i < 3;  ++i){
            qDebug() << i;
        }
        return res;
    }
};

#endif // FHE_SOLVE_H
