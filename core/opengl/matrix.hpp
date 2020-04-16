/*++ BUILD Version: 001		Increment the value of version if changing has global effect

Copyright (c) WalesDev. All rights reserved.

FILE: matrix.hpp
Realisation File: matrix.cpp

Description:
		When working with bitmap images, it is sometimes convenient to
		present a one-dimensional data array as two-dimensional. The Matrix
		class below allows you to select a rectangular block of elements for
		processing in such an array, and the elements can be arranged
		inconsistently.

++*/

#pragma once

#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <new>

namespace Oneness {
	class Matrix {
	private:
		int* xlen = (int*)operator new(sizeof(int)); // Width of the entire array
		int* sx = (int*)operator new(sizeof(int)); int* sy = (int*)operator new(sizeof(int)); // Scale factors for x and y
		// The upper left corner of the element block
		// without coefficients
		int* ox = (int*)operator new(sizeof(int)); int* oy = (int*)operator new(sizeof(int));
		int* index = (int*)operator new(sizeof(int)); // Current index

	public:
		Matrix(int xl, int ox = 0, int oy = 0, int sx = 1, int sy = 1);
		void init(int xl, int ox = 0, int oy = 0, int sx = 1, int sy = 1);
		int getIndex(int x, int y);
		void setIndex(int x, int y);
		void setOrg(int x, int y);
		void setScale(int sx, int sy);
		int operator ++(int i);
		operator int();
		~Matrix();
	};

	template <class Src, class Dst> void copy(int xl, int yl, Src src, Dst dst,
		Matrix& sind, Matrix& dind);

	template <class T, class Dst> void fill(T v, int xl, int yl, Dst dst, Matrix& dind);

	template <class T, class T1, class Dst> void for_each(T f, T1 arg, int xl,
		int yl, Dst dst, Matrix& dind);

	/*
	Accumulation of the results of some function.
	For example, when calculating the sum of works
	fa is the addition function, and f is the product function
	*/
	template <class T, class Tf, class Tfa, class Src>
	T accum(Tf f, Tfa fa, T init, int xl, int yl,
		Matrix& index1, Matrix& index2);
}

#endif // MATRIX_HPP
