#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Shaders.hpp>

#include <GLObject.hpp>

Shader::Shader(std::filesystem::path const& path, unsigned u32ShaderType) :
  FileResource(path),
  m_u32ShaderType(u32ShaderType),
  m_pglObj(CreateGLObject<1>(glCreateShader, glDeleteShader))
{
}

Shader::~Shader()
{
  Destroy();
}

void Shader::Setup()
{
  m_pglObj->Setup(m_u32ShaderType);
  char const* _data{ getData().data() };
  glShaderSource(GetID(), 1, &_data, NULL);
  glCompileShader(GetID());
}

void Shader::Destroy()
{
  m_pglObj->Destroy();
}

unsigned Shader::GetID() const
{
  return m_pglObj->GetID();
}

ShaderProgram::ShaderProgram(Shader* pVert, Shader* pFrag) :
  m_pShaders{ pVert, pFrag },
  m_pglObj(CreateGLObject<0>(glCreateProgram, glDeleteProgram))
{
}

ShaderProgram::~ShaderProgram()
{
  Destroy();
}

void ShaderProgram::Setup()
{
  m_pglObj->Setup();
  for (auto& pShader : m_pShaders)
  {
    glAttachShader(m_pglObj->GetID(), pShader->GetID());
  }
  glLinkProgram(m_pglObj->GetID());

  int success = 1; // will be 0 if linking error.
  // check for linking errors
  glGetProgramiv(m_pglObj->GetID(), GL_LINK_STATUS, &success);
  if (!success) {
    char infoLog[512];
    glGetProgramInfoLog(m_pglObj->GetID(), 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
  }
}

void ShaderProgram::Use() const
{
  glUseProgram(m_pglObj->GetID());
}

void ShaderProgram::Destroy()
{
  for (auto& pShader : m_pShaders)
  {
    delete pShader;
  }
  m_pglObj->Destroy();
}
