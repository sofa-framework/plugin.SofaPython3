
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

#include <vector>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/cast.h>

#include <SofaDeformable/SpringForceField.h>
#include <sofa/defaulttype/VecTypes.h>

#include <SofaPython3/SofaDeformable/Binding_SpringForceField.h>
#include <SofaPython3/SofaDeformable/Binding_SpringForceField_doc.h>

#include <SofaPython3/Sofa/Core/Binding_Base.h>
#include <SofaPython3/PythonFactory.h>


namespace sofapython3 {

namespace py { using namespace pybind11; }

template<class DataType>
void bindSpringForcefield(py::module& m) {
    // template the SpringForceField to use it with different types of MechanicalStates such as Vec3 or Rigid3
    using SpringForceField = sofa::component::interactionforcefield::SpringForceField<DataType>;

    using sofa::component::interactionforcefield::LinearSpring;
    typedef LinearSpring<SReal> LinearSpringR;

    // create a python binding for the c++ class SpringForceField from SofaDeformable
    // no init binding, because creation should be done via node.addObject("SpringForceField")
    std::string type_name = sofa::helper::NameDecoder::getTypeName<SpringForceField>();
    py::class_<SpringForceField,
            sofa::core::objectmodel::BaseObject,
            py_shared_ptr<SpringForceField>> s (m, type_name.c_str(), sofapython3::doc::SofaDeformable::SpringForceFieldClass);

    // remove all springs and optionally reserve memory for #reserve springs in the vector of springs
    s.def("clear", &SpringForceField::clear, py::arg("reserve") = 0, sofapython3::doc::SofaDeformable::SpringForceFieldClear);

    // directly binding this one with &SpringForceField::getSprings returns a vector including CPUMemoryManager
    s.def("getSprings", [](const SpringForceField& self){
        std::vector<LinearSpringR> springs = self.getSprings();
        return springs;
    }, sofapython3::doc::SofaDeformable::SpringForceFieldGetSprings);

    // remove the nth spring
    s.def("removeSpring", &SpringForceField::removeSpring, py::arg("index"), sofapython3::doc::SofaDeformable::SpringForceFieldRemoveSpring);

    // remove springs specified by a list of indices
    s.def("removeSprings", [](SpringForceField& self, const std::vector<int> &v){
                for (const auto index: v){
                    self.removeSpring(index);
                }
            },
            py::arg("indices"), sofapython3::doc::SofaDeformable::SpringForceFieldRemoveSprings);

    // add spring form a LinearSpringR
    s.def("addSpring", py::overload_cast<const LinearSpringR &>(&SpringForceField::addSpring), py::arg("spring"), sofapython3::doc::SofaDeformable::SpringForceFieldAddSpring);

    // add spring from construtor arguments for a LinearSpringR
    s.def("addSpring", py::overload_cast<sofa::Index, sofa::Index, SReal, SReal, SReal>(&SpringForceField::addSpring),
            py::arg("index1"),
            py::arg("index2"),
            py::arg("springStiffness"),
            py::arg("dampingFactor"),
            py::arg("restLength"),
            sofapython3::doc::SofaDeformable::SpringForceFieldAddSpring);

    // add multiple springs at once
    s.def("addSprings", [](SpringForceField& self, const std::vector<LinearSpringR> &v){
                for (const auto spring: v){
                    self.addSpring(spring);
                }
            },
            py::arg("springs"), sofapython3::doc::SofaDeformable::SpringForceFieldAddSprings);


    // register the binding in the downcasting subsystem
    PythonFactory::registerType<SpringForceField>([](sofa::core::objectmodel::Base* object){
        return py::cast(dynamic_cast<SpringForceField*>(object));
    });
}

void moduleAddSpringForceField(py::module& m) {
    bindSpringForcefield<sofa::defaulttype::Vec3dTypes>(m);
    bindSpringForcefield<sofa::defaulttype::Vec6dTypes>(m);
}
} // namespace sofapython3
