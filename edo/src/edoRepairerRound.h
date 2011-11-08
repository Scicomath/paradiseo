/*
The Evolving Distribution Objects framework (EDO) is a template-based,
ANSI-C++ evolutionary computation library which helps you to write your
own estimation of distribution algorithms.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

Copyright (C) 2011 Thales group
*/
/*
Authors:
    Johann Dréo <johann.dreo@thalesgroup.com>
    Pierre Savéant <pierre.saveant@thalesgroup.com>
*/

#ifndef _edoRepairerRound_h
#define _edoRepairerRound_h

#include <cmath>

#include "edoRepairerApply.h"

/** A repairer that calls "floor" on each items of a solution
 *
 * Just a proxy to "edoRepairerApplyUnary<EOT, EOT::AtomType(EOT::AtomType)> rep( std::floor);"
 *
 * @ingroup Repairers
 */
template < typename EOT >
class edoRepairerFloor : public edoRepairerApplyUnary<EOT>
{
public:
    edoRepairerFloor() : edoRepairerApplyUnary<EOT>( std::floor ) {}
};

/** A repairer that calls "ceil" on each items of a solution
 *
 * @see edoRepairerFloor
 *
 * @ingroup Repairers
 */
template < typename EOT >
class edoRepairerCeil : public edoRepairerApplyUnary<EOT>
{
public:
    edoRepairerCeil() : edoRepairerApplyUnary<EOT>( std::ceil ) {}
};


#endif // !_edoRepairerRound_h
