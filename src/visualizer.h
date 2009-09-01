/***************************************************************************
 *   Copyright (C) 2008-2009 by Andrzej Rybczak                            *
 *   electricityispower@gmail.com                                          *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.              *
 ***************************************************************************/

#ifndef _VISUALIZER_H
#define _VISUALIZER_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#ifdef ENABLE_VISUALIZER

#include "window.h"
#include "screen.h"

#include <fftw3.h>

class Visualizer : public Screen<Window>
{
	public:
		virtual void SwitchTo();
		virtual void Resize();
		
		virtual std::basic_string<my_char_t> Title();
		
		virtual void Update();
		virtual void Scroll(Where, const int *) { }
		
		virtual void EnterPressed() { }
		virtual void SpacePressed();
		virtual void MouseButtonPressed(MEVENT) { }
		
		virtual NCurses::List *GetList() { return 0; }
		
		virtual bool allowsSelection() { return false; }
		
		void SetFD();
		void ResetFD();
		
	protected:
		virtual void Init();
		
	private:
		void DrawSoundWave(int16_t *, ssize_t);
		void DrawFrequencySpectrum(int16_t *, ssize_t);
		
		int itsFifo;
		unsigned *itsFreqsMagnitude;
		double *itsInput;
		fftw_complex *itsOutput;
		fftw_plan itsPlan;
		
		static const unsigned Samples;
		static const unsigned FFTResults;
};

extern Visualizer *myVisualizer;

#endif // ENABLE_VISUALIZER

#endif
