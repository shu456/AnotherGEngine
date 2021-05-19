#include <Resource.hpp>

Resource::Resource(unsigned char* u8Data)
  : m_u8Data(u8Data)
{
}

Resource::~Resource()
{
  delete m_u8Data;
}
