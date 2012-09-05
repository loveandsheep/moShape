//
//  lutCurve.h
//  moShape
//
//  Created by Ovis aries on 12/09/05.
//
//
#pragma once
#include "ofMain.h"
#define LUT_RES 300

class lutCurve{
public:
	lutCurve();
	~lutCurve();
	
	void	addPoint(float x,float y);
	float	getValue(float x);
	void	generate();
	
	vector <ofPoint> pts;
	ofFbo table;
	int lut[LUT_RES];
};