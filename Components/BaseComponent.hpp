#ifndef BASECOMPONENT_H
#define BASECOMPONENT_H

#include <Components.hpp>

class GameObject;

class BaseComponent
{
public:
  /**
  * @brief : For initializing game object
  */
  virtual void OnStart() = 0;
  /**
  * @brief : Callback when updating
  */
  virtual void OnUpdate() = 0;
  /**
  * @brief : Callback when destroyed
  */
  virtual void OnDestroy() = 0;
  GameObject* m_pParent;
};

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

#endif
