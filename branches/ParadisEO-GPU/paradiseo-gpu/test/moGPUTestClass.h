/*
 <moTestClass.h>
 Copyright (C) DOLPHIN Project-Team, INRIA Lille - Nord Europe, 2006-2012

 Karima Boufaras, Thé van Luong

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

#ifndef _moGPUTestClass_h
#define _moGPUTestClass_h

#include <moTestClass.h>
#include <neighborhood/moGPUXChangeNeighbor.h>

template<class EOT>
class XChangeNeighborDummy: public moGPUXChangeNeighbor<EOT> {
public:

	XChangeNeighborDummy() :
		moGPUXChangeNeighbor<EOT> () {

	}

	/**
	 * Constructor
	 * @param _xChange the number of x-change to do
	 */

	XChangeNeighborDummy(unsigned int _xChange) :
		moGPUXChangeNeighbor<EOT> (_xChange) {
	}
	/**
	 * Move a solution
	 * @param _solution the related solution
	 */
	void move(EOT & _solution) {

	}
};

#endif