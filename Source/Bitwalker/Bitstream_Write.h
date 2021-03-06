
#ifndef BITSTREAM_WRITE_H_INCLUDED
#define BITSTREAM_WRITE_H_INCLUDED

#include "Bitstream.h"

/*@
  requires valid:     Writeable(stream);

  requires invariant: Invariant(stream, length);

  assigns  stream->addr[0..stream->size - 1];
  assigns  stream->bitpos;

  ensures  increment: stream->bitpos == \old(stream->bitpos) + length;

  behavior  normal_case:
    assumes Normal{Pre}(stream, length) && UpperBitsNotSet{Pre}(value, length);

    assigns stream->addr[0..stream->size - 1];
    assigns stream->bitpos;

    ensures left:   EqualBits{Here,Old}(stream, 0, \old(stream->bitpos));

    ensures middle: EqualBits(stream, \old(stream->bitpos), stream->bitpos, value);

    ensures right:  EqualBits{Here,Old}(stream, stream->bitpos, 8 * stream->size);

    ensures result: \result == 0;

  behavior  value_too_big:
    assumes Normal{Pre}(stream, length) && !UpperBitsNotSet{Pre}(value, length);

    assigns stream->addr[0..stream->size - 1];
    assigns stream->bitpos;

    ensures result: \result == -2;

  behavior  invalid_bit_sequence:
    assumes !Normal{Pre}(stream, length);

    assigns stream->addr[0..stream->size - 1];
    assigns stream->bitpos;

    ensures result:  \result == -1;

  complete behaviors;
  disjoint behaviors;
*/
int  Bitstream_Write(Bitstream* stream, uint32_t length, uint64_t value);

#endif // BITSTREAM_WRITE_H_INCLUDED

