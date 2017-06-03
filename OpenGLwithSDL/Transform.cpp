//
//  Transform.cpp
//  OpenGLwithSDL
//
//  Created by Ashutosh Rautela on 03/06/17.
//  Copyright © 2017 Ashutosh Rautela. All rights reserved.
//

#include "Transform.hpp"

namespace AR_RenderEngine {
    
    Transform::Transform():m_position(glm::vec3(0 , 0 , 0)), m_rotation(glm::vec3( 0 , 0 , 0 )) , m_scale(glm::vec3( 1 , 1 , 1))
    {
        
    }
    
    glm::mat4 Transform::GetModelMatrix(){
        glm::mat4 transformMatrix;
        
        glm::mat4 positionMatrix;
        positionMatrix = glm::translate(positionMatrix, m_position);
        
        glm::mat4 rotationXMatrix;
        rotationXMatrix = glm::rotate(rotationXMatrix, m_rotation.x, glm::vec3( 1 , 0 , 0 ));
        
        glm::mat4 rotationYMatrix;
        rotationYMatrix = glm::rotate(rotationYMatrix, m_rotation.y, glm::vec3( 0 , 1 , 0 ));
        
        glm::mat4 rotationZMatrix;
        rotationZMatrix = glm::rotate(rotationZMatrix, m_rotation.z, glm::vec3( 0 , 0 , 1 ));
        
        glm::mat4 rotationMatrix;
        rotationMatrix = rotationZMatrix * rotationYMatrix * rotationXMatrix;
        
        glm::mat4 scaleMatrix;
        scaleMatrix = glm::scale(scaleMatrix, m_scale);
        
        transformMatrix = positionMatrix * rotationMatrix * scaleMatrix;
        
        return transformMatrix;
    }
    
    void Transform::Translate(glm::vec3 translation){
        m_position += translation;
    }
    
    void Transform::Rotate(glm::vec3 rotation){
        m_rotation += rotation;
    }
    
    void Transform::Scale(glm::vec3 scale){
        m_scale += scale;
    }
    
    void Transform::BindTransform(GLint uniformLocation){
        glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, &(GetModelMatrix()[0][0]));
    }
    
    
    Transform::~Transform()
    {
        
    }
}
