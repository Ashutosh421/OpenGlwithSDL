//
//  Time.hpp
//  OpenGLwithSDL
//
//  Created by Ashutosh Rautela on 03/06/17.
//  Copyright © 2017 Ashutosh Rautela. All rights reserved.
//

#ifndef Time_hpp
#define Time_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

class Time {
    
private:
    static float currentTime;
    static float oldTime;
    
public:
    static float deltaTime;
    static float timeSinceLevelLoad;
    static float timeSinceLevelLoadInSecs;
    
    static void UpdateTime();
};

#endif /* Time_hpp */
