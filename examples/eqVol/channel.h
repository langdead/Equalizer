
/* Copyright (c) 2006-2007, Stefan Eilemann <eile@equalizergraphics.com> 
   All rights reserved. */

#ifndef EQ_VOL_CHANNEL_H
#define EQ_VOL_CHANNEL_H

#include "eqVol.h"

#include "rawVolModel.h"

#include <eq/eq.h>

#include "frame.h"


class FrameData;
class InitData;

namespace eqVol
{
    class Channel : public eq::Channel
    {
    public:
		bool _perspective; // perspective/ortogonal projection

    protected:
        virtual ~Channel() {}

        virtual bool configInit( const uint32_t initID );
        virtual void frameDraw( const uint32_t frameID );

		virtual void frameAssemble( const uint32_t frameID );
       	virtual void setupAssemblyState();
        virtual void frameReadback( const uint32_t frameID );

		void arrangeFrames( std::vector<Range>& ranges );

       	void applyFrustum() const;
		
		void clearViewport( const PixelViewport &pvp );
		
		void Channel::frameClear( const uint32_t frameID );


    private:

		void _clearPixelViewPorts( const vector<PixelViewport> &pvpVec );
		
        void _drawLogo();
        void _initFrustum( vmml::FrustumCullerf& frustum );

		//
		struct curFrData
		{
			Range           lastRange;
			bool  			needInverse;
			vmml::Matrix4d  modelviewM;		// modelview matrix
			vmml::Matrix4d  modelviewIM;	// modelview inverse matrix
			vmml::Matrix3d  modelviewITM;	// modelview inversed transposed matrix
			vmml::Frustumf  frustum;		// frustum
		}
		    _curFrData;

		Image _curFrameImage; //!< buffer for readback in case of DB compositing

		
		GLuint _tex1D;
		GLuint _tex3D;
		GLuint _preintName;
		GLuint _vertexID;
		int _slices;
		int _angle;
    };
}



#endif // EQ_VOL_CHANNEL_H

