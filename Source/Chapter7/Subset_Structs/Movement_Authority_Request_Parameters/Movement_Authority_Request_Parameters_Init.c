
#include "Movement_Authority_Request_Parameters_Init.h"

void Movement_Authority_Request_Parameters_Init(Movement_Authority_Request_Parameters* p)
{
    p->NID_PACKET        = 0;
    p->Q_DIR             = 0;
    p->L_PACKET          = 0;
    p->T_MAR             = 0;
    p->T_TIMEOUTRQST     = 0;
    p->T_CYCRQST         = 0;
}

