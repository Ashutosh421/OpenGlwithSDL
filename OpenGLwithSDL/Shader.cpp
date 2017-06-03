//
//  Shader.cpp
//  OpenGLwithSDL
//
//  Created by Ashutosh Rautela on 03/06/17.
//  Copyright © 2017 Ashutosh Rautela. All rights reserved.
//

#include "Shader.hpp"

namespace AR_RenderEngine {
    
    Shader::Shader(std::string vertexShaderSource, std::string fragmentShaderSource)
    {
        m_vertexShader = glCreateShader(GL_VERTEX_SHADER);
        std::string vertexShaderData = ReadFileContent(vertexShaderSource);
        const char* vertexShaderContent = vertexShaderData.c_str();
        glShaderSource(m_vertexShader, 1, &vertexShaderContent, NULL);
        
        m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        std::string fragmentShaderData = ReadFileContent(fragmentShaderSource).c_str();
        const char* fragmentShaderContent = fragmentShaderData.c_str();
        glShaderSource(m_fragmentShader, 1, &fragmentShaderContent , NULL);
        
        glCompileShader(m_vertexShader);
        if(CheckShaderError(m_vertexShader, false, GL_COMPILE_STATUS, "Compilation Error: "+vertexShaderSource))
        {
            printf("Vertex Shader compiled \n");
        }
        glCompileShader(m_fragmentShader);
        if(CheckShaderError(m_fragmentShader, false, GL_COMPILE_STATUS, "Compilation Error: "+fragmentShaderSource))
        {
            printf("Fragment Shader compiled \n");
        }
        m_shaderProgram = glCreateProgram();
        
        glAttachShader(m_shaderProgram, m_vertexShader);
        glAttachShader(m_shaderProgram, m_fragmentShader);
        
        glLinkProgram(m_shaderProgram);
        
        if(CheckShaderError(m_shaderProgram, true, GL_LINK_STATUS, "Program Link Error: "))
        {
            printf("Shader Program linked successfully \n");
        }
    
        glValidateProgram(m_shaderProgram);
        if(CheckShaderError(m_shaderProgram, true, GL_VALIDATE_STATUS, "Program Validation Error: "))
        {
            printf("Shader Program validated successfully \n");
        }
        
    }
    
    bool Shader::CheckShaderError(GLuint shaderOrProgram , bool isProgram , GLenum checkType, std::string errorMessage){
        GLint checkResult;
        if (!isProgram)
        {
            glGetShaderiv(shaderOrProgram, checkType, &checkResult);
            if(checkResult == GL_FALSE)
            {
                GLchar infoLog[512];
                glGetShaderInfoLog(shaderOrProgram, 512, NULL, infoLog);
                std::cout << errorMessage << " " << infoLog << std::endl;
                return false;
            }
        }
        else
        {
            glGetProgramiv(shaderOrProgram, checkType, &checkResult);
            if(checkResult == GL_FALSE)
            {
                GLchar infoLog[512];
                glGetProgramInfoLog(shaderOrProgram, 512, NULL, infoLog);
                std::cout <<errorMessage << " " << infoLog << std::endl;
                return false;
             }
        }
        return true;
    }
    
    void Shader::GLBindAttribute(std::string attributeName, unsigned int index)
    {
        glBindAttribLocation(m_shaderProgram, index, attributeName.c_str());
    }
    
    
    std::string Shader::ReadFileContent(std::string shaderSourcePath)
    {
        std::string shaderContent = "";
        std::fstream file;
        file.open(shaderSourcePath.c_str());
        if(!file.is_open())
        {
            std::cout << "Could open file " << shaderSourcePath << std::endl;
        }
        else
        {
            std::string newLine = "\n";
            while (getline(file, newLine)) {
                shaderContent.append(newLine + "\n");
            }
        }
       // std::cout << "File Read is " << shaderContent << std::endl;
        file.close();
        return shaderContent;
    }
    
    GLint Shader::GetUniformLocation(std::string vName)
    {
        return glGetUniformLocation(m_shaderProgram, vName.c_str());
    }
    
    void Shader::BindShader()
    {
        glUseProgram(m_shaderProgram);
    }
    
    void Shader::UnbindShader() 
    {
        glUseProgram(0);
    }
    
    Shader::~Shader()
    {
        glDeleteProgram(m_shaderProgram);
        glDeleteShader(m_vertexShader);
        glDeleteShader(m_fragmentShader);
    }
}
