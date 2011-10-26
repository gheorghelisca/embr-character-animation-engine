// Filename: atomicAdjustPosixImpl.h
// Created by:  drose (10Feb06)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) Carnegie Mellon University.  All rights reserved.
//
// All use of this software is subject to the terms of the revised BSD
// license.  You should have received a copy of this license along
// with this source code in a file named "LICENSE."
//
////////////////////////////////////////////////////////////////////

#ifndef ATOMICADJUSTPOSIXIMPL_H
#define ATOMICADJUSTPOSIXIMPL_H

#include "dtoolbase.h"
#include "selectThreadImpl.h"

#ifdef HAVE_POSIX_THREADS

#include "numeric_types.h"

#include <pthread.h>

////////////////////////////////////////////////////////////////////
//       Class : AtomicAdjustPosixImpl
// Description : Uses POSIX to implement atomic adjustments.
////////////////////////////////////////////////////////////////////
class EXPCL_DTOOL AtomicAdjustPosixImpl {
public:
  typedef int Integer;
  INLINE static void inc(TVOLATILE Integer &var);
  INLINE static bool dec(TVOLATILE Integer &var);
  INLINE static void add(TVOLATILE Integer &var, Integer delta);
  INLINE static Integer set(TVOLATILE Integer &var, Integer new_value);
  INLINE static Integer get(const TVOLATILE Integer &var);

  INLINE static void *set_ptr(void * TVOLATILE &var, void *new_value);
  INLINE static void *get_ptr(void * const TVOLATILE &var);

  INLINE static Integer compare_and_exchange(TVOLATILE Integer &mem, 
                                             Integer old_value,
                                             Integer new_value);

  INLINE static void *compare_and_exchange_ptr(void * TVOLATILE &mem, 
                                               void *old_value,
                                               void *new_value);

private:
  static pthread_mutex_t _mutex;
};

#include "atomicAdjustPosixImpl.I"

#endif  // HAVE_POSIX_THREADS

#endif
