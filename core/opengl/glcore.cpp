#include "glcore.hpp"

namespace Oneness {
	template <class T, class T1, class T2> inline void minmax(T& src, T1 min, T2 max) {
		src = (src < mi) ? mi : ((src > ma) ? ma : src);
	}
}
