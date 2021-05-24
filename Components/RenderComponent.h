#pragma once

#include "BaseComponent.h"

class ShaderProgram;

class RenderComponent : public BaseComponent
{
public:
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

