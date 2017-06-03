//
//  Shader.hpp
//  OpenGLwithSDL
//
//  Created by Ashutosh Rautela on 03/06/17.
//  Copyright © 2017 Ashutosh Rautela. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#include <iostream>
//#include <OpenGL/gl3.h>
#include <GL/glew.h>
#include <fstream>
#include <string>

namespace AR_RenderEngine {

    class Shader {
        
    private:
        GLuint m_vertexShader;
        GLuint m_fragmentShader;
        GLuint m_shaderProgram;
        
        std::string ReadFileContent(std::string shaderSourcePath);
        bool CheckShaderError(GLuint shaderOrProgram ,bool isProgram , GLenum checkType, std::string errorMessage);
    public:
        
        Shader(std::string vertexShaderSource, std::string fragmentShaderSource);
        ~Shader();
        
        void BindShader() ;
        void UnbindShader()  ;
        void GLBindAttribute(std::string attributeName , unsigned int index);
        GLint GetUniformLocation(std::string vName);
    };

}

#endif /* Shader_hpp */
