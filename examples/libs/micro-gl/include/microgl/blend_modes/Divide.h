/*========================================================================================
 Copyright (2021), Tomer Shalev (tomer.shalev@gmail.com, https://github.com/HendrixString).
 All Rights Reserved.
 License is a custom open source semi-permissive license with the following guidelines:
 1. unless otherwise stated, derivative work and usage of this file is permitted and
    should be credited to the project and the author of this project.
 2. Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
========================================================================================*/
#pragma once

#include <microgl/blend_modes/blend_mode_base.h>

namespace microgl {
    namespace blendmode {

        class Divide {
        private:
            template<uint8_t bits>
            static inline
            uint blend_Divide(cuint b, cuint s) {
                constexpr cuint max = (uint(1)<<bits)-1;
                cuint res= (s==0) ? max : ((b*max) / s);
                return res>max ? max: res;
            }

        public:
            template<uint8_t R, uint8_t G, uint8_t B>
            static inline void blend(const color_t &b,
                                     const color_t &s,
                                     color_t &output) {
                output.r = blend_Divide<R>(b.r, s.r);
                output.g = blend_Divide<G>(b.g, s.g);
                output.b = blend_Divide<B>(b.b, s.b);
            }
        };
    }
}