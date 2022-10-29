#ifndef RENDER_COMPONENT_H
#define RENDER_COMPONENT_H

#include <BaseComponent.hpp>
#include <filesystem>

class ShaderProgram;

class RenderComponent : public BaseComponent
{
public:
  void SetupShader(std::filesystem::path const& vertFile, std::filesystem::path const& fragFile);
  /**
  * @brief : For initializing game object
  */
  virtual void OnStart() override;
  /**
  * @brief : Callback when updating
  */
  virtual void OnUpdate() override;
  /**
  * @brief : Callback when destroyed
  */
  virtual void OnDestroy() override;
  virtual ~RenderComponent();
private:
  unsigned m_u32VBO;
  unsigned m_u32VAO;
  unsigned m_u32EBO;
  ShaderProgram* m_pShaderProg;
};

extern Components< RenderComponent > g_cRenderEngine;

/**
* @brief : This is to achieve nice syntax such as auto* pRenderComp = AddNewComponent<RenderComponent>()
*/
template<>
inline RenderComponent* AddNewComponent<RenderComponent>(unsigned u32ID)
{
  return g_cRenderEngine.AddNewComponent(u32ID);
}

/**
* @brief : This is to achieve nice syntax such as auto* pRenderComp = AddNewComponent<RenderComponent>()
*/
template<>
inline RenderComponent* GetComponent<RenderComponent>(unsigned u32ID)
{
  return g_cRenderEngine.GetComponent(u32ID);
}


#endif
