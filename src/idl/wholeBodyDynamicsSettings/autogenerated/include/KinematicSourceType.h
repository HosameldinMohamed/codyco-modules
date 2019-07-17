/*
 * Copyright (C) 2006-2019 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

// Autogenerated by Thrift Compiler (0.12.0-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#ifndef YARP_THRIFT_GENERATOR_ENUM_KINEMATICSOURCETYPE_H
#define YARP_THRIFT_GENERATOR_ENUM_KINEMATICSOURCETYPE_H

#include <yarp/os/Wire.h>
#include <yarp/os/idl/WireTypes.h>

enum KinematicSourceType
{
    IMU = 0,
    FIXED_FRAME = 1
};

class KinematicSourceTypeVocab :
        public yarp::os::idl::WireVocab
{
public:
    int fromString(const std::string& input) override;
    std::string toString(int input) const override;
};

#endif // YARP_THRIFT_GENERATOR_ENUM_KINEMATICSOURCETYPE_H
