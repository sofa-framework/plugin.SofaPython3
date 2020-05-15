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
********************************************************************/

#include "Binding_BaseGui.h"

#include <sofa/gui/BaseGUI.h>

namespace py = pybind11;

namespace sofapython3 {
using sofa::gui::BaseGUI;
using sofa::simulation::Node;

void moduleAddBaseGui(py::module& m)
{
    py::class_<sofa::gui::BaseGUI, std::unique_ptr<sofa::gui::BaseGUI, py::nodelete>> baseGUI(m, "BaseGUI");

    /*
     * Sofa.Gui.BaseGUI.SetBackgroundImage
     */
    const auto SetBackgroundImageDoc = R"doc(
        Set the background image of the current GUI viewer with the given filepath.

        :param filename: Path to the image which will become the background of the viewer.
        :type filename: str
    )doc";
    baseGUI.def("setBackgroundImage", &sofa::gui::BaseGUI::setBackgroundImage, SetBackgroundImageDoc);

}

} // namespace sofapython3