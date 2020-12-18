//
// Created by Peter Westerstrom on 2020-12-18.
//

#ifndef SET_CROSS_H
#define SET_CROSS_H

#include <tuple>
#include <vector>

#include "pow_int.h"
#include "tuple_math.h"

namespace westerstrom
{
	namespace detail
	{
		// cross_imp(f, v...) means "do `f` for each element of cartesian product of v..."
		template <typename F> inline void cross_imp(F f)
		{
			f();
		}
		template <typename F, typename H, typename... Ts>
		inline void cross_imp(F f, std::vector<H> const& h, std::vector<Ts> const&... t)
		{
			for(H const& he : h)
				cross_imp([&](Ts const&... ts) { f(he, ts...); }, t...);
		}
	} // namespace detail

	/**
	 * Set cartesian product (x) of sets (vectors).
	 * Example: {1,2} x {a,b,c} = { (1,a),(1,b),(1,c),(2,a),(2,b),(2,c) }
	 * @return A vector of tuples<A,B..> representing the cartesian product set.
	 */
	template <typename... Ts> std::vector<std::tuple<Ts...>> set_cross(std::vector<Ts> const&... in)
	{
		std::vector<std::tuple<Ts...>> res;
		detail::cross_imp([&](Ts const&... ts) { res.emplace_back(ts...); }, in...);
		return res;
	}

} // namespace westerstrom

#endif // SET_CROSS_H
