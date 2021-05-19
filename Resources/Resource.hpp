#ifndef RESOURCE_HPP
#define RESOURCE_HPP

/**
* Base class for all resources
*/
class Resource
{
public:
  Resource(unsigned char* u8Data = nullptr);
  virtual ~Resource();
protected:
  unsigned char* m_u8Data;
};

#endif
