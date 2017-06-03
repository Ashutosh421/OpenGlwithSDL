//
//  Camera.hpp
//  OpenGLwithSDL
//
//  Created by Ashutosh Rautela on 03/06/17.
//  Copyright © 2017 Ashutosh Rautela. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace AR_RenderEngine {
 
    class Camera {
        
    private:
        int SCREEN_WIDTH;
        int SCREEN_HEIGHT;
        
    public:
        Camera();
        Camera(int , int);
        ~Camera();
        glm::vec3 position;
        
        glm::mat4 GetViewMat4f();
        glm::mat4 GetProjectionMat4f();
    };

}

#endif /* Camera_hpp */
