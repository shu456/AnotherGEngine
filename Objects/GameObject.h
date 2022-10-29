#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <vector>

class GameObject
{
public:
  /**
  * @brief : Unique ID
  */
  unsigned GetID() const;
  /**
  * @brief : For initializing game object 
  */
  virtual void OnStart();
  /**
  * @brief : Callback when updating
  */
  virtual void OnUpdate();
  /**
  * @brief : Callback when destroyed
  */
  virtual void OnDestroy();
protected:
  template<typename T>
  T* GetComponent()
  {
    return ::GetComponent<T>(m_u32ID);
  }

  template<typename T>
  T* AddNewComponent()
  {
    return ::AddNewComponent<T>(m_u32ID);
  }
private:
  unsigned m_u32ID;
  std::string m_sName;
};

#endif
