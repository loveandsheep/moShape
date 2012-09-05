//
//  simpleEase.h
//  moShape
//
//  Created by Ovis aries on 12/09/05.
//
//
#pragma once
#include "ofMain.h"
#include "lutCurve.h"

#define EASE_IN 0
#define EASE_OUT 1
#define EASE_MIDDLE_DASH 2
#define EASE_MIDDLE_STOP 3

class simpleEase{
public:
	simpleEase();
	~simpleEase();
	void setTempo(int bpm_);
	void setHead();
	float getval(int type,int scale);
	float getRaw(int type,float x);
	
	int bpm;
	int bpm_millisec;
	int tempo_head;
	

	lutCurve lut_ease_in;
	lutCurve lut_ease_out;
	lutCurve lut_middle_dash;
	lutCurve lut_middle_stop;
	
};