
#include "Bitstream_Write.h"
#include "Bitstream_Write_Normal.h"
#include "UpperBitsNotSet.h"

int Bitstream_Write(Bitstream* stream, uint32_t length, uint64_t value)
{
    if (NormalBitstream(stream, length))
    {
        if (UpperBitsNotSet64(value, length))
        {
            Bitstream_Write_Normal(stream, length, value);
            stream->bitpos += length;
            return 0;
        }
        else
        {
            stream->bitpos += length;
            return -2;
        }
    }
    else
    {
        stream->bitpos += length;
        return -1;
    }
}

