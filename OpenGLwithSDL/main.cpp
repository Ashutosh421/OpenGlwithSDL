//
//  main.cpp
//  OpenGLwithSDL
//
//  Created by Ashutosh Rautela on 31/05/17.
//  Copyright © 2017 Ashutosh Rautela. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
//#include <OpenGL/gl3.h>
#include "GameObject.hpp"
#include "Time.hpp"
#include "Camera.hpp"
#include "Input.hpp"

struct WindowSize{
    int WIDTH;
    int HEIGHT;
}WINDOW;

void Init();
void WindowSetup();
void SetupObjects();

void GameLoop();
void Rendering();
void EventLoop();
void Close();

bool quitGame = false;

SDL_Window* sdlWindow;
SDL_GLContext sdlGLContext;
SDL_Event sdlEvent;
AR_RenderEngine::Mesh* newMesh;
AR_RenderEngine::GameObject* quad;
AR_RenderEngine::Camera* camera;
AR_RenderEngine::Texture* testTexture;


void Init(){
    WindowSetup();
    SetupObjects();
}

void SetupObjects(){
    camera = new AR_RenderEngine::Camera(WINDOW.WIDTH ,  WINDOW.HEIGHT);
    
   /* AR_RenderEngine::Vertex vertices[6];
    vertices[0].position = { -0.5f , -0.5f , 0 };
    vertices[0].color = { 255 , 0 , 0 , 255 };
    vertices[0].uv = { 0.0f , 0.0 } ;
    
    vertices[1].position = { -0.5f ,  0.5f , 0 };
    vertices[1].color = { 0 , 255 , 0 , 255 };
    vertices[1].uv = { 0.0f , 1.0f } ;
    
    vertices[2].position = {  0.5f ,  0.5f , 0 };
    vertices[2].color = { 0 , 0 , 255 , 255 };
    vertices[2].uv = { 1.0f , 1.0f } ;
    
    vertices[3].position = {  0.5f ,  0.5f , 0 };
    vertices[3].color = { 0 , 0 , 255 , 255 };
    vertices[3].uv = { 1.0f , 1.0f } ;
    
    vertices[4].position = { -0.5f , -0.5f , 0 };
    vertices[4].color = { 1 , 0 , 0 , 255 };
    vertices[4].uv = { 0.0f , 0.0f } ;
    
    vertices[5].position = {  0.5f , -0.5f , 0 };
    vertices[5].color = { 0 , 1 , 0 , 255 };
    vertices[5].uv = { 1.0f , 0.0f } ;*/
    
    
    AR_RenderEngine::Vertex vertices[8];
    vertices[0].position = { -0.5f, -0.5f , -0.5};    // 0
    vertices[0].color = {255 ,  0  , 0   , 255};
    vertices[0].uv = { 0.0f , 1.0f};
    
    vertices[1].position = { -0.5f,  0.5f , -0.5f};   // 1
    vertices[1].color = {0   , 255 , 0   , 255 };
    vertices[1].uv = { 0.0f , 0.0f};
    
    vertices[2].position = {  0.5f,  0.5f , -0.5f};   // 2
    vertices[2].color = {0   ,  0  , 255 , 255 };
    vertices[2].uv = { 1.0f , 0.0f};
    
    vertices[3].position = {  0.5f, -0.5f , -0.5f};  // 3
    vertices[3].color = {255 , 0   , 0   , 255 };
    vertices[3].uv = { 1.0f , 1.0f};
    
    vertices[4].position = { -0.5f, -0.5f ,  0.5};   // 4
    vertices[4].color = {255 ,  0  , 0   , 255};
    vertices[4].uv = { 0.0f , 0.0f};
    
    vertices[5].position = { -0.5f,  0.5f ,  0.5f};   //5
    vertices[5].color = {0   , 255 , 0   , 255 };
    vertices[5].uv = { 1.0f , 1.0f};
    
    vertices[6].position = {  0.5f,  0.5f ,  0.5f};    // 6
    vertices[6].color = {0   ,  0  , 255 , 255 };
    vertices[6].uv = { 0.0f , 1.0f};
    
    vertices[7].position = {  0.5f, -0.5f ,  0.5f};   //7
    vertices[7].color = {255 , 0   , 0   , 255 };
    vertices[7].uv = { 1.0f , 0.0f};
    
    GLushort indices[36] = {  0 , 1 , 2 , 0 , 2 , 3
                            , 4 , 5 , 6 , 4 , 6 , 7
                            , 0 , 4 , 5 , 0 , 5 , 1
                            , 3 , 7 , 6 , 3 , 6 , 2
                            , 0 , 3 , 7 , 0 , 7 , 4
                            , 1 , 2 , 6 , 1 , 6 , 5
                                };
    
    newMesh = new AR_RenderEngine::Mesh(vertices, indices, sizeof(indices)/sizeof(indices[0]));
    quad = new AR_RenderEngine::GameObject();
    quad->SetMesh(newMesh);
    quad->SetMainCamera(camera);
    quad->transform->Scale(glm::vec3(1 , 1 , 1));
   // quad->transform->Rotate(glm::vec3(0, -20 , 0));
    
    camera->position = glm::vec3( 0 , 0 , 4.0f );
    
    testTexture = new AR_RenderEngine::Texture("wall.jpg");
    quad->SetTexture(testTexture);
}

