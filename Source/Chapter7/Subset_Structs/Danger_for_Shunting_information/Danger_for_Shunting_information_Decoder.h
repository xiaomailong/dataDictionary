
#ifndef DANGER_FOR_SHUNTING_INFORMATION_DECODER_H_INCLUDED
#define DANGER_FOR_SHUNTING_INFORMATION_DECODER_H_INCLUDED

#include "Danger_for_Shunting_information.h"

/*@
    requires valid_stream:      Readable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:          EqualBits{Here,Old}(stream, 0, 8*stream->size);

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p));

      assigns stream->bitpos;
      assigns *p;

      ensures invariant:  Invariant(p);
      ensures result:     \result == 1; 
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures equal:      EqualBits(stream, \old(stream->bitpos), p);
      ensures upper:      UpperBitsNotSet(p);

    behavior error_case:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result: \result == 0;

    complete behaviors;
    disjoint behaviors;
*/
int Danger_for_Shunting_information_Decoder(Bitstream* stream, Danger_for_Shunting_information* p);


#endif // DANGER_FOR_SHUNTING_INFORMATION_DECODER_H_INCLUDED

