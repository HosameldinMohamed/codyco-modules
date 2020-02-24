#include "knownExternalWrench.h"

namespace wholeBodyDynamics
{

knownExternalWrench::knownExternalWrench(std::string parsedframeName, std::string parsedType, std::vector<double> parsedPosition, std::vector<double> parsedDirection)
{
    frameName = parsedframeName;
    type = parsedType;
    position = parsedPosition;
    direction = parsedDirection;
}

bool knownExternalWrench::isValid(wholeBodyDynamics::knownExternalWrench _knownExternalWrench)
{
    // For each frame in the paramater overrideContactFrames, there is one string value in the paramater contactWrenchType (one of the 3 types mentioned above), and 3 real numbers in the paramater contactWrenchDirection
    if(_knownExternalWrench.isTypeValid() && _knownExternalWrench.isPositionValid() && _knownExternalWrench.isDirectionValid())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool knownExternalWrench::isTypeValid()
{
    //Check is type is either:
    //full = FULL_WRENCH
    //pure = PURE_FORCE or
    //pureKnown = PURE_FORCE_WITH_KNOWN_DIRECTION
    if(type !="full" || type!="pure" || type !="pureKnown")
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool knownExternalWrench::isPositionValid()
{
    //Make sure that the parsed postion vector is of 3 elements
    if(position.size() != 3)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool knownExternalWrench::isDirectionValid()
{
    //Make sure that the parsed postion vector is of 3 elements
    if(direction.size() != 3)
    {
        return false;
    }
    else
    {
        return true;
    }
}

iDynTree::UnknownWrenchContactType knownExternalWrench::asiDynTreeType()
{
    if(type=="full")
    {
        return iDynTree::FULL_WRENCH;
    }
    else if(type=="pure")
    {
        return iDynTree::PURE_FORCE;
    }
    else if(type=="pureKnown")
    {
        return iDynTree::PURE_FORCE_WITH_KNOWN_DIRECTION;
    }
}

iDynTree::Position knownExternalWrench::asiDynTreePosition()
{
    return iDynTree::Position(position[0], position[1],position[3]);
}

iDynTree::Direction knownExternalWrench::asiDynTreeDirection()
{
    return iDynTree::Direction(direction[0], direction[1], direction[2]);
}


}
