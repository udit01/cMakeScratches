/*! \brief Hack squareroot calculation
 *
 *  A hack square root calculation using simple operations.
 *  Uses Exp or Log depending on their availibility (checked by CMake)
 */
#include "MathFunctions.h"
#include <stdio.h>
 
double mysqrt(double x)
{
// if we have both log and exp then use them
#if defined(HAVE_LOG) && defined(HAVE_EXP)
  fprintf(stdout, "LOG and EXP found yayy!\n");
  result = exp(log(x) * 0.5);
#else // otherwise use an iterative approach

  if (x <= 0) {
    return 0;
  }

  double result;
  double delta;
  result = x;

  // do ten iterations
  int i;
  for (i = 0; i < 10; ++i) {
    if (result <= 0) {
      result = 0.1;
    }
    delta = x - (result * result);
    result = result + 0.5 * delta / result;
    fprintf(stdout, "Computing sqrt of %g to be %g\n", x, result);
  }

#endif

  return result;

}
