/*++ BUILD Version: 001		Increment the value of version if changing has global effect

Copyright (c) WalesDev. All rights reserved.

FILE: glcore.hpp
Realisation File: glcore.cpp

Description: 
		Contains declarations of included files.

++*/

#pragma once

#ifndef GLCORE_HPP
#define GLCORE_HPP
#ifndef CALLBACK
#define CALLBACK __stdcall
#endif // CALLBACK
#include <glew.h>
#include <glfw3.h>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <numeric>
#include <vector>

namespace Oneness {
	template <class T, class T1, class T2> inline void minmax(T& src, T1 min, T2 max);
}

#include "input.hpp"
#include "vertex.hpp"
#include "matrix.hpp"
#include "camera.hpp"
#include "TransformationMatrix.hpp"
#include "ControlOpengl.hpp"
#include "ModelsClass.hpp"
#include "ImageControl.hpp"
#include "ImageProcessing.hpp"
#include "FractalsAlgorithms.hpp"

#endif // GLCORE_HPP
