/*****************************************************************************
 *   GATB : Genome Assembly Tool Box
 *   Copyright (C) 2014  INRIA
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#ifndef _TOOL_SRC_linker_ram_HPP_
#define _TOOL_SRC_linker_ram_HPP_

/********************************************************************************/
#include <gatb/gatb_core.hpp>
#include "../../../thirdparty/IteratorKmerH5/IteratorKmerH5.hpp"
#include "../../../thirdparty/quasi_dictionary/src/quasidictionary.h"
#include "common.hpp"
/********************************************************************************/

////////////////////////////////////////////////////////////////////////////////
//
// THIS FILE IS AUTOMATICALLY GENERATED...
//
// THIS IS A SIMPLE EXAMPLE HOW TO USE THE Tool CLASS. IF YOU WANT MORE FEATURES,
// YOU CAN HAVE A LOOK AT THE ToyTool SNIPPET HERE:
//
//      http://gatb-core.gforge.inria.fr/snippets_tools.html
//
////////////////////////////////////////////////////////////////////////////////

class SRC_linker_ram : public Tool
{
	
private:
	quasidictionaryVectorKeyGeneric <IteratorKmerH5Wrapper, u_int32_t > quasiDico;
	u_int64_t nbSolidKmers;
    int gamma_value;
	int kmer_size;
	static const size_t span = KMER_SPAN(1);

public:

    // Constructor
	SRC_linker_ram ();

    // Actual job done by the tool is here
    void execute ();

    void create_quasi_dictionary(int fingerprint_size, int nbCores);

    void fill_quasi_dictionary(const int nbCores);

    void parse_query_sequences(int threshold, const int nbCores);
};

/********************************************************************************/

#endif /* _TOOL_SRC_linker_ram_HPP_ */
