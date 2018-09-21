/*
 * This file is part of the VSS-Vision project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#ifndef VSS_VISION_IPATTERNRECOGNIZER_H
#define VSS_VISION_IPATTERNRECOGNIZER_H

#include <Domain/ColorPosition.h>

class IPatternRecognizer {
public:
    virtual ColorPosition getBallColorPosition() = 0;
    virtual ColorPosition getTeamColorPosition() = 0;
    virtual ColorPosition getOpponnetColorPosition() = 0;
    virtual std::vector<ColorPosition> getPlayerColorPosition() = 0;
};

#endif // VSS_VISION_IPATTERNRECOGNIZER_H
