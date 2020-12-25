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
/********************************************************************
 Contributors:
    - damien.marchal@univ-lille.fr
    - bruno.josue.marques@inria.fr
    - eve.le-guillou@centrale.centralelille.fr
    - jean-nicolas.brunet@inria.fr
    - thierry.gaugry@inria.fr
    - paul.scheikl@kit.edu
********************************************************************/

#include <pybind11/pybind11.h>
#include "Binding_LinearSpring.h"
#include "Binding_LinearSpring_doc.h"

#include <SofaDeformable/config.h>
#include <SofaDeformable/SpringForceField.h>

#include <SofaPython3/Sofa/Core/Binding_Base.h>


namespace sofapython3 {

using sofa::component::interactionforcefield::LinearSpring;
typedef LinearSpring<SReal> LinearSpringR;

namespace py { using namespace pybind11; }

void moduleAddLinearSpring(pybind11::module& m) {
    // Create a python binding for the C++ class LinearSpring from SofaDeformable
    py::class_<LinearSpringR> s (m, "LinearSpring", sofapython3::doc::SofaDeformable::LinearSpringClass);

    // Initializer for the class
    s.def(py::init<sofa::Index,
                   sofa::Index,
                   SReal,
                   SReal,
                   SReal,
                   bool,
                   bool>(),
                   py::arg("index1"),
                   py::arg("index2"),
                   py::arg("springStiffness"),
                   py::arg("dampingFactor"),
                   py::arg("restLength"),
                   py::arg("elongationOnly"),
                   py::arg("enabled"));

    // Make class fields accessible from python (e.g. spring.restLength = 10)
    s.def_readwrite("index1", &LinearSpringR::m1);
    s.def_readwrite("index2", &LinearSpringR::m2);
    s.def_readwrite("springStiffness", &LinearSpringR::ks);
    s.def_readwrite("dampingFactor", &LinearSpringR::kd);
    s.def_readwrite("restLength", &LinearSpringR::initpos);
    s.def_readwrite("elongationOnly", &LinearSpringR::elongationOnly);
    s.def_readwrite("enabled", &LinearSpringR::enabled);

}

} // namespace sofapython3
