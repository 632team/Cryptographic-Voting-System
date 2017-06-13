#ifndef VOTERHELP_H
#define VOTERHELP_H
#include <QApplication>
#include <vector>
#include "fhe_solve.h"

class VoterHelp
{
public:
    VoterHelp();
    static void getEncrypedNvFromRegisterCenter();
    static QString getFheEncrypedVector();
    static QString getMvXinVoter();
    static QString getMvX();
    static QString encodeWithRSA(const QString& enString, const QString& systemName);
    static QString decodeWithRSA(const QString& plainString, const QString& systemName);
public:
    static QString R_Nv;
    static QString FUE_publicKey;
    static QString S_Gv;
    static std::vector<uint64_t> voteContent;
    static QString R_MACv;
    static QString SIGr_Nv;
    static QString Ec_MvX;
    static QString Ec_Gv;
    static QString Av;
    static QString V_Mv;
    static QString V_MvX;
    static FHE_SOLVE fhe_solve;//{"/home/mrsiz/SRTP/"};
    static QString temp_Mv;
    static QString idv;
};

#endif // VOTERHELP_H
