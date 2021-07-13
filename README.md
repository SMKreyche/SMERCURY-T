# SMERCURY-T
[![DOI](https://zenodo.org/badge/235687253.svg)](https://zenodo.org/badge/latestdoi/235687253)

An upgrade of the SMERCURY orbital integrator that includes modules to enable the solar tidal spin torque as well as the general relativistic force. In order to enable these modules for a SMERCURY-T simulation make sure that the param.in file specifies 'yes' for the obliquity tides (time lag model) and user-defined force (general relativity).

This work modified the existing spin-tracking orbital integration algorithm, smercury, which is based in the original mercury package developed by Chambers (1999). This algorithm follows Wisdom and Touma (1994), while additional details can be found in Lissauer et al. (2012) and Barnes et al. (2016). The smercury algorithm primarily differs from the base package by treating the first listed body in the 'big.in' file as a spin-tracked rigid rotator, while the central body and other planets are point masses. The bodies listed in the 'small.in' file are deemed 'ghost planets', and are massless copies of the spin-tracked 'big.in' body that copy the same orbital evolution but their spin evolution is computed independently. This algorithm includes the effects of torques from the Sun and other planets on the spin-tracked planet's equatorial bulge, as well as the resulting forces exerted back on those bodies which affects their orbits.

The modifications include the addition of the general relativistic force and the solar gravitational tidal torque according to Bolmont et al. (2015). The general relativistic force tends to speed up the apsidal precession of bodies in proximity to the central body, while the solar gravitational torque acts on the spin-tracked body and dampens its spin rate over time while its obliquity evolves. We specifically neglect the effects of orbital tides at present in order to preserve the 'small.in' ghost planet scheme, therefore the tidal module should only be applied to systems for which those effects can be neglected. There are also a series of additional quality of life improvements to the code listed below. 

See https://github.com/4xxi/mercury for more information on how to operate the parent code mercury.

Modifications:

- the param.in file now requires one of the following argument keywords to specify the spin-tracking algorithm: "spin", "Spin", "SPIN", "spn", or "SPN"

- following Bolmont et al. (2015), general relativisitic forces between the central body and each big body are now included for the spin algorithm if the user specifies "yes" to the user-defined routine option in the param.in file (only an option for the SPIN algorithm)

- double precision has been added everywhere in the smercury-T.for and element6.for files

- fixed spin rate and pomega output for ghost planet .aei files, and the spin node longitude now outputs from 0 to 360 degrees rather than -180 to 180

- new param.in format along with message.in updates to include the options for time lag tidal model that affects body 2 (in big.in input file) and the ghost planets (in small.in input file)

- added a time lag obliquity tides subroutine obl_tides.for that is included within the spin subroutine to compute the tidal torques from the star at each time step, while a new subroutine mce_spin.for is included to update the planets' radii, J2 coefficients, and therefore moment of inertia components according to the reverse of the equations found in apppendix A of Lissauer et al. (2012), as their spin angular momentum evolves over time

- the big.in and small.in files no longer need to specify the body's J2 coefficent since that is now calculated internally based on the input mass, density, moment of inertia coefficient, and spin angular momentum within the mdt_spin.for subroutine

- the big.in and small.in files require the input of the body's tidal potential love number (k=) and time lag duration (t=) in the header if using time lag obliquity tides

- element6.for includes changes to output new relevent parameters of each body with key letters in element.in such as their radii (k), spin periods (s), moment of inertia coefficients (c), J2 coefficients (j), spin inclination (h), spin nodal angle (t), spin angular momentum components (sx,sy,sz) = (1,2,3), which requried a redone new mce_spin.for subroutine that recalculates what was calculated in the spin subroutine of smercury-T.for

- The updated code letters for element.in are:
  - a = semi-major axis (AU)
  - b = apocentre distance (AU, b is short for Big q)
  - c = moment of inertia coefficient (C/MR^2)
  - d = density (g per cm^3)
  - e = eccentricity
  - f = true anomaly (degrees)
  - g = argument of perihelion (degrees)
  - h = spin vector inclination (degrees)
  - i = inclination (degrees)
  - j = J2 oblateness coefficient 
  - k = radius (km)
  - l = mean anomaly (degrees)
  - m = mass (solar masses)
  - n = longitude of ascending node (degrees)
  - o = obliquity (degrees)
  - p = longitude of perihelion (degrees)
  - q = pericentre distance (AU)
  - r = radial distance (AU)
  - s = spin period (days)
  - t = spin vector azimuth (degrees)
  - u, v or w = Cartesian velocities vx, vy or vz (AU/day)
  - x, y or z = Cartesian coordinates x, y or z (AU)
  - 1, 2, or 3 = spin vector components sx, sy, or sz (solar masses AU^2 /day)

- smercury-T.for includes a tidal tolerance scheme for the tidal time lag option. This scheme allows the user to specify a tolerance value in the param.in file, "tidal tolerance" which controls the frequency at which the tidal torques are added to the spin vector based on a comparision of the tidal torque magnitude to the spin vector magnitude, which in turn also controls how often the planet radius and moment of inertia tensor needs to be updated. tidal tolerance = 1d-12 is a typical value, while ttol = 0d0 would instruct the tidal torque to be added at every time step
