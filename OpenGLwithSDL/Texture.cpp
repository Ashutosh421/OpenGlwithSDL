//
//  Texture.cpp
//  OpenGLwithSDL
//
//  Created by Ashutosh Rautela on 08/06/17.
//  Copyright © 2017 Ashutosh Rautela. All rights reserved.
//

#include "Texture.hpp"

namespace AR_RenderEngine {
    
    Texture::Texture(std::string filePath)
    {
        glEnable(GL_TEXTURE_2D);
        short initFlags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
        short initIMG = IMG_Init(initFlags);
        
        if ((initIMG & initFlags) != initFlags) {
            std::cout << "Couldn't initialize IMG_Init " << IMG_GetError() << std::endl;
            return;
        }
        std::string textFile = filePath;
        
        SDL_Surface* imageSurface = IMG_Load(textFile.c_str());
        if (imageSurface == NULL) {
            std::cout << "Couldn't load the Image Surface " << IMG_GetError() << std::endl;
            return;
        }
        
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageSurface->w, imageSurface->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, imageSurface->pixels);
        glGenerateMipmap(GL_TEXTURE_2D);
        
        SDL_FreeSurface(imageSurface);
    }
    
    void Texture::BindTexture(unsigned short textureID)
    {
        glActiveTexture(0);
        glBindTexture(GL_TEXTURE_2D, texture);
    }
    
    void Texture::UnBindTexture()
    {
        glBindTexture(GL_TEXTURE_2D, texture);
    }
    
    Texture::~Texture()
    {
        glDeleteTextures(1, &texture);
        IMG_Quit();
    }
    
}
