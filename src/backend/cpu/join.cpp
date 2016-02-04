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

	int(*join_func[100])(int, int);

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
	case 51:
		getQueue().enqueue(kernel::join<T, 51>, dim, out, inputs);
		break;
	case 52:
		getQueue().enqueue(kernel::join<T, 52>, dim, out, inputs);
		break;
	case 53:
		getQueue().enqueue(kernel::join<T, 53>, dim, out, inputs);
		break;
	case 54:
		getQueue().enqueue(kernel::join<T, 54>, dim, out, inputs);
		break;
	case 55:
		getQueue().enqueue(kernel::join<T, 55>, dim, out, inputs);
		break;
	case 56:
		getQueue().enqueue(kernel::join<T, 56>, dim, out, inputs);
		break;
	case 57:
		getQueue().enqueue(kernel::join<T, 57>, dim, out, inputs);
		break;
	case 58:
		getQueue().enqueue(kernel::join<T, 58>, dim, out, inputs);
		break;
	case 59:
		getQueue().enqueue(kernel::join<T, 59>, dim, out, inputs);
		break;
	case 60:
		getQueue().enqueue(kernel::join<T, 60>, dim, out, inputs);
		break;
	case 61:
		getQueue().enqueue(kernel::join<T, 61>, dim, out, inputs);
		break;
	case 62:
		getQueue().enqueue(kernel::join<T, 62>, dim, out, inputs);
		break;
	case 63:
		getQueue().enqueue(kernel::join<T, 63>, dim, out, inputs);
		break;
	case 64:
		getQueue().enqueue(kernel::join<T, 64>, dim, out, inputs);
		break;
	case 65:
		getQueue().enqueue(kernel::join<T, 65>, dim, out, inputs);
		break;
	case 66:
		getQueue().enqueue(kernel::join<T, 66>, dim, out, inputs);
		break;
	case 67:
		getQueue().enqueue(kernel::join<T, 67>, dim, out, inputs);
		break;
	case 68:
		getQueue().enqueue(kernel::join<T, 68>, dim, out, inputs);
		break;
	case 69:
		getQueue().enqueue(kernel::join<T, 69>, dim, out, inputs);
		break;
	case 70:
		getQueue().enqueue(kernel::join<T, 70>, dim, out, inputs);
		break;
	case 71:
		getQueue().enqueue(kernel::join<T, 71>, dim, out, inputs);
		break;
	case 72:
		getQueue().enqueue(kernel::join<T, 72>, dim, out, inputs);
		break;
	case 73:
		getQueue().enqueue(kernel::join<T, 73>, dim, out, inputs);
		break;
	case 74:
		getQueue().enqueue(kernel::join<T, 74>, dim, out, inputs);
		break;
	case 75:
		getQueue().enqueue(kernel::join<T, 75>, dim, out, inputs);
		break;
	case 76:
		getQueue().enqueue(kernel::join<T, 76>, dim, out, inputs);
		break;
	case 77:
		getQueue().enqueue(kernel::join<T, 77>, dim, out, inputs);
		break;
	case 78:
		getQueue().enqueue(kernel::join<T, 78>, dim, out, inputs);
		break;
	case 79:
		getQueue().enqueue(kernel::join<T, 79>, dim, out, inputs);
		break;
	case 80:
		getQueue().enqueue(kernel::join<T, 80>, dim, out, inputs);
		break;
	case 81:
		getQueue().enqueue(kernel::join<T, 81>, dim, out, inputs);
		break;
	case 82:
		getQueue().enqueue(kernel::join<T, 82>, dim, out, inputs);
		break;
	case 83:
		getQueue().enqueue(kernel::join<T, 83>, dim, out, inputs);
		break;
	case 84:
		getQueue().enqueue(kernel::join<T, 84>, dim, out, inputs);
		break;
	case 85:
		getQueue().enqueue(kernel::join<T, 85>, dim, out, inputs);
		break;
	case 86:
		getQueue().enqueue(kernel::join<T, 86>, dim, out, inputs);
		break;
	case 87:
		getQueue().enqueue(kernel::join<T, 87>, dim, out, inputs);
		break;
	case 88:
		getQueue().enqueue(kernel::join<T, 88>, dim, out, inputs);
		break;
	case 89:
		getQueue().enqueue(kernel::join<T, 89>, dim, out, inputs);
		break;
	case 90:
		getQueue().enqueue(kernel::join<T, 90>, dim, out, inputs);
		break;
	case 91:
		getQueue().enqueue(kernel::join<T, 91>, dim, out, inputs);
		break;
	case 92:
		getQueue().enqueue(kernel::join<T, 92>, dim, out, inputs);
		break;
	case 93:
		getQueue().enqueue(kernel::join<T, 93>, dim, out, inputs);
		break;
	case 94:
		getQueue().enqueue(kernel::join<T, 94>, dim, out, inputs);
		break;
	case 95:
		getQueue().enqueue(kernel::join<T, 95>, dim, out, inputs);
		break;
	case 96:
		getQueue().enqueue(kernel::join<T, 96>, dim, out, inputs);
		break;
	case 97:
		getQueue().enqueue(kernel::join<T, 97>, dim, out, inputs);
		break;
	case 98:
		getQueue().enqueue(kernel::join<T, 98>, dim, out, inputs);
		break;
	case 99:
		getQueue().enqueue(kernel::join<T, 99>, dim, out, inputs);
		break;
	case 100:
		getQueue().enqueue(kernel::join<T, 100>, dim, out, inputs);
		break;
	case 101:
		getQueue().enqueue(kernel::join<T, 101>, dim, out, inputs);
		break;
	case 102:
		getQueue().enqueue(kernel::join<T, 102>, dim, out, inputs);
		break;
	case 103:
		getQueue().enqueue(kernel::join<T, 103>, dim, out, inputs);
		break;
	case 104:
		getQueue().enqueue(kernel::join<T, 104>, dim, out, inputs);
		break;
	case 105:
		getQueue().enqueue(kernel::join<T, 105>, dim, out, inputs);
		break;
	case 106:
		getQueue().enqueue(kernel::join<T, 106>, dim, out, inputs);
		break;
	case 107:
		getQueue().enqueue(kernel::join<T, 107>, dim, out, inputs);
		break;
	case 108:
		getQueue().enqueue(kernel::join<T, 108>, dim, out, inputs);
		break;
	case 109:
		getQueue().enqueue(kernel::join<T, 109>, dim, out, inputs);
		break;
	case 110:
		getQueue().enqueue(kernel::join<T, 110>, dim, out, inputs);
		break;
	case 111:
		getQueue().enqueue(kernel::join<T, 111>, dim, out, inputs);
		break;
	case 112:
		getQueue().enqueue(kernel::join<T, 112>, dim, out, inputs);
		break;
	case 113:
		getQueue().enqueue(kernel::join<T, 113>, dim, out, inputs);
		break;
	case 114:
		getQueue().enqueue(kernel::join<T, 114>, dim, out, inputs);
		break;
	case 115:
		getQueue().enqueue(kernel::join<T, 115>, dim, out, inputs);
		break;
	case 116:
		getQueue().enqueue(kernel::join<T, 116>, dim, out, inputs);
		break;
	case 117:
		getQueue().enqueue(kernel::join<T, 117>, dim, out, inputs);
		break;
	case 118:
		getQueue().enqueue(kernel::join<T, 118>, dim, out, inputs);
		break;
	case 119:
		getQueue().enqueue(kernel::join<T, 119>, dim, out, inputs);
		break;
	case 120:
		getQueue().enqueue(kernel::join<T, 120>, dim, out, inputs);
		break;
	case 121:
		getQueue().enqueue(kernel::join<T, 121>, dim, out, inputs);
		break;
	case 122:
		getQueue().enqueue(kernel::join<T, 122>, dim, out, inputs);
		break;
	case 123:
		getQueue().enqueue(kernel::join<T, 123>, dim, out, inputs);
		break;
	case 124:
		getQueue().enqueue(kernel::join<T, 124>, dim, out, inputs);
		break;
	case 125:
		getQueue().enqueue(kernel::join<T, 125>, dim, out, inputs);
		break;
	case 126:
		getQueue().enqueue(kernel::join<T, 126>, dim, out, inputs);
		break;
	case 127:
		getQueue().enqueue(kernel::join<T, 127>, dim, out, inputs);
		break;
	case 128:
		getQueue().enqueue(kernel::join<T, 128>, dim, out, inputs);
		break;
	case 129:
		getQueue().enqueue(kernel::join<T, 129>, dim, out, inputs);
		break;
	case 130:
		getQueue().enqueue(kernel::join<T, 130>, dim, out, inputs);
		break;
	case 131:
		getQueue().enqueue(kernel::join<T, 131>, dim, out, inputs);
		break;
	case 132:
		getQueue().enqueue(kernel::join<T, 132>, dim, out, inputs);
		break;
	case 133:
		getQueue().enqueue(kernel::join<T, 133>, dim, out, inputs);
		break;
	case 134:
		getQueue().enqueue(kernel::join<T, 134>, dim, out, inputs);
		break;
	case 135:
		getQueue().enqueue(kernel::join<T, 135>, dim, out, inputs);
		break;
	case 136:
		getQueue().enqueue(kernel::join<T, 136>, dim, out, inputs);
		break;
	case 137:
		getQueue().enqueue(kernel::join<T, 137>, dim, out, inputs);
		break;
	case 138:
		getQueue().enqueue(kernel::join<T, 138>, dim, out, inputs);
		break;
	case 139:
		getQueue().enqueue(kernel::join<T, 139>, dim, out, inputs);
		break;
	case 140:
		getQueue().enqueue(kernel::join<T, 140>, dim, out, inputs);
		break;
	case 141:
		getQueue().enqueue(kernel::join<T, 141>, dim, out, inputs);
		break;
	case 142:
		getQueue().enqueue(kernel::join<T, 142>, dim, out, inputs);
		break;
	case 143:
		getQueue().enqueue(kernel::join<T, 143>, dim, out, inputs);
		break;
	case 144:
		getQueue().enqueue(kernel::join<T, 144>, dim, out, inputs);
		break;
	case 145:
		getQueue().enqueue(kernel::join<T, 145>, dim, out, inputs);
		break;
	case 146:
		getQueue().enqueue(kernel::join<T, 146>, dim, out, inputs);
		break;
	case 147:
		getQueue().enqueue(kernel::join<T, 147>, dim, out, inputs);
		break;
	case 148:
		getQueue().enqueue(kernel::join<T, 148>, dim, out, inputs);
		break;
	case 149:
		getQueue().enqueue(kernel::join<T, 149>, dim, out, inputs);
		break;
	case 150:
		getQueue().enqueue(kernel::join<T, 150>, dim, out, inputs);
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
