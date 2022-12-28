#pragma once
#include <stdarg.h>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class SVM {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        float kernels[43] = { 0 };
                        float decisions[1] = { 0 };
                        int votes[2] = { 0 };
                        kernels[0] = compute_kernel(x,   -2.330960042345  , -0.871421993496 );
                        kernels[1] = compute_kernel(x,   -0.17558309504  , -0.391568799014 );
                        kernels[2] = compute_kernel(x,   -0.603381960353  , 1.857497192876 );
                        kernels[3] = compute_kernel(x,   -1.835088030263  , 2.234863845404 );
                        kernels[4] = compute_kernel(x,   -1.712900146515  , -0.105521447676 );
                        kernels[5] = compute_kernel(x,   -0.683738399403  , -0.654835971823 );
                        kernels[6] = compute_kernel(x,   -1.435912604819  , -0.353840923589 );
                        kernels[7] = compute_kernel(x,   -1.655669679987  , -1.129104250679 );
                        kernels[8] = compute_kernel(x,   0.554839617897  , 0.671977911405 );
                        kernels[9] = compute_kernel(x,   2.168522151429  , 0.558050943079 );
                        kernels[10] = compute_kernel(x,   0.174075328171  , -0.868973346898 );
                        kernels[11] = compute_kernel(x,   2.824298279401  , -0.592444716924 );
                        kernels[12] = compute_kernel(x,   -0.461593155575  , -0.152564579734 );
                        kernels[13] = compute_kernel(x,   0.714746341313  , -0.270771717755 );
                        kernels[14] = compute_kernel(x,   2.301854462996  , -1.678632990291 );
                        kernels[15] = compute_kernel(x,   0.899730417526  , 0.878816220496 );
                        kernels[16] = compute_kernel(x,   1.8338752007  , 0.581058191119 );
                        kernels[17] = compute_kernel(x,   -0.460689098492  , -0.862507088752 );
                        kernels[18] = compute_kernel(x,   -4.133100984702  , -0.293863545117 );
                        kernels[19] = compute_kernel(x,   -0.401095725026  , -0.594357356676 );
                        kernels[20] = compute_kernel(x,   -0.836663825118  , -0.969933887774 );
                        kernels[21] = compute_kernel(x,   -0.622345227904  , -0.377541543077 );
                        kernels[22] = compute_kernel(x,   -1.84170399355  , -0.987836966229 );
                        kernels[23] = compute_kernel(x,   -1.926911759521  , 1.100898725815 );
                        kernels[24] = compute_kernel(x,   -1.32740162157  , 0.80497913922 );
                        kernels[25] = compute_kernel(x,   1.056191588845  , -0.27066751903 );
                        kernels[26] = compute_kernel(x,   -1.173167956837  , -0.653168346135 );
                        kernels[27] = compute_kernel(x,   -4.046210134058  , 0.694792481406 );
                        kernels[28] = compute_kernel(x,   0.187442235436  , 0.839808743467 );
                        kernels[29] = compute_kernel(x,   0.860291867662  , 0.487527397111 );
                        kernels[30] = compute_kernel(x,   -0.651664614574  , 0.457698334732 );
                        kernels[31] = compute_kernel(x,   -1.464149940949  , 0.745293745665 );
                        kernels[32] = compute_kernel(x,   -0.006370841414  , 0.2820692907 );
                        kernels[33] = compute_kernel(x,   2.187058634848  , -1.810282835571 );
                        kernels[34] = compute_kernel(x,   0.545112796362  , -0.379109298428 );
                        kernels[35] = compute_kernel(x,   0.455657211895  , 0.761927012661 );
                        kernels[36] = compute_kernel(x,   -1.713052087043  , -0.565713706629 );
                        kernels[37] = compute_kernel(x,   -0.181954100631  , -1.355939796446 );
                        kernels[38] = compute_kernel(x,   -0.436116300867  , -0.767851363882 );
                        kernels[39] = compute_kernel(x,   -1.133363782327  , -0.673968888089 );
                        kernels[40] = compute_kernel(x,   2.886585135902  , 0.585338573619 );
                        kernels[41] = compute_kernel(x,   2.397168009711  , -0.071710131444 );
                        kernels[42] = compute_kernel(x,   0.54107842514  , 0.606163511346 );
                        float decision = 0.231290733697;
                        decision = decision - ( + kernels[0] * -10.0  + kernels[1] * -10.0  + kernels[2] * -10.0  + kernels[3] * -10.0  + kernels[4] * -10.0  + kernels[5] * -10.0  + kernels[6] * -10.0  + kernels[7] * -10.0  + kernels[8] * -10.0  + kernels[9] * -10.0  + kernels[10] * -10.0  + kernels[11] * -10.0  + kernels[12] * -10.0  + kernels[13] * -10.0  + kernels[14] * -3.712154298397  + kernels[15] * -10.0  + kernels[16] * -10.0  + kernels[17] * -10.0  + kernels[18] * -10.0  + kernels[19] * -10.0  + kernels[20] * -10.0 );
                        decision = decision - ( + kernels[21] * 10.0  + kernels[22] * 10.0  + kernels[23] * 2.901561371689  + kernels[24] * 10.0  + kernels[25] * 10.0  + kernels[26] * 10.0  + kernels[27] * 10.0  + kernels[28] * 10.0  + kernels[29] * 10.0  + kernels[30] * 10.0  + kernels[31] * 10.0  + kernels[32] * 10.0  + kernels[33] * 10.0  + kernels[34] * 10.0  + kernels[35] * 10.0  + kernels[36] * 10.0  + kernels[37] * 10.0  + kernels[38] * 10.0  + kernels[39] * 10.0  + kernels[40] * 0.810592926707  + kernels[41] * 10.0  + kernels[42] * 10.0 );

                        return decision > 0 ? 0 : 1;
                    }

                    /**
                    * Predict readable class name
                    */
                    const char* predictLabel(float *x) {
                        return idxToLabel(predict(x));
                    }

                    /**
                    * Convert class idx to readable name
                    */
                    const char* idxToLabel(uint8_t classIdx) {
                        switch (classIdx) {
                            case 0:
                            return "susu";
                            case 1:
                            return "berlin";
                            default:
                            return "Houston we have a problem";
                        }
                    }

                protected:
                    /**
                    * Compute kernel between feature vector and support vector.
                    * Kernel type: linear
                    */
                    float compute_kernel(float *x, ...) {
                        va_list w;
                        va_start(w, 2);
                        float kernel = 0.0;

                        for (uint16_t i = 0; i < 2; i++) {
                            kernel += x[i] * va_arg(w, double);
                        }

                        return kernel;
                    }
                };
            }
        }
    }