//
//  Mesh.hpp
//  OpenGLwithSDL
//
//  Created by Ashutosh Rautela on 02/06/17.
//  Copyright © 2017 Ashutosh Rautela. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp

//#include <OpenGL/gl3.h>
#include <GL/glew.h>
#include "Shader.hpp"
#include "Transform.hpp"
#include "Camera.hpp"

namespace AR_RenderEngine {
    
    struct Vertex
    {
        struct Position
        {
            GLfloat x;
            GLfloat y;
            GLfloat z;
        }position;
    };
    
    class Mesh {
        
    private:
        Vertex* vertices;
        
    public:
        unsigned int m_drawCount= 0;
        GLuint m_VAO;
        GLuint m_VBO;
        
        Mesh(Vertex* vertices, int drawCount);
        void Draw();
        ~Mesh();
    };
    
    class GameObject{
        
    private:
        GLint m_transformUniformLocation;
        GLint m_viewMat4UniformLocation;
        GLint m_projectionMat4UniformLocation;
        
        void BindWithCamera();
        
    public:
        Mesh* mesh;
        AR_RenderEngine::Shader* shader;
        AR_RenderEngine::Transform* transform;
        Camera* mainCamera;
        
    public:
        GameObject();
        GameObject(Mesh* mesh);
        ~GameObject();
        void SetShader(AR_RenderEngine::Shader* shader);
        void SetMesh(Mesh* mesh);
        void SetShaderProgram();
        void SetMainCamera(Camera* mainCamera);
        void Draw();
    };
}

#include <stdio.h>

#endif /* Mesh_hpp */
