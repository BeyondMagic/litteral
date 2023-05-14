#include <filesystem>
#include <string_view>
#include <fstream>
#include <vector>

struct Lyrics
{
  Lyrics  (const std::string_view &);
  ~Lyrics ()=default;
  std::vector<std::string> text;

  auto clean_text ();

  private:
    [[nodiscard]] auto read_path (const std::filesystem::path&);

    //size_t line = 0;
    //size_t running = 0;
};

auto
Lyrics::clean_text ()
{
  std::vector<std::string> new_text;

  for (auto it = text.begin(); it != text.end(); it++)
  {
    std::istringstream is(*it);

    /* TODO: Add flag to show metainformation of the lyrics.
     *       Currently it just ignores. */
    char a, b, c, d;
    is >> a >> b >> c >> d;

    if (not (a == '[' and std::isalpha(b) and std::isalpha(c) and d == ':'))
      new_text.emplace_back(*it);
  }

  text.swap(new_text);
}

auto
Lyrics::read_path (const std::filesystem::path& path)
{
  // Sanity check.
  if (!std::filesystem::is_regular_file(path))
    throw "Did not found such file.";

  // Open the file:
  // Note that we have to use binary mode as we want to return a string
  // representing matching the bytes of the file on the file system.
  std::ifstream file(path, std::ios::in | std::ios::binary);
  if (!file.is_open())
    throw "File could not be read.";

  // Read contents
  std::vector<std::string> contents;

  for (std::string line; std::getline(file, line);)
    contents.emplace_back(line);

  // Close the file.
  file.close();

  return contents;
}

Lyrics::Lyrics (const std::string_view &filename)
{
  const auto path = std::filesystem::path(filename);

  this->text = this->read_path(filename);
}
