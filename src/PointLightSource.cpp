/*
 * PointLightSource.cpp
 *
 * */

#include "PointLightSource.hpp"


PointLightSource::PointLightSource(GLenum num) : LightSource(num){

}

PointLightSource::~PointLightSource(){

}


void PointLightSource::draw(){
	LightSource::draw();
	if(_state){
	}
}
