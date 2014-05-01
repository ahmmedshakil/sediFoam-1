/* ----------------------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

/*
   C or Fortran style library interface to LAMMPS
   new LAMMPS-specific functions can be added
*/

#include "mpi.h"
#include "stdio.h"
/* ifdef allow this file to be included in a C program */

#ifdef __cplusplus
extern "C" {
#endif

  void lammps_open(int, char **, MPI_Comm, void **);  /* start-up LAMMPS */
  void lammps_close(void *);                          /* shut-down LAMMPS */
  void lammps_file(void *, char *);                 /* run input script */
  char *lammps_command(void *, char *);             /* execute a command */

  void lammps_sync(void *ptr);
  int lammps_get_natoms(void *);              /* return # of atoms */

  /* get atom x&v for all procs */
  void lammps_get_coord_velo(void *ptr, double *coords, double *velos);
  /* get atom x&v&d & rho & type */
  void lammps_get_info(void *ptr, double *coords, double *velos,
                       double *diam, double* rho_, int* tag_, int* type_);
  /* set atom x&v for all procs */
  void lammps_put_drag(void *ptr, double *fdrag);
  void lammps_step(void *ptr, int n);
  void lammps_set_timestep(void *ptr, double dt_i);
  double lammps_get_timestep(void *ptr);
#ifdef __cplusplus
}
#endif
