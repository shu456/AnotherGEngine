#ifndef BASECOMPONENT_H
#define BASECOMPONENT_H

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

#endif
