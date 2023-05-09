#include <filesystem>
#include <string_view>
#include <fstream>
#include <vector>

struct Lyrics
{
  Lyrics  (const std::string_view &);
  ~Lyrics ()=default;

  private:
    auto read_path (const std::filesystem::path&);

    std::vector<std::string_view> text;
    //size_t line = 0;
    //size_t running = 0;
};

[[nodiscard]]
auto
Lyrics::read_path (const std::filesystem::path& path)
{
  std::vector<std::string_view> contents;

  // Sanity check.
  if (!std::filesystem::is_regular_file(path))
      return contents;

  // Open the file:
  // Note that we have to use binary mode as we want to return a string
  // representing matching the bytes of the file on the file system.
  std::ifstream file(path, std::ios::in | std::ios::binary);
  if (!file.is_open())
      return contents;

  // Read contents
  for (std::string line; std::getline(file, line);)
  contents.emplace_back(line);

  // Close the file
  file.close();

  return contents;
}

Lyrics::Lyrics (const std::string_view &filename)
{
  const auto path = std::filesystem::path(filename);

  this->text = read_path(filename);
}