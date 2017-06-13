#include "signaturesystem.h"
#include "registercenter.h"

#include <QSqlQuery>
#include "dao.h"
#include "voterhelp.h"

QString SignatureSystem::R_idv;
QString SignatureSystem::R_nv;
QString SignatureSystem::V_idv;
QString SignatureSystem::V_mvX;
QString SignatureSystem::V_SIGrNv;
QString SignatureSystem::mv;

SignatureSystem::SignatureSystem()
{

}

QString SignatureSystem::getNvFromRegisterCenter()
{
    R_nv = RegisterCenter::getNv();
    return R_nv;
}

QString SignatureSystem::getIdvFromRegisterCentger()
{
    R_idv = RegisterCenter::getIdv();
    return R_idv;
}

bool SignatureSystem::judgeWhetherExitInSigTable(const QString &idv)
{
    QString sql = "select * from signature_system_valid_list where idv = '" + idv + "'";
    QSqlQuery resultSet = Dao::findForResultSet(sql);
    if (resultSet.next()){
        if (resultSet.size() <= 0){
            return false;
        }
    }
    return true;
}

QString SignatureSystem::getMvXFromVoter()
{
    return VoterHelp::V_MvX;
}

QString SignatureSystem::getSIGrNvFromVoter()
{
    return VoterHelp::SIGr_Nv;
}

QString SignatureSystem::getIdvFromVoter()
{
    return RegisterCenter::getIdv();
}

bool SignatureSystem::decodeMvX()
{

}

QString SignatureSystem::signatureMv()
{

}

void SignatureSystem::registerInfoToSigTable()
{
//    QString sql = "INSERT INTO `voter_information`(`voter_id`, `voter_name`, `voter_age`, `voter_sex`, `voter_ic`, "
//                  "`voter_password`, `voter_public_key`, `Hv`, `SNv`, `av`) VALUES (NULL,'" + voter.name +"',"
//            + QString::number(voter.age, 10) + ",'" + voter.sex + "','" + voter.id + "','" + voter.password + "','1', '1', '1', NULL)";
    QString sql = "INSERT INTO `signature_system_registered_list`(`IDv`, `SNv`, `Mv*`, `Gv`) VALUES ('"
            "[value-1],[value-2],[value-3],[value-4])";
    Dao::insertInfo(sql);
    return ;
}


