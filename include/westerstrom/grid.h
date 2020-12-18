//
// Created by Peter Westerstrom on 2020-12-18.
//

#ifndef GRID_H
#define GRID_H

#include <tuple>
#include <vector>

#include "pow_int.h"
#include "tuple_math.h"
#include <numeric>

namespace westerstrom
{
	namespace detail
	{
		template <size_t i, typename T> auto neighbors_impl(std::vector<T>& v)
		{
			constexpr auto N = std::tuple_size_v<T>;
			if constexpr(i == 0)
			{
				for(int x = -1; x <= 1; ++x)
				{
					T y;
					std::get<0>(y) = x;
					v.push_back(y);
				}
				neighbors_impl<i + 1>(v);
			} else if constexpr(i < N)
			{
				auto v2 = v;
				v.clear();
				for(int x = -1; x <= 1; ++x)
				{
					auto v3 = v2;
					for(auto& y : v3)
					{
						std::get<i>(y) = x;
					}
					std::copy(std::begin(v3), std::end(v3), std::back_inserter(v));
				}
				neighbors_impl<i + 1>(v);
			} else
			{
				return;
			}
		}
	} // namespace detail

	template <typename T> auto neighbors()
	{
		std::vector<T> v;
		detail::neighbors_impl<0, T>(v);
		constexpr auto N = std::tuple_size_v<T>;
		constexpr auto num = pow_int<3, N>();
		constexpr auto zeroIndex = ((num)-1) / 2;
		v.erase(std::begin(v) + zeroIndex);
		return v;
	}

	template <typename T> auto neighbors(T p)
	{
		auto v = neighbors<T>();
		std::transform(std::begin(v), std::end(v), std::begin(v),
		               [p](auto v) { return add(p, v); });
		return v;
	}

} // namespace westerstrom
#endif // GRID_H
