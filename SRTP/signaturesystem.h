#ifndef SIGNATURESYSTEM_H
#define SIGNATURESYSTEM_H

#include <QApplication>

class SignatureSystem
{
public:
    SignatureSystem();
    static SignatureSystem getInstance(){
        static SignatureSystem instance = SignatureSystem();
        return instance;
    }

public:
    static QString getNvFromRegisterCenter();
    static QString getIdvFromRegisterCentger();
    static bool judgeWhetherExitInSigTable(const QString& idv);

    static QString getMvXFromVoter();
    static QString getSIGrNvFromVoter();
    static QString getIdvFromVoter();
    static bool decodeMvX();
    static QString signatureMv();
    static void registerInfoToSigTable();
private:
    static QString R_idv;
    static QString R_nv;
    static QString V_idv;
    static QString V_mvX;
    static QString V_SIGrNv;
    static QString mv;
};

#endif // SIGNATURESYSTEM_H
