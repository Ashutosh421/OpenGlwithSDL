//
//  Time.cpp
//  OpenGLwithSDL
//
//  Created by Ashutosh Rautela on 03/06/17.
//  Copyright © 2017 Ashutosh Rautela. All rights reserved.
//

#include "Time.hpp"

float Time::deltaTime = 0;
float Time::currentTime = 0;
float Time::oldTime = 0;
float Time::timeSinceLevelLoad = 0;
float Time::timeSinceLevelLoadInSecs = 0;

void Time::UpdateTime(){
    timeSinceLevelLoad = SDL_GetTicks();
    timeSinceLevelLoadInSecs = timeSinceLevelLoad/1000;
    
    
    currentTime = SDL_GetTicks();
    deltaTime = (currentTime - oldTime)/1000;
    oldTime = currentTime;
}
