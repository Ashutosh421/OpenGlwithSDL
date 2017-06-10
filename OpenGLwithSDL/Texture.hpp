//
//  Texture.hpp
//  OpenGLwithSDL
//
//  Created by Ashutosh Rautela on 08/06/17.
//  Copyright © 2017 Ashutosh Rautela. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp

#include <stdio.h>
#include <string>
//#include <OpenGL/gl3.h>
#include <GL/glew.h>
#include <iostream>
#include <SDL2_image/SDL_image.h>
#include "stb_image.h"

namespace AR_RenderEngine {
 
    class Texture {
        
    private:
        
        
    public:
        GLuint texture;
        
        Texture(std::string texturePath);
        ~Texture();
        
        void BindTexture(unsigned short textureID);
        void UnBindTexture();
        
    };

}

#endif /* Texture_hpp */
