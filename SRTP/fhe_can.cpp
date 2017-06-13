#include "fhe_can.h"
#include <QDebug>

const long p=17, r=1; // Native plaintext space
                    // Computations will be 'modulo p'
const long L=16;          // Levels
const long c=3;           // Columns in key switching matrix
const long w=64;          // Hamming weight of secret key
const long d=0;
const long security = 128;
//long m = FindM(security,L,c,p, d, 0, 0);
//FHEcontext context(m, p, r);
long  m = FindM(security,L,c,p, d, 0, 0);
#include <QDataStream>
QString StdStringConvertQString(const std::string& str){
    int sz = str.size();
    QString s;
    s.resize(sz);;
    for(int i = 0; i < sz; ++i){
        s[i] = ((int)str[i])+128;
    }
    return s;
}

std::string QStringConvertStdString(const QString& qstr){
        int sz = qstr.size();
        std::string s;
        s.resize(sz);
        for(int i = 0; i < sz; ++i){
            s[i] = char(((int)(qstr[i].cell()))-128);
        }
        return s;
}
long getmm(){
    return m = FindM(security,L,c,p, d, 0, 0);
}

FHEcontext& getContext(FHEcontext& context){
    buildModChain(context, L, c);
    return context;
}
FHE_CAN::FHE_CAN(std::string _path, int num) : _contexty(getmm(), p, r), _secretKey(getContext(_contexty)),
    _publicKey(_secretKey), path(_path){
    sec_path = path + "sec_can_" + to_string(num) + ".txt";
    pub_path = path + "pub_can_" + to_string(num) + ".txt";
    if(file_exist(sec_path) && file_exist(pub_path)){
        return;
    }
    G = _contexty.alMod.getFactorsOverZZ()[0];
    _secretKey.GenSecKey(w);
    writePubKey(_publicKey, _contexty, pub_path);
    writeSecKey(_secretKey, _contexty, sec_path);
}

//std::string FHE_CAN::getSecPath(int i){
//    std::string sec_p = path + "user_"+to_string(i) + "_sec.txt";
//    return sec_p;
//}
//std::string FHE_CAN::getPubPath(int i){
//    std::string pub_p = path + "user_"+to_string(i) + "_pub.txt";
//    return pub_p;
//}
void FHE_CAN::writeSecKey(const FHESecKey& new_secretKey, const FHEcontext& context, const std::string& path){
    fstream out_sec(path, fstream::out|fstream::trunc);
    writeContextBase(out_sec, context);
    out_sec << context   << endl;
    out_sec << new_secretKey << endl;
    out_sec.close();
}

void FHE_CAN::writePubKey(const FHEPubKey& new_publicKey, const FHEcontext& context, const std::string& path){
    fstream out_pub(path, fstream::out|fstream::trunc);
    writeContextBase(out_pub, context);
    out_pub << context << endl;
    out_pub << new_publicKey << endl;
    out_pub.close();
}


//std::string&& FHE_CAN::ReadCipherText(const std::string& path){
//    fstream in(path, fstream::in);
//    stringstream ss;
//    ss << in.rdbuf();
//    std::string str(ss.str());
//    return std::move(str);
//}


std::vector<long> FHE_CAN::Decode(const QString& ciphertext){
    fstream keyFile(sec_path, fstream::in);
    std::vector<long> res;
    if(!keyFile.is_open()){
        assert(0);
        return res;
    }
    unsigned long m1, p1, r1;
    std::vector<long> gens, ords;
    readContextBase(keyFile, m1, p1, r1, gens, ords);
//    cout << "m1 = " << m1 << " p1 = " << p1 << " r1 = " << r1 << endl;
    FHEcontext context(m1, p1, r1, gens, ords);
    keyFile >> context;
    FHESecKey sec_key(context);
    keyFile >> sec_key;
    keyFile.close();
    EncryptedArray ea(context);
    const FHEPubKey& publicKey = sec_key;
    Ctxt ct1(publicKey);
    std::string str(QStringConvertStdString(ciphertext));
    stringstream ss(str);
    ss >> ct1;
    ea.decrypt(ct1, sec_key, res);
    return res;
}


