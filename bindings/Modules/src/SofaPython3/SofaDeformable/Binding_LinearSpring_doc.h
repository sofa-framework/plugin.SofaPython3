/*********************************************************************
Copyright 2019, CNRS, University of Lille, INRIA

This file is part of sofaPython3

sofaPython3 is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

sofaPython3 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with sofaqtquick. If not, see <http://www.gnu.org/licenses/>.
*********************************************************************/

#pragma once

namespace sofapython3::doc::SofaDeformable {

static auto LinearSpringClass =
R"(
A LinearSpring between two objects, specified by indices on a topology.
)";

static auto LinearSpringInit =
R"(
Create a linear spring from indices and spring parameters.
:param index1: Index of the point on object 1.
:param index2: Index of the point on object 2.
:param springStiffness: Stiffnes k of the spring (f = -k*x -d*v)
:param dampingFactor: Damping factor d of the spring (f = -k*x -d*v)
:param restLength: Initial length of the spring, such that f = 0
:param elongationOnly: If set to true, no compression of the spring is possible (x < 0)
:param enabled: If set to false, no force will be calculated for this spring

:return: A linear spring of type Sofa.SofaDeformable.LinearSpring
)";

} // sofapython3::doc::SofaDeformable
