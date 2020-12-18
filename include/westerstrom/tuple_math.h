//
// Created by Peter Westerstrom on 2020-12-18.
//

#ifndef TUPLE_MATH_H
#define TUPLE_MATH_H

#include <cstddef>
#include <tuple>

namespace westerstrom
{
	namespace detail
	{
		template <size_t i, typename T> constexpr void add_impl(T& a, const T& b)
		{
			constexpr auto N = std::tuple_size_v<T>;
			if constexpr(i < N)
			{
				std::get<i>(a) += std::get<i>(b);
				add_impl<i + 1>(a, b);
			}
		}
	} // namespace detail

	template <typename T> constexpr auto add(T a, const T& b)
	{
		detail::add_impl<0, T>(a, b);
		return a;
	}

	template <typename T> constexpr auto operator+(T a, const T& b)
	{
		return add(a, b);
	}

	template <typename T> constexpr auto& operator+=(T& a, const T& b)
	{
		detail::add_impl<0, T>(a, b);
		return a;
	}
} // namespace westerstrom
#endif // TUPLE_MATH_H
