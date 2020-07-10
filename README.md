# Smercury-T
A work in progress to equip the smercury orbital integrator with tidal and general relativisitic effects.

This work will modify the existing spin-tracking orbital integration algorithm, smercury, which is based in the original mercury package developed by Chambers (1999). The modifications include the addition of general relativistic forces, solar gravitational tidal effects on planetary obliquity and rotation rate, and other quality of life improvements. 

Modifications so far:

- the param.in file now requires one of the following argument keywords to specify the spin-tracking algorithm: "spin", "Spin", "SPIN", "spn", or "SPN"

- following Bolmont et al. (2015), general relativisitic forces between the central body and each big body are now included for the spin algorithm if the user specifies "yes" to the user-defined routine option in the param.in file

- double precision has been added everywhere in the smercury-T.for and element6.for files

- fixed spin rate and pomega output for ghost planet .aei files, and the spin node longitude now outputs from 0 to 360 degrees rather than -180 to 180

- new param.in format along with message.in updates to include the options for phase lag or time lag obliquity tides for body 2 and the ghost planets

- added a time lag obliquity tides subroutine obl_tides.for that is included within the spin subroutine to compute the tidal torques from the star at each time step, while a new subroutine mce_spin.for is included to update the planets' radii, J2 coefficients, and therefore moment of inertia components according to the reverse of the equations found in apppendix A of Lissauer et al. (2012), as their spin angular momentum evolves over time

- the big.in and small.in files no longer need to specify the body's J2 coefficent since that is now calculated internally based on the input mass, density, moment of inertia coefficient, and spin angular momentum within the mdt_spin.for subroutine

- the big.in and small.in files require the input of the body's tidal potential love number (k=) and time lag duration (t=) in the header if using time lag obliquity tides

- element6.for includes changes to output new relevent parameters of each body with key letters in element.in such as their radii (k), spin periods (s), moment of inertia coefficients (c), J2 coefficients (j), spin inclination (h), spin nodal angle (t), spin angular momentum components (sx,sy,sz) = (1,2,3), which requried a redone new mce_spin.for subroutine that recalculates what was calculated in the spin subroutine of smercury-T.for

The updated code letters are:
                              a = semi-major axis (AU)
                              b = apocentre distance (AU, b is short for Big q)
                              c = moment of inertia coefficient (C/MR^2)
                              d = density (g per cm^3)
                              e = eccentricity
                              f = true anomaly (degrees)
                              g = argument of perihelion (degrees)
                              h = spin vector inclination (degrees)
                              i = inclination (degrees)
                              j = J2 oblateness coefficient 
                              k = radius (km)
                              l = mean anomaly (degrees)
                              m = mass (solar masses)
                              n = longitude of ascending node (degrees)
                              o = obliquity (degrees)
                              p = longitude of perihelion (degrees)
                              q = pericentre distance (AU)
                              r = radial distance (AU)
                              s = spin period (days)
                              t = spin vector azimuth (degrees)
                              u, v or w = Cartesian velocities vx, vy or vz (AU/day)
                              x, y or z = Cartesian coordinates x, y or z (AU)
                              1, 2, or 3 = spin vector components sx, sy, or sz (solar masses AU^2 /day)

- smercury-T.for now includes a tidal tolerance scheme for the tidal time lag option. This scheme allows the user to specify a tolerance value in the param.in file which controls the frequency at which the tidal torques are added to the spin vector based on a comparision of the tidal torque magnitude to the spin vector magnitude, which in turn also controls how often the planet radius and moment of inertia tensor needs to be updated. 
