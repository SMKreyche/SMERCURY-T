c%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
c
c      MERCURY.INC    (ErikSoft   31 January 2001)
c
c%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
c
c Author: John E. Chambers
c
c Parameters that you may want to alter at some point:
c
c NMAX  = maximum number of bodies
c CMAX  = maximum number of close-encounter minima monitored simultaneously
c NMESS = maximum number of messages in message.in
c HUGE  = an implausibly large number
c NFILES = maximum number of files that can be open at the same time
c
      integer NMAX, CMAX, NMESS, NFILES
      double precision HUGE
c
      parameter (NMAX = 2000)
      parameter (CMAX = 2000)
      parameter (NMESS = 200)
      parameter (HUGE = 9.9d29)
      parameter (NFILES = 100)
c
c------------------------------------------------------------------------------
c
c Constants:
c
c DR = conversion factor from degrees to radians
c K2 = Gaussian gravitational constant squared
c AU = astronomical unit in cm
c MSUN = mass of the Sun in g
c lightspeed = speed of light in vacuum in AU/day
c
      double precision PI,TWOPI,PIBY2,DR,K2,AU,MSUN,lightspeed
c
      parameter (PI = 3.141592653589793d0)
      parameter (TWOPI = PI * 2.d0)
      parameter (PIBY2 = PI * .5d0)
      parameter (DR = PI / 180.d0)
      parameter (K2 = 2.959122082855911d-4)
      parameter (AU = 1.4959787e13)
      parameter (MSUN = 1.9891e33)
      parameter (lightspeed = 1.731446335d2)
