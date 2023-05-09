#include <fmt/format.h>
#include "lyrics.hpp"

#define ARGS_QUANTITY 2

int main (const int argc, const char **argv)
{
  if (argc != ARGS_QUANTITY)
  {
    fmt::print(stderr, "Lack of second string argument representing .lrc filename.\n");
    return 1;
  }

  const std::string_view filename(argv[1]);
  fmt::print("I know what love is and this file name is \"{}\".\n", filename);

  Lyrics lyrics(filename);
}
