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
#include <kernel/join.hpp>
#include <stdexcept>
#include <err_cuda.hpp>

namespace cuda
{
    template<int dim>
    af::dim4 calcOffset(const af::dim4 dims)
    {
        af::dim4 offset;
        offset[0] = (dim == 0) ? dims[0] : 0;
        offset[1] = (dim == 1) ? dims[1] : 0;
        offset[2] = (dim == 2) ? dims[2] : 0;
        offset[3] = (dim == 3) ? dims[3] : 0;
        return offset;
    }

    template<typename Tx, typename Ty>
    Array<Tx> join(const int dim, const Array<Tx> &first, const Array<Ty> &second)
    {
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

        af::dim4 zero(0,0,0,0);

        switch(dim) {
            case 0:
                kernel::join<Tx, Tx, 0>(out, first,  zero);
                kernel::join<Tx, Ty, 0>(out, second, calcOffset<0>(fdims));
                break;
            case 1:
                kernel::join<Tx, Tx, 1>(out, first,  zero);
                kernel::join<Tx, Ty, 1>(out, second, calcOffset<1>(fdims));
                break;
            case 2:
                kernel::join<Tx, Tx, 2>(out, first,  zero);
                kernel::join<Tx, Ty, 2>(out, second, calcOffset<2>(fdims));
                break;
            case 3:
                kernel::join<Tx, Tx, 3>(out, first,  zero);
                kernel::join<Tx, Ty, 3>(out, second, calcOffset<3>(fdims));
                break;
        }

        return out;
    }

    template<typename T, int n_arrays>
    void join_wrapper(const int dim, Array<T> &out, const std::vector<Array<T> > &inputs)
    {
        af::dim4 zero(0,0,0,0);
        af::dim4 d = zero;

        switch(dim) {
            case 0:
                kernel::join<T, T, 0>(out, inputs[0], zero);
                for(int i = 1; i < n_arrays; i++) {
                    d += inputs[i - 1].dims();
                    kernel::join<T, T, 0>(out, inputs[i], calcOffset<0>(d));
                }
                break;
            case 1:
                kernel::join<T, T, 1>(out, inputs[0], zero);
                for(int i = 1; i < n_arrays; i++) {
                    d += inputs[i - 1].dims();
                    kernel::join<T, T, 1>(out, inputs[i], calcOffset<1>(d));
                }
                break;
            case 2:
                kernel::join<T, T, 1>(out, inputs[0], zero);
                for(int i = 1; i < n_arrays; i++) {
                    d += inputs[i - 1].dims();
                    kernel::join<T, T, 2>(out, inputs[i], calcOffset<2>(d));
                }
                break;
            case 3:
                kernel::join<T, T, 3>(out, inputs[0], zero);
                for(int i = 1; i < n_arrays; i++) {
                    d += inputs[i - 1].dims();
                    kernel::join<T, T, 3>(out, inputs[i], calcOffset<3>(d));
                }
                break;
        }
    }

