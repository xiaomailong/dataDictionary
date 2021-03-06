
#include "Stop_Shunting_on_desk_opening_Encoder.h"
#include "Stop_Shunting_on_desk_opening_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Stop_Shunting_on_desk_opening_Encoder(Bitstream* stream, const Stop_Shunting_on_desk_opening* p)
{
    if (NormalBitstream(stream, STOP_SHUNTING_ON_DESK_OPENING_BITSIZE))
    {
        if (Stop_Shunting_on_desk_opening_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);

            stream->bitpos += STOP_SHUNTING_ON_DESK_OPENING_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);

            return 1;
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
}

