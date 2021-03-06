
#ifndef STOP_IF_IN_STAFF_RESPONSIBLE_H_INCLUDED
#define STOP_IF_IN_STAFF_RESPONSIBLE_H_INCLUDED

#include "Bitstream.h"

struct Stop_if_in_Staff_Responsible
{
    // TransmissionMedia=Balise
    // Information to stop a train in staff responsible.
    // Packet Number = 137

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SRSTOP;         // # 1
};

typedef struct Stop_if_in_Staff_Responsible Stop_if_in_Staff_Responsible;

#define STOP_IF_IN_STAFF_RESPONSIBLE_BITSIZE 24

/*@
    logic integer BitSize{L}(Stop_if_in_Staff_Responsible* p) = STOP_IF_IN_STAFF_RESPONSIBLE_BITSIZE;

    logic integer MaxBitSize{L}(Stop_if_in_Staff_Responsible* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Stop_if_in_Staff_Responsible* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Stop_if_in_Staff_Responsible* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SRSTOP);

    predicate ZeroInitialized(Stop_if_in_Staff_Responsible* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SRSTOP);

    predicate EqualBits(Bitstream* stream, integer pos, Stop_if_in_Staff_Responsible* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 24,  p->Q_SRSTOP);


    predicate UpperBitsNotSet(Stop_if_in_Staff_Responsible* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SRSTOP,         1);

*/

#endif // STOP_IF_IN_STAFF_RESPONSIBLE_H_INCLUDED

