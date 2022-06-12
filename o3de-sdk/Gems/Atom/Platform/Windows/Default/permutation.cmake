#
# Copyright (c) Contributors to the Open 3D Engine Project.
# For complete copyright and license terms please see the LICENSE at the root of this distribution.
#
# SPDX-License-Identifier: Apache-2.0 OR MIT
#
#

if(NOT TARGET Atom.Clients)
   ly_create_alias( NAME Atom.Clients NAMESPACE Gem TARGETS Gem::Atom_AtomBridge.Clients)
endif()
if(NOT TARGET Atom.Servers)
   ly_create_alias( NAME Atom.Servers NAMESPACE Gem TARGETS Gem::Atom_AtomBridge.Servers)
endif()
if(NOT TARGET Atom.Builders)
   ly_create_alias( NAME Atom.Builders NAMESPACE Gem TARGETS Gem::Atom_AtomBridge.Builders)
endif()
if(NOT TARGET Atom.Tools)
   ly_create_alias( NAME Atom.Tools NAMESPACE Gem TARGETS Gem::Atom_AtomBridge.Tools)
endif()
