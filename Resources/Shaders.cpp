#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Shaders.hpp>

#include <GLObject.hpp>

Shader::Shader(const char * c8Data, unsigned u32ShaderType) :
  Resource(reinterpret_cast<unsigned char*>( const_cast<char*>( c8Data) )),
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
  const char* c8Data = reinterpret_cast<const char*>( m_u8Data );
  glShaderSource(GetID(), 1, &c8Data, NULL);
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
