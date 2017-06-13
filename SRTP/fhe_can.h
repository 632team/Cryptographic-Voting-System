#ifndef FHE_CAN_H
#define FHE_CAN_H




#include "FHE.h"
#include "EncryptedArray.h"
#include <NTL/lzz_pXFactoring.h>
#include <fstream>
#include <sstream>
#include <sys/time.h>
#include <fstream>
#include <unistd.h>

#include <NTL/ZZX.h>
#include <NTL/vector.h>
#include <fstream>
#include <unistd.h>

#include <NTL/ZZX.h>
#include <NTL/vector.h>

#include "FHE.h"
#include "timing.h"
#include "EncryptedArray.h"
#include "FHE.h"
#include "timing.h"
#include "EncryptedArray.h"
#include <string>
#include <cstring>
#include <QString>




QString StdStringConvertQString(const std::string& str);
std::string QStringConvertStdString(const QString& qstr);

class FHE_CAN{
public:

    FHEcontext _contexty;
    FHESecKey _secretKey;
    const FHEPubKey& _publicKey;
    ZZX G;
    std::string path;
    std::string sec_path;
    std::string pub_path;
    FHE_CAN(std::string _path, int num) ;
//    std::string getSecPath(int i);
//    std::string getPubPath(int i);
    bool file_exist(std::string path);
    void writeSecKey(const FHESecKey& new_secretKey, const FHEcontext& context, const std::string& path);
    void writePubKey(const FHEPubKey& new_publicKey, const FHEcontext& context, const std::string& path);
//    std::vector<long> Decode(const QString& ciphertext, const std::string& sec_path);
//    std::vector<long> Decode(const Ctxt& ct1);
    std::vector<long> Decode(const QString& ciphertext);
    QString Encode(const std::vector<long>& v);
//    QString Encode(const std::vector<long>& v, const std::string& pub_path);
    QString calSum(const std::vector<QString>& vt);
//    std::string&& Ctxt2str(const Ctxt& ct1, const FHEPubKey& pub_key);
//    Ctxt str2Ctxt(const std::string& str, const FHEPubKey& pub_key);
//    std::vector<long> getTestVector(int siz);
//    void print(const std::vector<long> res);
};

#endif // FHE_CAN_H
