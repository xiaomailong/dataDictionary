
#ifndef PeekNext_included
#define PeekNext_included

#include "Locals.h"
#include "ValidIncrementalLocals.h"
#include "Bitwalker.h"

/*@
  requires \valid(Locals);
  requires Valid(Locals);
  requires 0 <= Length <= 64;
  requires Locals->CurrentBitposition + Length <= UINT_MAX;

  assigns  Locals->CurrentBitposition;

  ensures \old(Locals->CurrentBitposition) + Length == Locals->CurrentBitposition;

  behavior  invalid_bit_sequence:
    assumes (Locals->CurrentBitposition + Length)  > 8 * Locals->Length;
    assigns  Locals->CurrentBitposition;

    ensures \result == 0;

  behavior  normal_case:
    assumes (Locals->CurrentBitposition + Length) <= 8 * Locals->Length;
    assigns  Locals->CurrentBitposition;

    ensures \forall integer i; 0 <= i < Length ==>
    		(LeftBitInStream(\old(Locals->Bitstream), \old(Locals->CurrentBitposition)+i) <==> LeftBit64(\result, 64-Length + i));

    ensures \forall integer i; 0 <= i < 64-Length ==> !LeftBit64(\result, i);

  complete behaviors;
  disjoint behaviors;
*/
uint64_t Bitwalker_IncrementalWalker_Peek_Next(
  T_Bitwalker_Incremental_Locals*  Locals,
  unsigned int                     Length);

#endif

