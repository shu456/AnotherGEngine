#ifndef FILE_RESOURCE_HPP
#define FILE_RESOURCE_HPP

#include <filesystem>
#include <Resource.hpp>
#include <string>

class FileResource : Resource
{
public:
  FileResource(std::filesystem::path const& path);

  std::string_view getData() const;
private:
  void LoadFile(std::filesystem::path const& path);
  std::string m_data;
};

#endif
