
/* Copyright (c) 2006-2007, Stefan Eilemann <eile@equalizergraphics.com> 
   All rights reserved. */

#ifndef EQ_VOL_CONFIG_H
#define EQ_VOL_CONFIG_H

#include <eq/eq.h>

#include "localInitData.h" // member
#include "frameData.h"     // member

namespace eVolve
{
    class Config : public eq::Config
    {
    public:
        Config();

        /** @sa eq::Config::init. */
        virtual bool init();
        /** @sa eq::Config::exit. */
        virtual bool exit();

        /** @sa eq::Config::startFrame. */
        virtual uint32_t startFrame();

        void setInitData( const LocalInitData& data ) { _initData = data; }

    protected:
        virtual ~Config();

        /** @sa eq::Config::handleEvent */
        virtual bool handleEvent( const eq::ConfigEvent* event );

        int        _spinX, _spinY;

        LocalInitData _initData;
        FrameData     _frameData;

    private:
        static void _applyRotation( float m[16], const float dx, const float dy );
    };
}

#endif // EQ_VOL_CONFIG_H