    template<typename T>
    Array<T> join(const int dim, const std::vector<Array<T> > &inputs)
    {
        // All dimensions except join dimension must be equal
        // Compute output dims
        af::dim4 odims;
        const dim_t n_arrays = inputs.size();
        std::vector<af::dim4> idims(n_arrays);

        dim_t dim_size = 0;
        for(int i = 0; i < (int)idims.size(); i++) {
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
                join_wrapper<T, 1>(dim, out, inputs);
                break;
            case 2:
                join_wrapper<T, 2>(dim, out, inputs);
                break;
            case 3:
                join_wrapper<T, 3>(dim, out, inputs);
                break;
            case 4:
                join_wrapper<T, 4>(dim, out, inputs);
                break;
            case 5:
                join_wrapper<T, 5>(dim, out, inputs);
                break;
            case 6:
                join_wrapper<T, 6>(dim, out, inputs);
                break;
            case 7:
                join_wrapper<T, 7>(dim, out, inputs);
                break;
            case 8:
                join_wrapper<T, 8>(dim, out, inputs);
                break;
            case 9:
                join_wrapper<T, 9>(dim, out, inputs);
                break;
            case 10:
                join_wrapper<T,10>(dim, out, inputs);
                break;
			case 11:
				join_wrapper<T, 11>(dim, out, inputs);
				break;
			case 12:
				join_wrapper<T, 12>(dim, out, inputs);
				break;
			case 13:
				join_wrapper<T, 13>(dim, out, inputs);
				break;
			case 14:
				join_wrapper<T, 14>(dim, out, inputs);
				break;
			case 15:
				join_wrapper<T, 15>(dim, out, inputs);
				break;
			case 16:
				join_wrapper<T, 16>(dim, out, inputs);
				break;
			case 17:
				join_wrapper<T, 17>(dim, out, inputs);
				break;
			case 18:
				join_wrapper<T, 18>(dim, out, inputs);
				break;
			case 19:
				join_wrapper<T, 19>(dim, out, inputs);
				break;
			case 20:
				join_wrapper<T, 20>(dim, out, inputs);
				break;
			case 21:
				join_wrapper<T, 21>(dim, out, inputs);
				break;
			case 22:
				join_wrapper<T, 22>(dim, out, inputs);
				break;
			case 23:
				join_wrapper<T, 23>(dim, out, inputs);
				break;
			case 24:
				join_wrapper<T, 24>(dim, out, inputs);
				break;
			case 25:
				join_wrapper<T, 25>(dim, out, inputs);
				break;
			case 26:
				join_wrapper<T, 26>(dim, out, inputs);
				break;
			case 27:
				join_wrapper<T, 27>(dim, out, inputs);
				break;
			case 28:
				join_wrapper<T, 28>(dim, out, inputs);
				break;
			case 29:
				join_wrapper<T, 29>(dim, out, inputs);
				break;
			case 30:
				join_wrapper<T, 30>(dim, out, inputs);
				break;
			case 31:
				join_wrapper<T, 31>(dim, out, inputs);
				break;
			case 32:
				join_wrapper<T, 32>(dim, out, inputs);
				break;
			case 33:
				join_wrapper<T, 33>(dim, out, inputs);
				break;
			case 34:
				join_wrapper<T, 34>(dim, out, inputs);
				break;
			case 35:
				join_wrapper<T, 35>(dim, out, inputs);
				break;
			case 36:
				join_wrapper<T, 36>(dim, out, inputs);
				break;
			case 37:
				join_wrapper<T, 37>(dim, out, inputs);
				break;
			case 38:
				join_wrapper<T, 38>(dim, out, inputs);
				break;
			case 39:
				join_wrapper<T, 39>(dim, out, inputs);
				break;
			case 40:
				join_wrapper<T, 40>(dim, out, inputs);
				break;
			case 41:
				join_wrapper<T, 41>(dim, out, inputs);
				break;
			case 42:
				join_wrapper<T, 42>(dim, out, inputs);
				break;
			case 43:
				join_wrapper<T, 43>(dim, out, inputs);
				break;
			case 44:
				join_wrapper<T, 44>(dim, out, inputs);
				break;
			case 45:
				join_wrapper<T, 45>(dim, out, inputs);
				break;
			case 46:
				join_wrapper<T, 46>(dim, out, inputs);
				break;
			case 47:
				join_wrapper<T, 47>(dim, out, inputs);
				break;
			case 48:
				join_wrapper<T, 48>(dim, out, inputs);
				break;
			case 49:
				join_wrapper<T, 49>(dim, out, inputs);
				break;
			case 50:
				join_wrapper<T, 50>(dim, out, inputs);
				break;
			case 51:
				join_wrapper<T, 51>(dim, out, inputs);
				break;
			case 52:
				join_wrapper<T, 52>(dim, out, inputs);
				break;
			case 53:
				join_wrapper<T, 53>(dim, out, inputs);
				break;
			case 54:
				join_wrapper<T, 54>(dim, out, inputs);
				break;
			case 55:
				join_wrapper<T, 55>(dim, out, inputs);
				break;
			case 56:
				join_wrapper<T, 56>(dim, out, inputs);
				break;
			case 57:
				join_wrapper<T, 57>(dim, out, inputs);
				break;
			case 58:
				join_wrapper<T, 58>(dim, out, inputs);
				break;
			case 59:
				join_wrapper<T, 59>(dim, out, inputs);
				break;
			case 60:
				join_wrapper<T, 60>(dim, out, inputs);
				break;
			case 61:
				join_wrapper<T, 61>(dim, out, inputs);
				break;
			case 62:
				join_wrapper<T, 62>(dim, out, inputs);
				break;
			case 63:
				join_wrapper<T, 63>(dim, out, inputs);
				break;
			case 64:
				join_wrapper<T, 64>(dim, out, inputs);
				break;
			case 65:
				join_wrapper<T, 65>(dim, out, inputs);
				break;
			case 66:
				join_wrapper<T, 66>(dim, out, inputs);
				break;
			case 67:
				join_wrapper<T, 67>(dim, out, inputs);
				break;
			case 68:
				join_wrapper<T, 68>(dim, out, inputs);
				break;
			case 69:
				join_wrapper<T, 69>(dim, out, inputs);
				break;
			case 70:
				join_wrapper<T, 70>(dim, out, inputs);
				break;
			case 71:
				join_wrapper<T, 71>(dim, out, inputs);
				break;
			case 72:
				join_wrapper<T, 72>(dim, out, inputs);
				break;
			case 73:
				join_wrapper<T, 73>(dim, out, inputs);
				break;
			case 74:
				join_wrapper<T, 74>(dim, out, inputs);
				break;
			case 75:
				join_wrapper<T, 75>(dim, out, inputs);
				break;
			case 76:
				join_wrapper<T, 76>(dim, out, inputs);
				break;
			case 77:
				join_wrapper<T, 77>(dim, out, inputs);
				break;
			case 78:
				join_wrapper<T, 78>(dim, out, inputs);
				break;
			case 79:
				join_wrapper<T, 79>(dim, out, inputs);
				break;
			case 80:
				join_wrapper<T, 80>(dim, out, inputs);
				break;
			case 81:
				join_wrapper<T, 81>(dim, out, inputs);
				break;
			case 82:
				join_wrapper<T, 82>(dim, out, inputs);
				break;
			case 83:
				join_wrapper<T, 83>(dim, out, inputs);
				break;
			case 84:
				join_wrapper<T, 84>(dim, out, inputs);
				break;
			case 85:
				join_wrapper<T, 85>(dim, out, inputs);
				break;
			case 86:
				join_wrapper<T, 86>(dim, out, inputs);
				break;
			case 87:
				join_wrapper<T, 87>(dim, out, inputs);
				break;
			case 88:
				join_wrapper<T, 88>(dim, out, inputs);
				break;
			case 89:
				join_wrapper<T, 89>(dim, out, inputs);
				break;
			case 90:
				join_wrapper<T, 90>(dim, out, inputs);
				break;
			case 91:
				join_wrapper<T, 91>(dim, out, inputs);
				break;
			case 92:
				join_wrapper<T, 92>(dim, out, inputs);
				break;
			case 93:
				join_wrapper<T, 93>(dim, out, inputs);
				break;
			case 94:
				join_wrapper<T, 94>(dim, out, inputs);
				break;
			case 95:
				join_wrapper<T, 95>(dim, out, inputs);
				break;
			case 96:
				join_wrapper<T, 96>(dim, out, inputs);
				break;
			case 97:
				join_wrapper<T, 97>(dim, out, inputs);
				break;
			case 98:
				join_wrapper<T, 98>(dim, out, inputs);
				break;
			case 99:
				join_wrapper<T, 99>(dim, out, inputs);
				break;
			case 100:
				join_wrapper<T, 100>(dim, out, inputs);
				break;
        }
        return out;
    }

#define INSTANTIATE(Tx, Ty)                                                                             \
    template Array<Tx> join<Tx, Ty>(const int dim, const Array<Tx> &first, const Array<Ty> &second);   \

    INSTANTIATE(float  , float  )
    INSTANTIATE(double , double )
    INSTANTIATE(cfloat , cfloat )
    INSTANTIATE(cdouble, cdouble)
    INSTANTIATE(int    , int    )
    INSTANTIATE(uint   , uint   )
    INSTANTIATE(intl   , intl   )
    INSTANTIATE(uintl  , uintl  )
    INSTANTIATE(short  , short  )
    INSTANTIATE(ushort , ushort )
    INSTANTIATE(uchar  , uchar  )
    INSTANTIATE(char   , char   )

#undef INSTANTIATE

#define INSTANTIATE(T)                                                                              \
    template Array<T> join<T>(const int dim, const std::vector<Array<T> > &inputs);

    INSTANTIATE(float)
    INSTANTIATE(double)
    INSTANTIATE(cfloat)
    INSTANTIATE(cdouble)
    INSTANTIATE(int)
    INSTANTIATE(uint)
    INSTANTIATE(intl)
    INSTANTIATE(uintl)
    INSTANTIATE(short)
    INSTANTIATE(ushort)
    INSTANTIATE(uchar)
    INSTANTIATE(char)

#undef INSTANTIATE
}
