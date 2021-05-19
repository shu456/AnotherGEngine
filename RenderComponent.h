#pragma once

#include "BaseComponent.h"

class ShaderProgram;

class RenderComponent : public BaseComponent
{
public:
  void OnStart() override;
  void OnUpdate() override;
  void OnDestroy() override;
  virtual ~RenderComponent();
private:
  unsigned m_u32VBO;
  unsigned m_u32VAO;
  ShaderProgram* m_pShaderProg;
};

