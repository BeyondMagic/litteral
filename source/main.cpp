#include <fmt/format.h>
#include "lyrics.hpp"

#define ARGS_QUANTITY 2

int main (const int argc, const char **argv)
{
  if (argc != ARGS_QUANTITY)
  {
    fmt::print(stderr, "Lack of second string argument representing .lrc filename.\n");
    return EXIT_FAILURE;
  }

  const std::string_view filename(argv[1]);
  try {
    Lyrics lyrics(filename);
  } catch (char const *message) {
    fmt::print(stderr, "{}\n", message);
    return EXIT_FAILURE;
  }
}
