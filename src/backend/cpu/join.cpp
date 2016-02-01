/*******************************************************
 * Copyright (c) 2014, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#include <Array.hpp>
#include <join.hpp>
#include <platform.hpp>
#include <queue.hpp>
#include <kernel/join.hpp>

namespace cpu
{

template<typename Tx, typename Ty>
Array<Tx> join(const int dim, const Array<Tx> &first, const Array<Ty> &second)
{
    first.eval();
    second.eval();

    // All dimensions except join dimension must be equal
    // Compute output dims
    af::dim4 odims;
    af::dim4 fdims = first.dims();
    af::dim4 sdims = second.dims();

    for(int i = 0; i < 4; i++) {
        if(i == dim) {
            odims[i] = fdims[i] + sdims[i];
        } else {
            odims[i] = fdims[i];
        }
    }

    Array<Tx> out = createEmptyArray<Tx>(odims);

    getQueue().enqueue(kernel::join<Tx, Ty>, out, dim, first, second);

    return out;
}

template<typename T>
Array<T> join(const int dim, const std::vector<Array<T>> &inputs)
{
    for (unsigned i=0; i<inputs.size(); ++i)
        inputs[i].eval();
    // All dimensions except join dimension must be equal
    // Compute output dims
    af::dim4 odims;
    const dim_t n_arrays = inputs.size();
    std::vector<af::dim4> idims(n_arrays);

    dim_t dim_size = 0;
    for(unsigned i = 0; i < idims.size(); i++) {
        idims[i] = inputs[i].dims();
        dim_size += idims[i][dim];
    }

    for(int i = 0; i < 4; i++) {
        if(i == dim) {
            odims[i] = dim_size;
        } else {
            odims[i] = idims[0][i];
        }
    }

    Array<T> out = createEmptyArray<T>(odims);

    switch(n_arrays) {
	case 1:
		getQueue().enqueue(kernel::join<T, 1>, dim, out, inputs);
		break;
	case 2:
		getQueue().enqueue(kernel::join<T, 2>, dim, out, inputs);
		break;
	case 3:
		getQueue().enqueue(kernel::join<T, 3>, dim, out, inputs);
		break;
	case 4:
		getQueue().enqueue(kernel::join<T, 4>, dim, out, inputs);
		break;
	case 5:
		getQueue().enqueue(kernel::join<T, 5>, dim, out, inputs);
		break;
	case 6:
		getQueue().enqueue(kernel::join<T, 6>, dim, out, inputs);
		break;
	case 7:
		getQueue().enqueue(kernel::join<T, 7>, dim, out, inputs);
		break;
	case 8:
		getQueue().enqueue(kernel::join<T, 8>, dim, out, inputs);
		break;
	case 9:
		getQueue().enqueue(kernel::join<T, 9>, dim, out, inputs);
		break;
	case 10:
		getQueue().enqueue(kernel::join<T, 10>, dim, out, inputs);
		break;
	case 11:
		getQueue().enqueue(kernel::join<T, 11>, dim, out, inputs);
		break;
	case 12:
		getQueue().enqueue(kernel::join<T, 12>, dim, out, inputs);
		break;
	case 13:
		getQueue().enqueue(kernel::join<T, 13>, dim, out, inputs);
		break;
	case 14:
		getQueue().enqueue(kernel::join<T, 14>, dim, out, inputs);
		break;
	case 15:
		getQueue().enqueue(kernel::join<T, 15>, dim, out, inputs);
		break;
	case 16:
		getQueue().enqueue(kernel::join<T, 16>, dim, out, inputs);
		break;
	case 17:
		getQueue().enqueue(kernel::join<T, 17>, dim, out, inputs);
		break;
	case 18:
		getQueue().enqueue(kernel::join<T, 18>, dim, out, inputs);
		break;
	case 19:
		getQueue().enqueue(kernel::join<T, 19>, dim, out, inputs);
		break;
	case 20:
		getQueue().enqueue(kernel::join<T, 20>, dim, out, inputs);
		break;
	case 21:
		getQueue().enqueue(kernel::join<T, 21>, dim, out, inputs);
		break;
	case 22:
		getQueue().enqueue(kernel::join<T, 22>, dim, out, inputs);
		break;
	case 23:
		getQueue().enqueue(kernel::join<T, 23>, dim, out, inputs);
		break;
	case 24:
		getQueue().enqueue(kernel::join<T, 24>, dim, out, inputs);
		break;
	case 25:
		getQueue().enqueue(kernel::join<T, 25>, dim, out, inputs);
		break;
	case 26:
		getQueue().enqueue(kernel::join<T, 26>, dim, out, inputs);
		break;
	case 27:
		getQueue().enqueue(kernel::join<T, 27>, dim, out, inputs);
		break;
	case 28:
		getQueue().enqueue(kernel::join<T, 28>, dim, out, inputs);
		break;
	case 29:
		getQueue().enqueue(kernel::join<T, 29>, dim, out, inputs);
		break;
	case 30:
		getQueue().enqueue(kernel::join<T, 30>, dim, out, inputs);
		break;
	case 31:
		getQueue().enqueue(kernel::join<T, 31>, dim, out, inputs);
		break;
	case 32:
		getQueue().enqueue(kernel::join<T, 32>, dim, out, inputs);
		break;
	case 33:
		getQueue().enqueue(kernel::join<T, 33>, dim, out, inputs);
		break;
	case 34:
		getQueue().enqueue(kernel::join<T, 34>, dim, out, inputs);
		break;
	case 35:
		getQueue().enqueue(kernel::join<T, 35>, dim, out, inputs);
		break;
	case 36:
		getQueue().enqueue(kernel::join<T, 36>, dim, out, inputs);
		break;
	case 37:
		getQueue().enqueue(kernel::join<T, 37>, dim, out, inputs);
		break;
	case 38:
		getQueue().enqueue(kernel::join<T, 38>, dim, out, inputs);
		break;
	case 39:
		getQueue().enqueue(kernel::join<T, 39>, dim, out, inputs);
		break;
	case 40:
		getQueue().enqueue(kernel::join<T, 40>, dim, out, inputs);
		break;
	case 41:
		getQueue().enqueue(kernel::join<T, 41>, dim, out, inputs);
		break;
	case 42:
		getQueue().enqueue(kernel::join<T, 42>, dim, out, inputs);
		break;
	case 43:
		getQueue().enqueue(kernel::join<T, 43>, dim, out, inputs);
		break;
	case 44:
		getQueue().enqueue(kernel::join<T, 44>, dim, out, inputs);
		break;
	case 45:
		getQueue().enqueue(kernel::join<T, 45>, dim, out, inputs);
		break;
	case 46:
		getQueue().enqueue(kernel::join<T, 46>, dim, out, inputs);
		break;
	case 47:
		getQueue().enqueue(kernel::join<T, 47>, dim, out, inputs);
		break;
	case 48:
		getQueue().enqueue(kernel::join<T, 48>, dim, out, inputs);
		break;
	case 49:
		getQueue().enqueue(kernel::join<T, 49>, dim, out, inputs);
		break;
	case 50:
		getQueue().enqueue(kernel::join<T, 50>, dim, out, inputs);
		break;
    }

    return out;
}

#define INSTANTIATE(Tx, Ty) \
    template Array<Tx> join<Tx, Ty>(const int dim, const Array<Tx> &first, const Array<Ty> &second);

INSTANTIATE(float,   float)
INSTANTIATE(double,  double)
INSTANTIATE(cfloat,  cfloat)
INSTANTIATE(cdouble, cdouble)
INSTANTIATE(int,     int)
INSTANTIATE(uint,    uint)
INSTANTIATE(intl,    intl)
INSTANTIATE(uintl,   uintl)
INSTANTIATE(uchar,   uchar)
INSTANTIATE(char,    char)
INSTANTIATE(ushort,  ushort)
INSTANTIATE(short,   short)

#undef INSTANTIATE

#define INSTANTIATE(T)      \
    template Array<T> join<T>(const int dim, const std::vector<Array<T>> &inputs);

INSTANTIATE(float)
INSTANTIATE(double)
INSTANTIATE(cfloat)
INSTANTIATE(cdouble)
INSTANTIATE(int)
INSTANTIATE(uint)
INSTANTIATE(intl)
INSTANTIATE(uintl)
INSTANTIATE(uchar)
INSTANTIATE(char)
INSTANTIATE(ushort)
INSTANTIATE(short)

#undef INSTANTIATE
}
