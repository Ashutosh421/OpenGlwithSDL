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


void Init(){
    WindowSetup();
    SetupObjects();
}

void SetupObjects(){
    camera = new AR_RenderEngine::Camera(WINDOW.WIDTH ,  WINDOW.HEIGHT);
    
    
   /* AR_RenderEngine::Vertex vertices[3];
    vertices[0].position = { -0.5f , -0.5f , 0 };
    vertices[1].position = {   0   ,  0.5f , 0 };
    vertices[2].position = {  0.5f , -0.5f , 0 };
    
    newMesh = new AR_RenderEngine::Mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));
    triangle = new AR_RenderEngine::GameObject();
    triangle->SetMesh(newMesh);
    triangle->SetMainCamera(camera);
    triangle->transform->m_scale = glm::vec3(0.5f , 0.5f , 0.5f);*/
    
    
    AR_RenderEngine::Vertex vertices[6];
    vertices[0].position = { -0.5f , -0.5f , 0 };
    vertices[1].position = { -0.5f ,  0.5f , 0 };
    vertices[2].position = {  0.5f ,  0.5f , 0 };
    vertices[3].position = {  0.5f ,  0.5f , 0 };
    vertices[4].position = { -0.5f , -0.5f , 0 };
    vertices[5].position = {  0.5f , -0.5f , 0 };
    
    newMesh = new AR_RenderEngine::Mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));
    quad = new AR_RenderEngine::GameObject();
    quad->SetMesh(newMesh);
    quad->SetMainCamera(camera);
    
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
    
   /* triangle->Draw();
    triangle->transform->m_position = glm::vec3(sin(Time::timeSinceLevelLoadInSecs)/2 , cos(Time::timeSinceLevelLoadInSecs)/2 , 0 );*/
    
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
        }
    }
}

void Close(){
    quitGame = true;
    SDL_GL_DeleteContext(sdlGLContext);
    SDL_DestroyWindow(sdlWindow);
    SDL_Quit();
}