QString FHE_CAN::calSum(const std::vector<QString>& vt){
    fstream keyFile(pub_path, fstream::in);
    if(!keyFile.is_open()){
        assert(0);
        return nullptr;
    }
    unsigned long m1, p1, r1;
    std::vector<long> gens, ords;
    readContextBase(keyFile, m1, p1, r1, gens, ords);
    FHEcontext context(m1, p1, r1, gens, ords);
    keyFile >> context;
    FHEPubKey pub_key(context);
    keyFile >> pub_key;
    keyFile.close();
    EncryptedArray ea(context, context.alMod.getFactorsOverZZ()[0]);
    long nslots = ea.size();
    assert(nslots>0);
    Ctxt ct0(pub_key);
    std::string tmp = QStringConvertStdString(vt[0]);
    int a=0;
    for(int i = 0; i < tmp.size(); ++i){
        if(tmp[i]<0) a = 1;
    }
    qDebug() << "tmp fushu" <<a;
    stringstream ss(tmp);
    ss >> ct0;
    qDebug() << "ss >> ct0 is ok";
    qDebug() << vt.size();
    qDebug() << "vt.size = " << vt.size();
    Ctxt Csum = ct0;

    for(int i = 1; i < vt.size(); ++i){
        Ctxt ct(pub_key);
        stringstream ss(QStringConvertStdString(vt[i]));
        ss >> ct;
        Csum += ct;
    }

    stringstream sss;
    sss << Csum << endl;
    std::string str(sss.str());
    return StdStringConvertQString(str);

}

//std::vector<long> FHE_CAN::Decode(const QString& ciphertext, const std::string& sec_path){
//    fstream keyFile(sec_path, fstream::in);
//    std::vector<long> res;
//    if(!keyFile.is_open()){
//        cerr << "there is no file" << endl;
//        return res;
//    }
//    unsigned long m1, p1, r1;
//    std::vector<long> gens, ords;
//    readContextBase(keyFile, m1, p1, r1, gens, ords);
//    FHEcontext context(m1, p1, r1, gens, ords);
//    keyFile >> context;
//    FHESecKey sec_key(context);
//    keyFile >> sec_key;
//    keyFile.close();
//    EncryptedArray ea(context);
//    const FHEPubKey& publicKey = sec_key;
//    Ctxt ct1(publicKey);
//    std::string str(QStringConvertStdString(ciphertext));
//    stringstream ss(str);
//    ss >> ct1;
//    ea.decrypt(ct1, sec_key, res);
//    return res;
//}
//FHEcontext FHE_CAN::ReadContext(const std::string& path){
//    fstream keyFile(pub_path, fstream::in);
//    unsigned long m1, p1, r1;
//    std::vector<long> gens, ords;
//    readContextBase(keyFile, m1, p1, r1, gens, ords);
//    FHEcontext context(m1, p1, r1, gens, ords);
//    keyFile >> context;
//    keyFile.close();
//    return context;

//}

