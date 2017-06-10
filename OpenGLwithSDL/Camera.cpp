//
//  Camera.cpp
//  OpenGLwithSDL
//
//  Created by Ashutosh Rautela on 03/06/17.
//  Copyright © 2017 Ashutosh Rautela. All rights reserved.
//

#include "Camera.hpp"

namespace AR_RenderEngine {
    
    Camera::Camera(int SCREEN_WIDTH, int SCREEN_HEIGHT){
        this->SCREEN_WIDTH = SCREEN_WIDTH;
        this->SCREEN_HEIGHT = SCREEN_HEIGHT;
        
        position = glm::vec3( 0 , 0 , 0 );
        cameraFront = glm::vec3( 0 , 0 , -1 );
        cameraUp = glm::vec3( 0 , 1 , 0 );
    }
    
    Camera::~Camera(){
    
    }
    
    glm::mat4 Camera::GetViewMat4f(){
        glm::mat4 viewMatrix;
        
        viewMatrix = glm::lookAt(position, position + cameraFront, cameraUp);
        
        return viewMatrix;
    }
    
    glm::mat4 Camera::GetProjectionMat4f(){
        glm::mat4 projectionMatrix;
        
        projectionMatrix = glm::perspective(20.0f, (float)SCREEN_WIDTH/SCREEN_HEIGHT, 0.1f, 1000.0f);
        
        return projectionMatrix;
    }
}
