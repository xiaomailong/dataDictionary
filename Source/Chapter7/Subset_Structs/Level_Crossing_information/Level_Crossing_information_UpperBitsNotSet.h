
#ifndef LEVEL_CROSSING_INFORMATION_UPPERBITSNOTSET_H_INCLUDED
#define LEVEL_CROSSING_INFORMATION_UPPERBITSNOTSET_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Level_Crossing_information_UpperBitsNotSet(const Level_Crossing_information* p);

#endif // LEVEL_CROSSING_INFORMATION_UPPERBITSNOTSET_H_INCLUDED

