/*
 *  libjdksmidi-2004 C++ Class Library for MIDI
 *
 *  Copyright (C) 2004  J.D. Koftinoff Software, Ltd.
 *  www.jdkoftinoff.com
 *  jeffk@jdkoftinoff.com
 *
 *  *** RELEASED UNDER THE GNU GENERAL PUBLIC LICENSE (GPL) April 27, 2004 ***
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
/*
** Copyright 1986 to 1998 By J.D. Koftinoff Software, Ltd.
**
** All rights reserved.
**
** No one may duplicate this source code in any form for any reason
** without the written permission given by J.D. Koftinoff Software, Ltd.
**
*/

#ifndef JDKSMIDI_MATRIX_H
#define JDKSMIDI_MATRIX_H


#include "jdksmidi/midi.h"
#include "jdksmidi/msg.h"

namespace jdksmidi
{

class  MIDIMatrix
{
public:
    MIDIMatrix();
    virtual ~MIDIMatrix();

    virtual bool Process ( const jdksMIDIMessage &m );

    virtual void Clear();

    int GetTotalCount() const
    {
        return total_count;
    }
    int GetChannelCount ( int channel ) const
    {
        return channel_count[channel];
    }

    int GetNoteCount ( int channel, int note ) const
    {
        return note_on_count[channel][note];
    }

    bool GetHoldPedal ( int channel ) const
    {
        return hold_pedal[channel];
    }


protected:
    virtual void DecNoteCount ( const jdksMIDIMessage &m, int channel, int note );
    virtual void IncNoteCount ( const jdksMIDIMessage &m, int channel, int note );
    virtual void ClearChannel ( int channel );
    virtual void OtherMessage ( const jdksMIDIMessage &m );

    void SetNoteCount ( unsigned char chan, unsigned char note, unsigned char val )
    {
        note_on_count[chan][note] = val;
    }
    void SetChannelCount ( unsigned char chan, int val )
    {
        channel_count[chan] = val;
    }

private:
    unsigned char note_on_count[16][128];
    int channel_count[16];
    bool hold_pedal[16];
    int total_count;
};

}


#endif


