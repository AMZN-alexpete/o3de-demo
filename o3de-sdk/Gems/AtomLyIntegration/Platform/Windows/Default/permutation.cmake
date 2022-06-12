#
# Copyright (c) Contributors to the Open 3D Engine Project.
# For complete copyright and license terms please see the LICENSE at the root of this distribution.
#
# SPDX-License-Identifier: Apache-2.0 OR MIT
#
#

if(NOT TARGET AtomLyIntegration.Clients)
   ly_create_alias( NAME AtomLyIntegration.Clients NAMESPACE Gem TARGETS Gem::Atom_AtomBridge.Clients)
endif()
if(NOT TARGET AtomLyIntegration.Servers)
   ly_create_alias( NAME AtomLyIntegration.Servers NAMESPACE Gem TARGETS Gem::Atom_AtomBridge.Servers)
endif()
if(NOT TARGET AtomLyIntegration.Builders)
   ly_create_alias( NAME AtomLyIntegration.Builders NAMESPACE Gem TARGETS Gem::Atom_AtomBridge.Builders)
endif()
if(NOT TARGET AtomLyIntegration.Tools)
   ly_create_alias( NAME AtomLyIntegration.Tools NAMESPACE Gem TARGETS Gem::Atom_AtomBridge.Tools)
endif()
