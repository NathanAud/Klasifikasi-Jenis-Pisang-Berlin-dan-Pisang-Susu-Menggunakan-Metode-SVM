#pragma once
#include <stdarg.h>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class PCA {
                public:
                    /**
                    * Apply dimensionality reduction
                    * @warn Will override the source vector if no dest provided!
                    */
                    void transform(float *x, float *dest = NULL) {
                        static float u[2] = { 0 };
                        u[0] = dot(x,   0.553798938847  , 0.556350548442  , 0.550032768259  , 0.152623839495  , 0.240729557885 );
                        u[1] = dot(x,   -0.038509679277  , -0.02641828174  , -0.06528892239  , 0.949542478473  , -0.30319221161 );
                        memcpy(dest != NULL ? dest : x, u, sizeof(float) * 2);
                    }

                protected:
                    /**
                    * Compute dot product with varargs
                    */
                    float dot(float *x, ...) {
                        va_list w;
                        va_start(w, 5);
                        static float mean[] = {  0.0 , 0.0 , -0.0 , -0.0 , -0.0  };
                        float dot = 0.0;

                        for (uint16_t i = 0; i < 5; i++) {
                            dot += (x[i] - mean[i]) * va_arg(w, double);
                        }

                        return dot;
                    }
                };
            }
        }
    }