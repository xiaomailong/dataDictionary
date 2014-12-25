
#ifndef BITSTREAMINVARIANT_H_INCLUDED
#define BITSTREAMINVARIANT_H_INCLUDED

#include "Bitstream.h"

/*@
  predicate BitstreamInvariant{L}(Bitstream* stream) =
     \valid(stream->addr + (0..stream->size-1))  &&
     \separated(stream, stream->addr + (0..stream->size-1)) &&
     8 * stream->size <= UINT32_MAX;

  predicate NormalBitsequence{L}(Bitstream* stream, integer length) =
     stream->bitpos + length <= 8 * stream->size;

  predicate LeftBitInStream{L}(Bitstream* stream, integer i) = \at(LeftBit8Array(stream->addr, i),L);

  predicate BitstreamUnchanged{A,B}(Bitstream* stream, integer first, integer last) =
    \forall integer i; first <= i < last ==>
      (LeftBitInStream{A}(stream, i) <==> LeftBitInStream{B}(stream, i));

  predicate BitstreamEqual64{L}(Bitstream* stream , 
             integer first, integer last, uint64_t value) =
                EqualBits64(stream->addr, first, last, value);

*/

#endif // BITSTREAMINVARIANT_H_INCLUDED

