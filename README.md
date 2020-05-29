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

- element6.for includes changes to output new relevent parameters of each body with key letters in element.in such as their radii (k), spin periods (s), moment of inertia coefficents (j), J2 coefficients (1), tidal potential love numbers (2), and time lag durations (3), which requried a redone new mce_spin.for subroutine that recalculates what was calculated in the spin subroutine of smercury-T.for
