//
//  Transform.hpp
//  OpenGLwithSDL
//
//  Created by Ashutosh Rautela on 03/06/17.
//  Copyright © 2017 Ashutosh Rautela. All rights reserved.
//

#ifndef Transform_hpp
#define Transform_hpp

#include <stdio.h>
//#include <OpenGL/gl3.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace AR_RenderEngine{
    class Transform {
        
    private:
        glm::mat4 GetModelMatrix();
    public:
        
        glm::vec3 m_position;
        glm::vec3 m_rotation;
        glm::vec3 m_scale;
        
        void BindTransform(GLint uniformLocation);
        void Translate(glm::vec3);
        void Rotate(glm::vec3);
        void Scale(glm::vec3);
        Transform();
        ~Transform();
    };
}



#endif /* Transform_hpp */
