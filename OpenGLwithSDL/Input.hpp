//
//  Input.hpp
//  OpenGLwithSDL
//
//  Created by Ashutosh Rautela on 03/06/17.
//  Copyright © 2017 Ashutosh Rautela. All rights reserved.
//

#ifndef Input_hpp
#define Input_hpp

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>


namespace AR_RenderEngine {
    class Input {
        
    private:
        static bool keyDown[1024];
        static bool keyRepeat[1024];
        static bool keyUp[1024];
        static SDL_Event m_sdlEvent;
    public:
        static void HandleKeyEvent(SDL_Event sdlEvent);
        
        static bool GetKeyDown(SDL_Keycode);
        static bool GetKeyRepeat(SDL_Keycode);
        static bool GetKeyUp(SDL_Keycode);
    };
}


#endif /* Input_hpp */
