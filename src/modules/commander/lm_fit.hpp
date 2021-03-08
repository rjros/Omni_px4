/****************************************************************************
 *
 *   Copyright (c) 2021 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#pragma once

#include <matrix/matrix/math.hpp>
#include <px4_platform_common/defines.h>

struct sphere_params {
	matrix::Vector3f offset{0.f, 0.f, 0.f};
	matrix::Vector3f diag{1.f, 1.f, 1.f};
	matrix::Vector3f offdiag{0.f, 0.f, 0.f};
	float radius{0.2f};
};


/**
 * Least-squares fit of a sphere to a set of points.
 *
 * Fits a sphere to a set of points on the sphere surface.
 *
 * @param data x,y,z point coordinates
 * @param samples_collected number of points
 * @param max_iterations abort if maximum number of iterations have been reached. If unsure, set to 100.
 * @param params the values to be optimized
 * @param full_ellipsoid whether to just optimize a sphere, or do an ellipsoid optimization
 *
 * NB!! If you optimize the full ellipsoid, you must have already optimized without the full ellipsoid
 *
 * @return 0 on success, 1 on failure
 */
int lm_fit(const matrix::Vector3f data[], unsigned samples_collected, sphere_params &params, bool full_ellipsoid);
