//
//  lutCurve.cpp
//  moShape
//
//  Created by Ovis aries on 12/09/05.
//
//

#include "lutCurve.h"

lutCurve::lutCurve(){
	table.allocate(LUT_RES, LUT_RES);
}

lutCurve::~lutCurve(){
	
}

void lutCurve::addPoint(float x, float y){
	ofPoint p = ofPoint(x*LUT_RES,y*LUT_RES);
	pts.push_back(p);
}

float lutCurve::getValue(float x){
	int a = lut[(int)floor(x*LUT_RES)];
	int b = lut[(int)floor(x*LUT_RES)+1];
	double nx = x*LUT_RES - floor(x*LUT_RES);
	
	return (a + (b - a)*nx)/(float)LUT_RES;
}

void lutCurve::generate(){
	table.begin();
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	ofNoFill();
	ofBeginShape();
	ofCurveVertex(0, LUT_RES);
	ofCurveVertex(0, LUT_RES);
	for (int i = 0;i < pts.size();i++){
		ofCurveVertex(pts[i]);
	}
	ofCurveVertex(LUT_RES, 0);
	ofCurveVertex(LUT_RES, 0);
	ofEndShape();
	ofFill();
	
	table.end();
	
	ofPixels pix;
	table.readToPixels(pix);
	
	for (int i = 0;i < LUT_RES;i++){
		for(int j = 0;j < LUT_RES;j++){
			if (pix.getColor(i, j).r != 0){
				lut[i] = j;
				j = LUT_RES;
			}
		}
	}
}