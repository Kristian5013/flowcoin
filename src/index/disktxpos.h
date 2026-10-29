// Copyright (c) Kristian Pilatovich.
// See COPYING for license.

#ifndef FLOWCOIN_INDEX_DISKTXPOS_H
#define FLOWCOIN_INDEX_DISKTXPOS_H

#include <flatfile.h>
#include <serialize.h>

struct CDiskTxPos : public FlatFilePos
{
    uint32_t nTxOffset{0}; // after header

    SERIALIZE_METHODS(CDiskTxPos, obj)
    {
        READWRITE(AsBase<FlatFilePos>(obj), VARINT(obj.nTxOffset));
    }

    CDiskTxPos(const FlatFilePos& blockIn, uint32_t nTxOffsetIn) : FlatFilePos{blockIn.nFile, blockIn.nPos}, nTxOffset{nTxOffsetIn} {
    }

    CDiskTxPos() = default;
};

#endif // FLOWCOIN_INDEX_DISKTXPOS_H