# Smercury-T
A work in progress to equip the smercury orbital integrator with tidal and general relativisitic effects.

This work will modify the existing spin-tracking orbital integration algorithm, smercury, which is based in the original mercury package developed by Chambers (1999). The modifications include the addition of general relativistic forces, solar gravitational tidal effects on planetary obliquity and rotation rate, and other quality of life improvements. 

Modifications so far:

- the param.in file now requires one of the following argument keywords to specify the spin-tracking algorithm: "spin", "Spin", "SPIN", "spn", or "SPN"

- following Bolmont et al. (2015), general relativisitic forces between the central body and each big body are now included if the user specifies "yes" to the user-defined routine option in the param.in file

- double precision has been added everywhere in the smercury-T.for and element6.for files

- fixed spin rate and pomega output for ghost planet .aei files, and the spin node longitude now outputs from 0 to 360 degrees rather than -180 to 180
