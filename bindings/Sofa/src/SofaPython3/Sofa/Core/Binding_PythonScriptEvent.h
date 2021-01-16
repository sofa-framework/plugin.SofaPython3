/******************************************************************************
*                              SofaPython3 plugin                             *
*                  (c) 2019 CNRS, University of Lille, INRIA                  *
*                                                                             *
* This program is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This program is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this program. If not, see <http://www.gnu.org/licenses/>.        *
*******************************************************************************
* Authors: see Authors.txt                                                    *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
/********************************************************************
 Contributors:
    - damien.marchal@univ-lille.fr
    - bruno.josue.marques@inria.fr
    - eve.le-guillou@centrale.centralelille.fr
    - jean-nicolas.brunet@inria.fr
    - thierry.gaugry@inria.fr
********************************************************************/

#pragma once

#include <pybind11/pybind11.h>
#include <sofa/core/objectmodel/ScriptEvent.h>

#include <SofaPython3/config.h>

namespace sofapython3
{

class PythonScriptEvent : public sofa::core::objectmodel::ScriptEvent
{
    SOFA_EVENT_H(PythonScriptEvent)
public:
    PythonScriptEvent(sofa::simulation::Node::SPtr sender, const char* eventName, pybind11::object userData=pybind11::none());
    ~PythonScriptEvent() override;
    pybind11::object getUserData() const { return m_userData; }
    inline static const char* GetClassName() { return "PythonScriptEvent"; }

private:
    pybind11::object m_userData;
};

void moduleAddPythonScriptEvent();

} // namespace objectmodel