//FHEPubKey* FHE_CAN::ReadPubKey(const std::string& pub_path){
//    fstream keyFile(pub_path, fstream::in);
//    unsigned long m1, p1, r1;
//    std::vector<long> gens, ords;
//    readContextBase(keyFile, m1, p1, r1, gens, ords);
//    FHEcontext context(m1, p1, r1, gens, ords);
//    keyFile >> context;
//    FHEPubKey *pub = new FHEPubKey(context);
//    keyFile >> *pub;
//    keyFile.close();
//    return pub;
//}
//FHESecKey* FHE_CAN::ReadSecKey(const std::string& sec_path){
//    fstream keyFile(sec_path, fstream::in);
//    unsigned long m1, p1, r1;
//    std::vector<long> gens, ords;
//    readContextBase(keyFile, m1, p1, r1, gens, ords);
//    FHEcontext context(m1, p1, r1, gens, ords);
//    keyFile >> context;
//    FHESecKey *sec = new FHESecKey(context);
//    keyFile >> *sec;
//    keyFile.close();
//    return sec;
//}
QString FHE_CAN::Encode(const std::vector<long>& v){
    fstream keyFile(pub_path, fstream::in);
    if(!keyFile.is_open()){
        cerr << "there is no file" << endl;
        return nullptr;
    }
    unsigned long m1, p1, r1;
    std::vector<long> gens, ords;
    readContextBase(keyFile, m1, p1, r1, gens, ords);
    FHEcontext context(m1, p1, r1, gens, ords);
    keyFile >> context;
    FHEPubKey pub_key(context);
    keyFile >> pub_key;
    keyFile.close();
    EncryptedArray ea(context);
    long nslots = ea.size();
    if(v.size() > nslots){
        cerr << "encode std::vector exceeds limit" << endl;
        return nullptr;
    }
    std::vector<long> v1;

    for(int i = 0; i < v.size(); ++i){
        v1.push_back(v[i]);
    }
    for(int i = v.size(); i < nslots; ++i){
        v1.push_back(i);
    }
    Ctxt ct1(pub_key);
    ea.encrypt(ct1, pub_key, v1);
    stringstream ss;
    ss << ct1 << endl;
    std::string str(ss.str());
    return StdStringConvertQString(str);
}

//QString FHE_CAN::Encode(const std::vector<long>& v, const std::string& pub_path){
//    fstream keyFile(pub_path, fstream::in);
//    if(!keyFile.is_open()){
//        cerr << "there is no file" << endl;
//        return nullptr;
//    }
//    unsigned long m1, p1, r1;
//    std::vector<long> gens, ords;
//    readContextBase(keyFile, m1, p1, r1, gens, ords);
//    FHEcontext context(m1, p1, r1, gens, ords);
//    keyFile >> context;
//    FHEPubKey pub_key(context);
//    keyFile >> pub_key;
//    keyFile.close();
//    EncryptedArray ea(context, context.alMod.getFactorsOverZZ()[0]);
//    long nslots = ea.size();
//    if(v.size() > nslots){
//        cerr << "encode std::vector exceeds limit" << endl;
//        return nullptr;
//    }
//    std::vector<long> v1;

//    for(int i = 0; i < v.size(); ++i){
//        v1.push_back(v[i]);
//    }
//    for(int i = v.size(); i < nslots; ++i){
//        v1.push_back(i);
//    }
//    Ctxt ct1(pub_key);
//    ea.encrypt(ct1, pub_key, v1);
//    fstream out;
//    out << ct1 << endl;
//    stringstream ss;
//    ss << ct1 << endl;
//    std::string str(ss.str());
//    return StdStringConvertQString(str);
//}
//std::string&& FHE_CAN::Ctxt2str(const Ctxt& ct1, const FHEPubKey& pub_key){
//    fstream out;
//    out << ct1 << endl;
//    stringstream ss;
//    ss << ct1 << endl;
//    std::string str(ss.str());
//    return std::move(str);
//}

//Ctxt FHE_CAN::str2Ctxt(const std::string& str, const FHEPubKey& pub_key){
//    Ctxt ct1(pub_key);
//    stringstream ss(str);
//    ss >> ct1;
//    ct1;
//}
bool FHE_CAN::file_exist(std::string path){
     fstream _file;
     _file.open(path,ios::in);
     if(!_file) return false;
     return true;
}
//std::vector<long> FHE_CAN::getTestVector(int siz){
//    std::vector<long> res;
//    for(int i = 0; i < siz; ++i){
//        res.push_back(i);
//    }
//    return res;
//}

//void FHE_CAN::print(const std::vector<long> res){
//    for(int i = 0; i < res.size(); ++i){
//        cout << " i = " << i << " res[i] = " << res[i] << endl;
//    }
//    cout << "res size = " << res.size() << endl;
//}
