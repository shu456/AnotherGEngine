#ifndef SHADERS_HPP
#define SHADERS_HPP

#include <FileResource.hpp>

class GLObjectHandlerInterface;

enum ShaderType 
{
  Vert = GL_VERTEX_SHADER,
  Frag = GL_FRAGMENT_SHADER
};

class Shader : public FileResource
{
public:
  Shader(std::filesystem::path const& path,unsigned u32ShaderType);
  ~Shader();
  void Setup();
  void Destroy();
  unsigned GetID() const;
protected:
  unsigned m_u32ShaderType;
  GLObjectHandlerInterface* m_pglObj;
};

class ShaderProgram
{
public:
  ShaderProgram(Shader*, Shader*);
  ~ShaderProgram();
  void Setup();
  void Use() const;
  void Destroy();
private:
  Shader* m_pShaders[2];
  GLObjectHandlerInterface* m_pglObj;
};

#endif
