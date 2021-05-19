#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <RenderComponent.h>

#include <SampleResource.hpp>

#include <Shaders.hpp>

void RenderComponent::OnStart()
{
  /** Create 2 shaders out from sample*/
  Shader* vert = new Shader(vertexShaderSource, GL_VERTEX_SHADER);
  Shader* frag = new Shader(fragmentShaderSource, GL_FRAGMENT_SHADER);

  /** Setup shaders*/
  vert->Setup();
  frag->Setup();

  m_pShaderProg = new ShaderProgram(vert, frag);
  m_pShaderProg->Setup();

  glGenVertexArrays(1, &m_u32VAO);
  glGenBuffers(1, &m_u32VBO);

  glBindVertexArray(m_u32VAO);
  glBindBuffer(GL_ARRAY_BUFFER, m_u32VBO);

  //copy the triangle data into the buffer defined by OnStart
  glBufferData(GL_ARRAY_BUFFER, sizeof(Triangles), Triangles, GL_STATIC_DRAW);

  //set the vertex attributes pointers
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  //unbind vbo and vao
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

void RenderComponent::OnUpdate()
{
  //use shader program to render an object
  m_pShaderProg->Use();

  //draw
  glBindVertexArray(m_u32VAO);
  glDrawArrays(GL_TRIANGLES, 0, 6);
}

void RenderComponent::OnDestroy()
{
  glDeleteVertexArrays(1, &m_u32VAO);
  glDeleteBuffers(1, &m_u32VBO);
  m_pShaderProg->Destroy();
}

RenderComponent::~RenderComponent()
{
  delete m_pShaderProg;
}
