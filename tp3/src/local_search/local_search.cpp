#include "local_search.h"

int main( int argc, char const* argv[] )
{
  const char* initialSolution = ( argc >= 2 ? argv[1] : NULL );
  const char* neighborhood = ( argc >= 3 ? argv[2] : NULL );
  Parser parser;
  parser.parseInput();
  /* code */
  return 0;
}