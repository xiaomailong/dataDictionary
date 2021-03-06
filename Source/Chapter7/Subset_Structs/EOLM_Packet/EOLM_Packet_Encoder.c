
#include "EOLM_Packet_Encoder.h"
#include "EOLM_Packet_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int EOLM_Packet_Encoder(Bitstream* stream, const EOLM_Packet* p)
{
    if (NormalBitstream(stream, EOLM_PACKET_BITSIZE))
    {
        if (EOLM_Packet_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 25,  14, p->NID_LOOP);
            Bitwalker_Poke_Normal(addr, size, pos + 39,  15, p->D_LOOP);
            Bitwalker_Poke_Normal(addr, size, pos + 54,  15, p->L_LOOP);
            Bitwalker_Poke_Normal(addr, size, pos + 69,  1,  p->Q_LOOPDIR);
            Bitwalker_Poke_Normal(addr, size, pos + 70,  4,  p->Q_SSCODE);

            stream->bitpos += EOLM_PACKET_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
            //@ assert NID_LOOP:          EqualBits(stream, pos + 25,  pos + 39,  p->NID_LOOP);
            //@ assert D_LOOP:            EqualBits(stream, pos + 39,  pos + 54,  p->D_LOOP);
            //@ assert L_LOOP:            EqualBits(stream, pos + 54,  pos + 69,  p->L_LOOP);
            //@ assert Q_LOOPDIR:         EqualBits(stream, pos + 69,  pos + 70,  p->Q_LOOPDIR);
            //@ assert Q_SSCODE:          EqualBits(stream, pos + 70,  pos + 74,  p->Q_SSCODE);

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