void WindowSetup(){
    WINDOW.WIDTH = 1024;
    WINDOW.HEIGHT = 768;
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL Couldn't initialize.." << std::endl;
    }
    else
    {
        //This is important in MAc BRO...   :D
        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8 );
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,16);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        
        sdlWindow = SDL_CreateWindow("Sample Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW.WIDTH, WINDOW.HEIGHT, SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
        if (sdlWindow == NULL) {
            std::cout << "SDL Window couldn't be created.. " << std::endl;
            Close();
            return;
        }
        else{
            //std::cout << "SDL Window successfully created " <<std::endl;
            sdlGLContext = SDL_GL_CreateContext(sdlWindow);
            GLenum glewInitCheck = glewInit();
            if (glewInitCheck != GLEW_OK) {
                std::cout << "GLEW couldn't initialize " << glewGetErrorString(glewInitCheck) << std::endl;
                Close();
            }
            else{
               // std::cout << "GLEW successfully initialized " <<std::endl;
                std::cout << "Current OpenGL Version is " << glGetString(GL_VERSION) << std::endl;
                glViewport(0, 0, WINDOW.WIDTH, WINDOW.HEIGHT);
                
            }
        }
    }
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, const char * argv[]) {

    Init();
    GameLoop();
    Close();
    
    return 0;
}

void GameLoop(){
    while (!quitGame) {
        
        Rendering();
        EventLoop();
        
    }
}

void Rendering(){
    Time::UpdateTime();
    glClearColor(0.2f, 0.2f, 0.2f, 1);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    
    quad->Draw();
    //quad->transform->m_position = glm::vec3(sin(Time::timeSinceLevelLoadInSecs) , 0 , 0);
    quad->transform->m_rotation = glm::vec3( Time::timeSinceLevelLoadInSecs , (Time::timeSinceLevelLoadInSecs) , 0);
    //camera->position = glm::vec3(sin(Time::timeSinceLevelLoadInSecs) , 0 , 2);
    
    SDL_GL_SwapWindow(sdlWindow);
}

void EventLoop(){
    while (SDL_PollEvent(&sdlEvent)) {
        if (sdlEvent.type == SDL_QUIT) {
            Close();
        }
        if(sdlEvent.type == SDL_WINDOWEVENT){
            if(sdlEvent.window.event == SDL_WINDOWEVENT_RESIZED)
            {
              /*  WINDOW.WIDTH = sdlEvent.window.data1;
                WINDOW.HEIGHT = sdlEvent.window.data2;
                glViewport(0, 0, WINDOW.WIDTH, WINDOW.HEIGHT);*/
            }
        }
        if (sdlEvent.type == SDL_KEYDOWN || sdlEvent.type == SDL_KEYUP) {
            AR_RenderEngine::Input::HandleKeyEvent(sdlEvent);
            
            if(sdlEvent.type == SDL_KEYDOWN)
            {
                if (sdlEvent.key.keysym.sym == SDLK_UP) {
                    //camera->position = glm::vec3( 1 * Time::timeSinceLevelLoadInSecs , 0 , 0);
                }
                if (sdlEvent.key.keysym.sym == SDLK_DOWN) {
                    
                }
                if (sdlEvent.key.keysym.sym == SDLK_LEFT) {
                    camera->position.x -=  1 * Time::deltaTime;
                }
                if (sdlEvent.key.keysym.sym == SDLK_RIGHT) {
                    camera->position.x +=  1 * Time::deltaTime;
                }
            }
        }
    }
}

void Close(){
    quitGame = true;
    SDL_GL_DeleteContext(sdlGLContext);
    SDL_DestroyWindow(sdlWindow);
    SDL_Quit();
}
