/*
  <moFirstImprExplorer.h>
  Copyright (C) DOLPHIN Project-Team, INRIA Lille - Nord Europe, 2006-2010

  Sébastien Verel, Arnaud Liefooghe, Jérémie Humeau

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

#ifndef _moFirstImprexplorer_h
#define _moFirstImprexplorer_h

#include <explorer/moNeighborhoodExplorer.h>
#include <comparator/moNeighborComparator.h>
#include <comparator/moSolNeighborComparator.h>

/**
 * Explorer for a first imporvement heuristic
 */
template< class Neighborhood >
class moFirstImprExplorer : public moNeighborhoodExplorer<Neighborhood>
{
public:
    typedef typename Neighborhood::EOT EOT ;
    typedef typename Neighborhood::Neighbor Neighbor ;

    using moNeighborhoodExplorer<Neighborhood>::neighborhood;
    using moNeighborhoodExplorer<Neighborhood>::eval;

    /**
     * Constructor
     * @param _neighborhood the neighborhood
     * @param _eval the evaluation function
     * @param _neighborComparator a neighbor comparator
     * @param _solNeighborComparator a solution vs neighbor comparator
     */
    moFirstImprExplorer(Neighborhood& _neighborhood, moEval<Neighbor>& _eval, moNeighborComparator<Neighbor>& _neighborComparator, moSolNeighborComparator<Neighbor>& _solNeighborComparator) : moNeighborhoodExplorer<Neighborhood>(_neighborhood, _eval), neighborComparator(_neighborComparator), solNeighborComparator(_solNeighborComparator) {
        isAccept = false;
        current=new Neighbor();
    }

    /**
     * Destructor
     */
    ~moFirstImprExplorer() {
        delete current;
    }

    /**
     * initParam: NOTHING TO DO
     */
    virtual void initParam(EOT & solution) {};

    /**
     * updateParam: NOTHING TO DO
     */
    virtual void updateParam(EOT & solution) {};

    /**
     * terminate: NOTHING TO DO
     */
    virtual void terminate(EOT & solution) {};

    /**
     * Explore the neighborhood of a solution
     * @param _solution
     */
    virtual void operator()(EOT & _solution) {

        //Test if _solution has a Neighbor
        if (neighborhood.hasNeighbor(_solution)) {
            //init the first neighbor
            neighborhood.init(_solution, (*current));

            //eval the _solution moved with the neighbor and stock the result in the neighbor
            eval(_solution, (*current));

            //test all others neighbors
            while (! solNeighborComparator(_solution, *current) && neighborhood.cont(_solution)) {
                //next neighbor
                neighborhood.next(_solution, (*current));
                //eval
                eval(_solution, (*current));
            }
        }
        else {
            //if _solution hasn't neighbor,
            isAccept=false;
        }
    };

    /**
     * continue if a move is accepted
     * @param _solution the solution
     * @return true if an ameliorated neighbor was be found
     */
    virtual bool isContinue(EOT & _solution) {
        return isAccept ;
    };

    /**
     * move the solution with the best neighbor
     * @param _solution the solution to move
     */
    virtual void move(EOT & _solution) {
        //move the solution
        (*current).move(_solution);
        //update its fitness
        _solution.fitness((*current).fitness());
    };

    /**
     * accept test if an amelirated neighbor was be found
     * @param _solution the solution
     * @return true if the best neighbor ameliorate the fitness
     */
    virtual bool accept(EOT & _solution) {
        if (neighborhood.hasNeighbor(_solution)) {
            isAccept = solNeighborComparator(_solution, (*current)) ;
        }
        return isAccept;
    };

private:
    // comparator betwenn solution and neighbor or between neighbors
    moNeighborComparator<Neighbor>& neighborComparator;
    moSolNeighborComparator<Neighbor>& solNeighborComparator;

    //Pointer on the best and the current neighbor
    Neighbor* current;

    // true if the move is accepted
    bool isAccept ;
};


#endif
