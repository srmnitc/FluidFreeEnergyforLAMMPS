/* -*- c++ -*- ----------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------
   Contributing author:
   fscale variable (which multiplies only the forces) was added in the extract()
   method by Rodolfo Paula Leite (Unicamp/BR).
------------------------------------------------------------------------- */

#ifdef ANGLE_CLASS

AngleStyle(harmonic,AngleHarmonic)

#else

#ifndef LMP_ANGLE_HARMONIC_H
#define LMP_ANGLE_HARMONIC_H

#include <cstdio>
#include "angle.h"

namespace LAMMPS_NS {

class AngleHarmonic : public Angle {
 public:
  AngleHarmonic(class LAMMPS *);
  virtual ~AngleHarmonic();
  virtual void compute(int, int);
  virtual void coeff(int, char **);
  double equilibrium_angle(int);
  void write_restart(FILE *);
  virtual void read_restart(FILE *);
  void write_data(FILE *);
  double single(int, int, int, int);
  virtual void *extract(char *, int &);

 protected:
  double *k,*theta0;
  double *fscale;
  virtual void allocate();
};

}

#endif
#endif

/* ERROR/WARNING messages:

E: Incorrect args for angle coefficients

Self-explanatory.  Check the input script or data file.

*/