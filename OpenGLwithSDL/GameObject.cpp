//
//  Mesh.cpp
//  OpenGLwithSDL
//
//  Created by Ashutosh Rautela on 02/06/17.
//  Copyright © 2017 Ashutosh Rautela. All rights reserved.
//

#include "GameObject.hpp"


namespace AR_RenderEngine {
    
    Mesh::Mesh(Vertex* vertices, GLushort *indices , int drawCount) : m_VAO(0) , m_VBO(0) , m_IBO(0){
        this->vertices;
        this->indices = indices;
        
        
        m_drawCount = drawCount;
        glGenVertexArrays(1 , &m_VAO);
        glBindVertexArray(m_VAO);
        
        glGenBuffers(1, &m_VBO);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        
        glGenBuffers(1, &m_IBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , m_IBO);
        
        glBufferData(GL_ARRAY_BUFFER, drawCount * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, drawCount * sizeof(indices[0]) , indices , GL_STATIC_DRAW);
        
        
        glVertexAttribPointer(0  ,  3  ,  GL_FLOAT          , GL_FALSE  , (sizeof(Vertex)) , (void*)0) ;
        glVertexAttribPointer(1  ,  4  ,  GL_UNSIGNED_BYTE  , GL_TRUE   , (sizeof(Vertex)) , (void*)(3 * sizeof(GLfloat)));
        glVertexAttribPointer(2  ,  2  ,  GL_FLOAT          , GL_FALSE  , (sizeof(Vertex)) , (void*)(3 * sizeof(GLfloat) + 4 * sizeof(GLubyte)));
        
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);
        
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(2);
    }
    
    Mesh::~Mesh(){
        glDeleteVertexArrays(1, &m_VAO);
        glDeleteBuffers(1, &m_VBO);
    }
    
    void Mesh::Draw(){
        glBindVertexArray(m_VAO);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);
        
     //   glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
        glDrawElements(GL_TRIANGLES, m_drawCount, GL_UNSIGNED_SHORT,0);
        
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(2);
        glBindVertexArray(0);
    }
    
    GameObject::GameObject(){
        shader = new  AR_RenderEngine::Shader("vertexShader.vsh" , "fragmentShader.fsh");
        shader->GLBindAttribute("vertPosition", 0);
        shader->GLBindAttribute("color", 1);
        shader->GLBindAttribute("uv", 2);
        shader->BindShader();
        m_transformUniformLocation = shader->GetUniformLocation("modelMatrix");
        m_viewMat4UniformLocation = shader->GetUniformLocation("viewMatrix");
        m_projectionMat4UniformLocation = shader->GetUniformLocation("projectionMatrix");
        
        transform = new Transform();
    }
    
    GameObject::GameObject(Mesh* mesh){

    }
    
    GameObject::~GameObject(){
    
    }
    
    void GameObject::SetMainCamera(AR_RenderEngine::Camera *mainCamera)
    {
        this->mainCamera = mainCamera;
    }
    
    void GameObject::BindWithCamera(){
        glUniformMatrix4fv(m_transformUniformLocation, 1, GL_FALSE , &(transform->GetModelMatrix()[0][0]));
        glUniformMatrix4fv(m_projectionMat4UniformLocation, 1, GL_FALSE, &(mainCamera->GetProjectionMat4f()[0][0]));
        glUniformMatrix4fv(m_viewMat4UniformLocation, 1, GL_FALSE, &(mainCamera->GetViewMat4f()[0][0]));
    }
    
    void GameObject::SetShader(AR_RenderEngine::Shader *shader)
    {
     
    }
    
    void GameObject::SetMesh(Mesh *mesh){
        this->mesh = mesh;
    }
    
    void GameObject::SetTexture(Texture *texture)
    {
        this->texture = texture;
    }
    
    void GameObject::Draw()
    {
        shader->BindShader();
        this->BindWithCamera();
        this->texture->BindTexture(0);
        this->mesh->Draw();
        this->texture->UnBindTexture();
        shader->UnbindShader();
    }
}
