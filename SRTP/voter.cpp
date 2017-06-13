#include "voter.h"

Voter::Voter()
{

}

bool Voter::isOk()
{
    if (id.isEmpty() || name.isEmpty() || sex.isEmpty() || password.isEmpty())
         return false;
    if (age <= 0 || age > 150)
        return false;
    return true;
}
