
#include "RBC_transition_order_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int RBC_transition_order_Decoder(Bitstream* stream, RBC_transition_order* p)
{
    if (NormalBitstream(stream, RBC_TRANSITION_ORDER_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->Q_SCALE            = Bitwalker_Peek_Normal(addr, size, pos + 23,  2);
        p->D_RBCTR            = Bitwalker_Peek_Normal(addr, size, pos + 25,  15);
        p->NID_C              = Bitwalker_Peek_Normal(addr, size, pos + 40,  10);
        p->NID_RBC            = Bitwalker_Peek_Normal(addr, size, pos + 50,  14);
        p->NID_RADIO          = Bitwalker_Peek_Normal(addr, size, pos + 64,  64);
        p->Q_SLEEPSESSION     = Bitwalker_Peek_Normal(addr, size, pos + 128, 1);

        stream->bitpos += RBC_TRANSITION_ORDER_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
        //@ assert D_RBCTR:           EqualBits(stream, pos + 25,  pos + 40,  p->D_RBCTR);
        //@ assert NID_C:             EqualBits(stream, pos + 40,  pos + 50,  p->NID_C);
        //@ assert NID_RBC:           EqualBits(stream, pos + 50,  pos + 64,  p->NID_RBC);
        //@ assert NID_RADIO:         EqualBits(stream, pos + 64,  pos + 128, p->NID_RADIO);
        //@ assert Q_SLEEPSESSION:    EqualBits(stream, pos + 128, pos + 129, p->Q_SLEEPSESSION);

        return 1;
    }
    else
    {
        return 0;
    }
}

