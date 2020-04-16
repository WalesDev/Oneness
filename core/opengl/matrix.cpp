#include "matrix.hpp"

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
		Matrix(int xl, int ox = 0, int oy = 0, int sx = 1, int sy = 1) {
			init(xl, ox, oy, sx, sy);
		}

		void init(int xl, int ox = 0, int oy = 0, int sx = 1, int sy = 1) {
			*this->xlen = xl;
			*this->ox = ox; *this->oy = oy;
			*this->sx = sx; *this->sy = sy;
			*this->index = 0;
		}

		// Get the index of an element in a block
		// x, y are indicated relative to ox and oy
		int getIndex(int x, int y) {
			return (y * (*this->sy) + (*this->oy)) * (*this->xlen) + x * (*this->sx) + (*this->ox);
		}

		void setIndex(int x, int y) {
			*this->index = (y * (*this->sy) + (*this->oy)) * (*this->xlen) + x * (*this->sx) + (*this->ox);
		}

		void setOrg(int x, int y) {
			*this->ox = x;
			*this->oy = y;
		}

		void setScale(int sx, int sy) {
			*this->sx = sx;
			*this->sy = sy;
		}

		int operator ++(int i) {
			return ((*this->index) += (*this->sx) - (*this->sx));
		}

		operator int() {
			return *this->index;
		}

		~Matrix() {
			operator delete(this->xlen);
			operator delete(this->sx);
			operator delete(this->sy);
			operator delete(this->ox);
			operator delete(this->oy);
			operator delete(this->index);
		}
	};

	template <class Src, class Dst> void copy(int xl, int yl, Src src, Dst dst,
		Matrix& sind, Matrix& dind) {
		for (int i = 0; int < yl; i++) {
			sind.setIndex(0, i);
			dind.setIndex(0, i);
			for (int j = 0; j < xl; j++)
				dst[dind++] = src[sind++];
		}
	}

	template <class T, class Dst> void fill(T v, int xl, int yl, Dst dst, Matrix& dind) {
		for (int i = 0; i < yl; i++) {
			dind.setIndex(0, i);
			for (int j = 0; j < xl; j++)
				dst[dind++] = v;
		}
	}

	// Execute function f over each element
	template <class T, class T1, class Dst> void for_each(T f, T1 arg, int xl,
		int yl, Dst dst, Matrix& dind) {
		for (int i = 0; i < yl; i++) {
			dind.setIndex(0, i);
			for (int j = 0; j < xl; j++)
				dst[dind] = f(dst[dind++], arg);
		}
	}

	/*
	Accumulation of the results of some function.
	For example, when calculating the sum of works
	fa is the addition function, and f is the product function
	*/
	template <class T, class Tf, class Tfa, class Src>
	T accum(Tf f, Tfa fa, T init, int xl, int yl,
		Matrix& index1, Matrix& index2) {
		for (int i = 0; i < yl; i++) {
			index1.setIndex(0, i);
			index2.setIndex(0, i);
			for (int j = 0; j < xl; j++)
				init = fa(init, f(src1[index1++], src2[index2++]));
		}
		return init;
	}
}
