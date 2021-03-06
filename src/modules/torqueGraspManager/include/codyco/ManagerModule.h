/*
 * Copyright (C) 2010 RobotCub Consortium, European Commission FP6 Project IST-004370
 * Author: Ugo Pattacini
 * email:  ugo.pattacini@iit.it
 * website: www.robotcub.org
 * Permission is granted to copy, distribute, and/or modify this program
 * under the terms of the GNU General Public License, version 2 or any
 * later version published by the Free Software Foundation.
 *
 * A copy of the license can be found at
 * http://www.robotcub.org/icub/license/gpl.txt
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details
*/

#ifndef MANAGERMODULE_H
#define MANAGERMODULE_H

#include <yarp/os/RFModule.h>
#include <yarp/os/Port.h>

namespace codyco {

    class ManagerThread;

    class ManagerModule: public yarp::os::RFModule
    {
    protected:
        ManagerThread *thr;
        yarp::os::Port rpcPort;

    public:
        ManagerModule();
        virtual ~ManagerModule();

        bool configure(yarp::os::ResourceFinder &rf);
        bool respond(const yarp::os::Bottle& command, yarp::os::Bottle& reply);
        bool close();
        double getPeriod();
        bool updateModule();
    };
}

#endif /* end of include guard: MANAGERMODULE_H */
