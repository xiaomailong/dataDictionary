
#include "Temporary_Speed_Restriction_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Temporary_Speed_Restriction_UpperBitsNotSet(const Temporary_Speed_Restriction* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->NID_TSR,           8)   &&
        UpperBitsNotSet64(p->D_TSR,             15)  &&
        UpperBitsNotSet64(p->L_TSR,             15)  &&
        UpperBitsNotSet64(p->Q_FRONT,           1)   &&
        UpperBitsNotSet64(p->V_TSR,             7))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

