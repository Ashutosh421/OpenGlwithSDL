//
//  Input.cpp
//  OpenGLwithSDL
//
//  Created by Ashutosh Rautela on 03/06/17.
//  Copyright © 2017 Ashutosh Rautela. All rights reserved.
//

#include "Input.hpp"

namespace AR_RenderEngine {
    
    bool keyDown[1024];
    bool keyUp[1024];
    bool keyRepeat[1024];
    SDL_Event m_sdlEvent;
    
    bool Input::GetKeyUp(SDL_Keycode keyCode)
    {
        
        return false;
    }
    
    bool Input::GetKeyDown(SDL_Keycode keyCode)
    {
        
        return false;
    }
    
    bool Input::GetKeyRepeat(SDL_Keycode keyCode)
    {
        
        return false;
    }
    
    void Input::HandleKeyEvent(SDL_Event sdlEvent)
    {
        if (sdlEvent.type == SDL_KEYDOWN) {
            std::cout << "You pressed" << sdlEvent.key.keysym.sym << std::endl;
        }
        if (sdlEvent.type == SDL_KEYUP) {
            std::cout << "You Released " << std::endl;
        }
    }
}

