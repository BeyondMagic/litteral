#include <iostream>
#include "lyrics.hpp"

#define ARGS_QUANTITY 2

int main (const int argc, const char **argv)
{
  if (argc != ARGS_QUANTITY)
  {
    std::cout << "Lack of second string argument representing .lrc filename.\n";
    return EXIT_FAILURE;
  }

  const std::string_view filename{argv[1]};

  try
  {
    Lyrics lyrics(filename);
    lyrics.clean_text();
    lyrics.read();
  }
  catch (char const *message)
  {
    std::cerr << message << '\n';
    return EXIT_FAILURE;
  }
}
