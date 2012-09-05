//
//  simpleEase.cpp
//  moShape
//
//  Created by Ovis aries on 12/09/05.
//
//

#include "simpleEase.h"

simpleEase::simpleEase(){
	lut_ease_in.addPoint(0.60,0.80);
	lut_ease_out.addPoint(0.40,0.20);
	
	lut_middle_dash.addPoint(0.4, 0.8);
	lut_middle_dash.addPoint(0.6, 0.2);
	
	lut_middle_stop.addPoint(0.2, 0.55);
	lut_middle_stop.addPoint(0.8, 0.45);

	lut_ease_in.generate();
	lut_ease_out.generate();
	lut_middle_dash.generate();
	lut_middle_stop.generate();
}

simpleEase::~simpleEase(){
	
}

void simpleEase::setTempo(int bpm_){
	tempo_head = ofGetElapsedTimeMillis();
	bpm = bpm_;
	bpm_millisec = 60000 / (float)bpm*4.0;
}

void simpleEase::setHead(){
	tempo_head = ofGetElapsedTimeMillis();
}

float simpleEase::getRaw(int type,float x){
	lutCurve* lt;
	
	switch (type) {
		case EASE_IN:
			lt = &lut_ease_in;
			break;
		case EASE_OUT:
			lt = &lut_ease_out;
			break;
		case EASE_MIDDLE_DASH:
			lt = &lut_middle_dash;
			break;
		case EASE_MIDDLE_STOP:
			lt = &lut_middle_stop;
			break;
			
		default:
			break;
	}
	
	return MIN(1,MAX(0,1 - lt->getValue(MIN(1,MAX(0,x)))));
}

float simpleEase::getval(int type, int scale){
	float pct = ((ofGetElapsedTimeMillis()-tempo_head) % bpm_millisec) / (float)bpm_millisec*16.0/(float)scale;
	pct = pct - floor(pct);
	lutCurve* lt;
	
	switch (type) {
		case EASE_IN:
			lt = &lut_ease_in;
			break;
		case EASE_OUT:
			lt = &lut_ease_out;
			break;
		case EASE_MIDDLE_DASH:
			lt = &lut_middle_dash;
			break;
		case EASE_MIDDLE_STOP:
			lt = &lut_middle_stop;
			break;
			
		default:
			break;
	}

	return MIN(1,MAX(0,1 - lt->getValue(MIN(1,MAX(0,pct)))));
}