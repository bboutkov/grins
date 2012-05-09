//-----------------------------------------------------------------------bl-
//--------------------------------------------------------------------------
// 
// GRINS - General Reacting Incompressible Navier-Stokes 
//
// Copyright (C) 2010-2012 The PECOS Development Team
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the Version 2 GNU General
// Public License as published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this library; if not, write to the Free Software
// Foundation, Inc. 51 Franklin Street, Fifth Floor, Boston, MA
// 02110-1301 USA
//
//-----------------------------------------------------------------------el-
//
// $Id$
//
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
#ifndef HEAT_TRANSFER_BC_HANDLING_H
#define HEAT_TRANSFER_BC_HANDLING_H

//libMesh
#include "const_function.h"

//GRINS
#include "bc_handling_base.h"

namespace GRINS
{
  //! Base class for reading and handling boundary conditions for physics classes
  class HeatTransferBCHandling : public BCHandlingBase
  {
  public:
    
    HeatTransferBCHandling( std::string& physics_name );
    
    ~HeatTransferBCHandling();

    int string_to_int( const std::string& bc_type_in ) const;

    void init_bc_data( const GRINS::BoundaryID bc_id, 
			       const std::string& bc_id_string, 
			       const int bc_type, 
			       const GetPot& input );

    void init_dirichlet_bcs( libMesh::DofMap& dof_map ) const;

    
  private:

    HeatTransferBCHandling();

    std::string _physics_name;

    enum HT_BC_TYPES{ISOTHERMAL_WALL=0,
		     ADIABATIC_WALL,
		     PRESCRIBED_HEAT_FLUX,
		     GENERAL_HEAT_FLUX};

  };
}
#endif // HEAT_TRANSFER_BC_HANDLING_H
