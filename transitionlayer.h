//
//  transitionlayer.h
//  moShape
//
//  Created by Ovis aries on 12/09/05.
//
//

#pragma once
#include "ofMain.h"
#include "simpleEase.h"

class transitionlayer{
public:
	transitionlayer();
	~transitionlayer();
	
	void setTempo(int bpm);
	void setHead();
	void update();
	void addScore(int type,int score);
	
	float pos;
	simpleEase easer;
	vector<int> scores;//ミリ秒を計算しとく
	vector<int> types;
	
	float last_pos;
	float target_pos;
	int score_stack;
	int cur_sc;
	int cur_milli;
	int head_milli;
};