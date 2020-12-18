//
// Created by Peter Westerstrom on 2020-12-18.
//

#ifndef POW_INT_H
#define POW_INT_H

#include <cstddef>

namespace westerstrom
{
	/**
	 * Pow with integer base and unsigned exponent.
	 * @tparam v Any non 0 integer
	 * @tparam n Unsigned small integer.
	 * @return v^n
	 */
	template <size_t v, size_t n> constexpr auto pow_int()
	{
		if constexpr(n == 0)
		{
			return 1;
		} else
		{
			return v * pow_int<v, n - 1>();
		}
	}
} // namespace westerstrom

#endif // POW_INT_H
