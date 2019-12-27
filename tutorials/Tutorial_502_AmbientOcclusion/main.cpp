/*
*	Copyright (C) 2015 by Liangliang Nan (liangliang.nan@gmail.com)
*	https://3d.bk.tudelft.nl/liangliang/
*
*	This file is part of Easy3D. If it is useful in your research/work,
*   I would be grateful if you show your appreciation by citing it:
*   ------------------------------------------------------------------
*           Liangliang Nan.
*           Easy3D: a lightweight, easy-to-use, and efficient C++
*           library for processing and rendering 3D data. 2018.
*   ------------------------------------------------------------------
*
*	Easy3D is free software; you can redistribute it and/or modify
*	it under the terms of the GNU General Public License Version 3
*	as published by the Free Software Foundation.
*
*	Easy3D is distributed in the hope that it will be useful,
*	but WITHOUT ANY WARRANTY; without even the implied warranty of
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*	GNU General Public License for more details.
*
*	You should have received a copy of the GNU General Public License
*	along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "ambient_occlusion.h"
#include <easy3d/viewer/model.h>
#include <easy3d/viewer/drawable_triangles.h>
#include <easy3d/viewer/setting.h>

using namespace easy3d;

// This example shows how to
//		- renders a surface mesh using ambient occlusion to improve depth perception.e.


int main(int /*argc*/, char** /*argv*/) {
    const std::string file = setting::resource_directory() + "/data/general.obj";

    try {
        // Create the viewer.
        TutorialAmbientOcclusion viewer("Tutorial_502_AmbientOcclusion");

        Model* model = viewer.open(file, true, false);
        if (!model) {
            std::cerr << "Error: failed to load model. Please make sure the file exists and format is correct." << std::endl;
            return EXIT_FAILURE;
        }
        auto drawable = model->triangles_drawable("surface");
        drawable->set_default_color(vec3(1.0f, 1.0f, 1.0f));

        // Run the viewer
        viewer.run();

        return EXIT_SUCCESS;
    } catch (const std::runtime_error &e) {
        const std::string error_msg = std::string("Caught a fatal error: ") + std::string(e.what());
        std::cerr << error_msg << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
