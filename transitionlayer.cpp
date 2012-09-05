//
//  transitionlayer.cpp
//  moShape
//
//  Created by Ovis aries on 12/09/05.
//
//

#include "transitionlayer.h"

transitionlayer::transitionlayer(){
	pos = 0.0;
	last_pos = 0.0;
	target_pos = ofRandom(1.0);
	cur_sc = 0;
	cur_milli = ofGetElapsedTimeMillis();

}

transitionlayer::~transitionlayer(){
	
}

void transitionlayer::setTempo(int bpm){
	easer.setTempo(bpm);
}

void transitionlayer::setHead(){
	cur_sc = 0;
	score_stack = 0;
	head_milli = ofGetElapsedTimeMillis();
	cur_milli = ofGetElapsedTimeMillis();
}

void transitionlayer::update(){
	if (scores.size() < 1) return;
	
	float pct = (ofGetElapsedTimeMillis() - cur_milli) / ((float)scores[cur_sc]*easer.bpm_millisec/16.0);
	if (pct < 0){
		pct = 0;
		cur_milli = ofGetElapsedTimeMillis();
	}

	if (pct >= 0.9999){
		score_stack += scores[cur_sc];
		cur_milli = head_milli+score_stack*easer.bpm_millisec/16.0;
		cur_sc = (cur_sc + 1)%scores.size();
		last_pos = target_pos;
		pos = target_pos;
		target_pos = ofRandom(1.0);

	}else{
		pos = last_pos + (target_pos - last_pos) * easer.getRaw(types[cur_sc], pct);
	}
	
}

void transitionlayer::addScore(int type, int score){
	int s = score;
	int t = type;
	scores.push_back(s);
	types.push_back(t);
}

bool transitionlayer::getTrigger(){
	if (lastScore != cur_sc){
		lastScore = cur_sc;
		return true;
	}else{
		return false;
	}
}

void transitionlayer::setRandomScore(){
	scores.clear();
	types.clear();
	int total = 0;
	while(total != 16){
		if (total < 16){
			int s = pow(2.0,(int)ofRandom(1,3));
			int t = 1;//ofRandom(2);
			scores.push_back(s);
			types.push_back(t);
		}else if (total > 16){
			scores.pop_back();
			types.pop_back();
			int s = pow(2.0,(int)ofRandom(1,3));
			int t = 1;
			scores.push_back(s);
			types.push_back(t);
		}
		total = 0;
		for (int i = 0;i < scores.size();i++){
			total += scores[i];
		}
	}
}

void transitionlayer::clearScore(){
	scores.clear();
	types.clear();
}