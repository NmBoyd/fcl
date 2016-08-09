/*
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2013-2014, Willow Garage, Inc.
 *  Copyright (c) 2014-2016, Open Source Robotics Foundation
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Open Source Robotics Foundation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

/** \author Jia Pan */

#ifndef FCL_MATH_SAMPLERSE3QUATBALL_H
#define FCL_MATH_SAMPLERSE3QUATBALL_H

#include "fcl/data_types.h"
#include "fcl/math/sampler_base.h"


namespace fcl
{

template <typename Scalar>
class SamplerSE3Quat_ball : public SamplerBase<Scalar>
{
public:
  SamplerSE3Quat_ball();

  SamplerSE3Quat_ball(Scalar r_);

  void setBound(const Scalar& r_);

  void getBound(Scalar& r_) const;

  Vector7<Scalar> sample() const;

protected:
  Scalar r;
};

using SamplerSE3Quat_ballf = SamplerSE3Quat_ball<float>;
using SamplerSE3Quat_balld = SamplerSE3Quat_ball<double>;

//============================================================================//
//                                                                            //
//                              Implementations                               //
//                                                                            //
//============================================================================//

//==============================================================================
template <typename Scalar>
SamplerSE3Quat_ball<Scalar>::SamplerSE3Quat_ball()
{
  // Do nothing
}

//==============================================================================
template <typename Scalar>
SamplerSE3Quat_ball<Scalar>::SamplerSE3Quat_ball(Scalar r_) : r(r_)
{
  // Do nothing
}

//==============================================================================
template <typename Scalar>
void SamplerSE3Quat_ball<Scalar>::setBound(const Scalar& r_)
{
  r = r_;
}

//==============================================================================
template <typename Scalar>
void SamplerSE3Quat_ball<Scalar>::getBound(Scalar& r_) const
{
  r_ = r;
}

//==============================================================================
template <typename Scalar>
Vector7<Scalar> SamplerSE3Quat_ball<Scalar>::sample() const
{
  Vector7<Scalar> q;
  Scalar x, y, z;
  this->rng.ball(0, r, x, y, z);
  q[0] = x;
  q[1] = y;
  q[2] = z;

  Scalar s[4];
  this->rng.quaternion(s);

  q[3] = s[0];
  q[4] = s[1];
  q[5] = s[2];
  q[6] = s[3];
  return q;
}

} // namespace fcl

#endif
