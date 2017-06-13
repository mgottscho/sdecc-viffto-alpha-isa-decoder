/*
 * Author: Mark Gottscho
 * Email: mgottscho@ucla.edu
 */

#ifndef DECODER_HH
#define DECODER_HH

#include <stdint.h>

//total hack to compile on Hoffman2...
/*#ifndef _WIN32
typedef unsigned long uint64_t;
#else
#include <cstdint>
#endif*/

inline uint64_t
mask(int nbits)
{
    return (nbits == 64) ? (uint64_t)-1LL : (1ULL << nbits) - 1;
}

template <class T>
inline
T
mbits(T val, int first, int last)
{
    return val & (mask(first+1) & ~mask(last));
}

inline uint64_t
mask (int first, int last)
{
    return mbits((uint64_t)-1LL, first, last);
}

template <class T>
inline
T
bits(T val, int first, int last)
{
    int nbits = first - last + 1;
    return (val >> last) & mask(nbits);
}

template <class T>
inline
T
bits(T val, int bit)
{
    return bits (val, bit, bit);
}

namespace AlphaISAInst {
#undef PALMODE
#define PALMODE	bits(machInst, 32, 32)
#undef OPCODE
#define OPCODE	bits(machInst, 31, 26)
#undef RA
#define RA	bits(machInst, 25, 21)
#undef RB
#define RB	bits(machInst, 20, 16)
#undef MEMDISP
#define MEMDISP	sext<16>(bits(machInst, 15,  0))
#undef MEMFUNC
#define MEMFUNC	bits(machInst, 15,  0)
#undef JMPFUNC
#define JMPFUNC	bits(machInst, 15, 14)
#undef JMPHINT
#define JMPHINT	bits(machInst, 13,  0)
#undef BRDISP
#define BRDISP	sext<21>(bits(machInst, 20,  0))
#undef INTIMM
#define INTIMM	bits(machInst, 20, 13)
#undef IMM
#define IMM	bits(machInst, 12, 12)
#undef INTFUNC
#define INTFUNC	bits(machInst, 11,  5)
#undef RC
#define RC	bits(machInst,  4,  0)
#undef FA
#define FA	bits(machInst, 25, 21)
#undef FB
#define FB	bits(machInst, 20, 16)
#undef FP_FULLFUNC
#define FP_FULLFUNC	bits(machInst, 15,  5)
#undef FP_TRAPMODE
#define FP_TRAPMODE	bits(machInst, 15, 13)
#undef FP_ROUNDMODE
#define FP_ROUNDMODE	bits(machInst, 12, 11)
#undef FP_TYPEFUNC
#define FP_TYPEFUNC	bits(machInst, 10,  5)
#undef FP_SRCTYPE
#define FP_SRCTYPE	bits(machInst, 10,  9)
#undef FP_SHORTFUNC
#define FP_SHORTFUNC	bits(machInst,  8,  5)
#undef FP_SHORTFUNC_TOP2
#define FP_SHORTFUNC_TOP2	bits(machInst,  8,  7)
#undef FC
#define FC	bits(machInst,  4,  0)
#undef PALFUNC
#define PALFUNC	bits(machInst, 25,  0)
#undef HW_LDST_PHYS
#define HW_LDST_PHYS	bits(machInst, 15, 15)
#undef HW_LDST_ALT
#define HW_LDST_ALT	bits(machInst, 14, 14)
#undef HW_LDST_WRTCK
#define HW_LDST_WRTCK	bits(machInst, 13, 13)
#undef HW_LDST_QUAD
#define HW_LDST_QUAD	bits(machInst, 12, 12)
#undef HW_LDST_VPTE
#define HW_LDST_VPTE	bits(machInst, 11, 11)
#undef HW_LDST_LOCK
#define HW_LDST_LOCK	bits(machInst, 10, 10)
#undef HW_LDST_COND
#define HW_LDST_COND	bits(machInst, 10, 10)
#undef HW_LDST_DISP
#define HW_LDST_DISP	sext<10>(bits(machInst,  9,  0))
#undef HW_REI_TYP
#define HW_REI_TYP	bits(machInst, 15, 14)
#undef HW_REI_MBZ
#define HW_REI_MBZ	bits(machInst, 13,  0)
#undef HW_IPR_IDX
#define HW_IPR_IDX	bits(machInst, 15,  0)
#undef M5FUNC
#define M5FUNC	bits(machInst,  7,  0)

}

#endif

