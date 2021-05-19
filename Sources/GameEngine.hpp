#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <Components.hpp>
#include <RenderComponent.h>

class GameEngine
{
public:
  GameEngine();
  void OnStart();
  void OnUpdate();
  void OnDestroy();

  /**
  * @brief : making use of template specialization, this base will be useless
  */
  template<typename T>
  T* AddNewComponent(unsigned)
  {
    return nullptr;
  }

  /**
  * @brief : making use of template specialization, this base will be useless
  */
  template<typename T>
  T* GetComponent(unsigned)
  {
    return nullptr;
  }

  /**
  * @brief : This is to achieve nice syntax such as auto* pRenderComp = AddNewComponent<RenderComponent>()
  */
  template<>
  RenderComponent* AddNewComponent<RenderComponent>(unsigned u32ID)
  {
    return m_cRenderEngine.AddNewComponent(u32ID);
  }

  /**
  * @brief : This is to achieve nice syntax such as auto* pRenderComp = AddNewComponent<RenderComponent>()
  */
  template<>
  RenderComponent* GetComponent<RenderComponent>(unsigned u32ID)
  {
    return m_cRenderEngine.GetComponent(u32ID);
  }

private:
  Components< RenderComponent > m_cRenderEngine;
};

extern GameEngine* g_pGE;

#endif