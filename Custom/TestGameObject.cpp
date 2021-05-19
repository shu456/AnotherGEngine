#include <iostream>

#include "TestGameObject.hpp"

void TestObject::OnStart()
{
  RenderComponent* rc = AddNewComponent<RenderComponent>();

  RenderComponent* rc1 = GetComponent< RenderComponent >();

  if (rc1 == rc)
  {
    std::cout << "Success" << std::endl;
  }
  else
  {
    std::cout << "Failed" << std::endl;
  }
}
