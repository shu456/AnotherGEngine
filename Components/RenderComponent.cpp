#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <RenderComponent.hpp>

#include <SampleResource.hpp>

#include <Shaders.hpp>

Components< RenderComponent > g_cRenderEngine;

#define USE_VBO 0
//#define DEBUG

void RenderComponent::SetupShader(std::filesystem::path const& vertFile, std::filesystem::path const& fragFile)
{
  /** Create 2 shaders out from sample*/
  Shader* vert = new Shader(vertFile, GL_VERTEX_SHADER);
  Shader* frag = new Shader(fragFile, GL_FRAGMENT_SHADER);

  /** Setup shaders*/
  vert->Setup();
  frag->Setup();

  m_pShaderProg = new ShaderProgram(vert, frag);

  m_pShaderProg->Setup();
}

void RenderComponent::OnStart()
{
  glGenVertexArrays(1, &m_u32VAO);
  glGenBuffers(1, &m_u32VBO);

  glBindVertexArray(m_u32VAO);

  //copy the triangle data into the buffer defined by OnStart
  glBindBuffer(GL_ARRAY_BUFFER, m_u32VBO);
#if (USE_VBO)
  glBufferData(GL_ARRAY_BUFFER, sizeof(Triangles), Triangles, GL_STATIC_DRAW);
#else
  glBufferData(GL_ARRAY_BUFFER, sizeof(EBO::vertices), EBO::vertices, GL_STATIC_DRAW);
#endif
  //set the vertex attributes pointers
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  //create indices for the binded vertices
  glGenBuffers(1, &m_u32EBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_u32EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(EBO::indices), EBO::indices, GL_STATIC_DRAW);

  //unbind vbo and vao
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

void RenderComponent::OnUpdate()
{
#if DEBUG
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
#else
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
#endif
  //use shader program to render an object
  m_pShaderProg->Use();
  glBindVertexArray(m_u32VAO);
#if (USE_VBO)
  //draw
  glDrawArrays(GL_TRIANGLES, 0, 3);
#else
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_u32EBO);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
#endif
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
