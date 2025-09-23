#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

#include <stdint.h>

typedef int fixed_point_t;

/* Fixed-point constants */
#define FIXED_POINT_SHIFT 14 // q = 14
#define FIXED_POINT_FACTOR (1<< FIXED_POINT_SHIFT) // f = 2^14

/* Conversion */
#define FIXED_POINT_FROM_INT(n) ((fixed_point_t)(n) << FIXED_POINT_SHIFT)

#define FIXED_POINT_TO_INT_ZERO(x) ((x) >> FIXED_POINT_SHIFT)

#define FIXED_POINT_TO_INT_NEAREST
#define FIXED_POINT_TO_INT_NEAREST(x) ((x) >= 0 ? ((x) + FIXED_POINT_FACTOR / 2) >> FIXED_POINT_SHIFT : ((x) - FIXED_POINT_FACTOR / 2) >> FIXED_POINT_SHIFT)

/* Basic Calculation */
#define FIXED_POINT_ADD(x, y) ((x) + (y))
#define FIXED_POINT_SUB(x, y) ((x) - (y))
#define FIXED_POINT_ADD_INT(x, n) ((x) + FIXED_POINT_FROM_INT(n))
#define FIXED_POINT_SUB_INT(x, n) ((x) - FIXED_POINT_FROM_INT(n))

/* Multiplication */
#define FIXED_POINT_MUL(x, y) ((fixed_point_t)(((int64_t)(x)) * (y) >> FIXED_POINT_SHIFT))

#define FIXED_POINT_MUL_INT(x, n) ((x) * (n))

/* Division */
#define FIXED_POINT_DIV(x,y) ((fixed_point_t)((((int64_t)(x)) << FIXED_POINT_SHIFT) / (y)))

#define FIXED_POINT_DIV_INT(x, n) ((x) / (n))

/* Constants for MLFQS (For Timer Interrupt Optimization) */
#define LOAD_AVG_DECAY_FACTOR ((59 * FIXED_POINT_FACTOR) / 60) // 59/60
#define LOAD_AVG_READY_FACTOR ((FIXED_POINT_FACTOR) / 60) // 1/60
#define RECENT_CPU_DECAY_BASE FIXED_POINT_FROM_INT(2)   // 2

#endif
