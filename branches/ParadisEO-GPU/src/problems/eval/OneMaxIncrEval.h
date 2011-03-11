/*
  <OneMaxIncrEval.h>
  Copyright (C) DOLPHIN Project-Team, INRIA Lille - Nord Europe, 2006-2010

  Karima Boufaras, Thé Van LUONG

  This software is governed by the CeCILL license under French law and
  abiding by the rules of distribution of free software.  You can  use,
  modify and/ or redistribute the software under the terms of the CeCILL
  license as circulated by CEA, CNRS and INRIA at the following URL
  "http://www.cecill.info".

  As a counterpart to the access to the source code and  rights to copy,
  modify and redistribute granted by the license, users are provided only
  with a limited warranty  and the software's author,  the holder of the
  economic rights,  and the successive licensors  have only  limited liability.

  In this respect, the user's attention is drawn to the risks associated
  with loading,  using,  modifying and/or developing or reproducing the
  software by the user in light of its specific status of free software,
  that may mean  that it is complicated to manipulate,  and  that  also
  therefore means  that it is reserved for developers  and  experienced
  professionals having in-depth computer knowledge. Users are therefore
  encouraged to load and test the software's suitability as regards their
  requirements in conditions enabling the security of their systems and/or
  data to be ensured and,  more generally, to use and operate it in the
  same conditions as regards security.
  The fact that you are presently reading this means that you have had
  knowledge of the CeCILL license and that you accept its terms.

  ParadisEO WebSite : http://paradiseo.gforge.inria.fr
  Contact: paradiseo-help@lists.gforge.inria.fr
*/

#ifndef __OneMaxIncrEval_H
#define __OneMaxIncrEval_H

#include <eval/moCudaEvalFunc.h>

/**
 * Incremental Evaluation of OneMax
 */

template<class Neighbor>
class OneMaxIncrEval: public moCudaEvalFunc<Neighbor> {

 public:

  typedef typename Neighbor::EOT EOT;
  typedef typename EOT::Fitness Fitness;

  /**
   * Constructor
   */

  OneMaxIncrEval() {
  }

  /**
   * Destructor
   */

  ~OneMaxIncrEval() {
  }

  /**
   * Incremental evaluation of the solution(function inline can be called from host or device)
   * @param _bitVector the solution to evaluate
   * @param _fitness the fitness of the current solution
   * @param _index the index of solution neighbor
   */

  inline __host__ __device__ Fitness operator() (EOT & _bitVector,Fitness _fitness, unsigned int * _index) {

    Fitness tmp;

    if (_bitVector[_index[0]] == 0)

      tmp= _fitness+1;

    else

      tmp= _fitness-1;

    return tmp;

  }
};

#endif