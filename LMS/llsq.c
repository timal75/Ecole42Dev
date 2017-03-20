# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

# include "llsq.h"


void llsq ( int n, double x[], double y[], double *a, double *b )
{
  double bot;
  int i;
  double top;
  double xbar;
  double ybar;
  if ( n == 1 )
  {
    *a = 0.0;
    *b = y[0];
    return;
  }
  xbar = 0.0;
  ybar = 0.0;
  for ( i = 0; i < n; i++ )
  {
    xbar = xbar + x[i];
    ybar = ybar + y[i];
  }
  xbar = xbar / ( double ) n;
  ybar = ybar / ( double ) n;
/*
  Compute Beta.
*/
  top = 0.0;
  bot = 0.0;
  for ( i = 0; i < n; i++ )
  {
    top = top + ( x[i] - xbar ) * ( y[i] - ybar );
    bot = bot + ( x[i] - xbar ) * ( x[i] - xbar );
  }
  *a = top / bot;

  *b = ybar - *a * xbar;

  return;
}

void timestamp ( void )
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
