/*
 * This file is part of the VSS-Vision project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#ifndef CALIBRATION_REPOSITORY_H
#define CALIBRATION_REPOSITORY_H

#include <Domain/ConfigurationType.h>
#include <Domain/ColorType.h>
#include <fstream>
#include <Domain/CutType.h>
#include <Interfaces/ICalibrationBuilder.h>
#include "ICalibrationRepository.h"
#include "Calibration.h"

class CalibrationRepository : public ICalibrationRepository {
public:
    CalibrationRepository(ICalibrationBuilder *calibrationFactory);

    Calibration read(std::string pathName) override;
    Calibration update(std::string pathName, Calibration calibration) override;
    void remove(std::string pathName) override;
    void create(std::string pathName, Calibration calibration) override;

private:
    ICalibrationBuilder *calibrationBuilder;

    ColorType hasColorType(std::string name);
    ConfigurationType hasConfigurationType(std::string name);
    CutType hasCutType(std::string name);

    void setCalibrationCut(Calibration &calibration, std::ifstream &file);
    void setCalibrationColorRange(Calibration &calibration, std::ifstream &file, ColorType &colorType);
    void setCalibrationConfiguration(Calibration &calibration, std::ifstream &file,
                                     ConfigurationType &configurationType);
};

#endif // CALIBRATION_REPOSITORY_H
