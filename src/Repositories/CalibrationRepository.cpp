/*
 * This file is part of the VSS-Vision project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#include "CalibrationRepository.h"
#include "fstream"

Calibration CalibrationRepository::read(std::string pathName){
  return new Calibration();
}

void CalibrationRepository::create(std::string pathName, Calibration calibration){
  std::ofstream file;
  std::cout << pathName << std::endl;
  file.open (pathName);

  file << "# Rotation" << std::endl;
  file << calibration.rotation << std::endl;
  file << std::endl;

  file << "# Brigthness" << std::endl;
  file << calibration.brightness << std::endl;
  file << std::endl;

  file << "# Contrast" << std::endl;
  file << calibration.contrast << std::endl;
  file << std::endl;

  file << "# Saturation" << std::endl;
  file << calibration.saturation << std::endl;
  file << std::endl;

  file << "# Exposure" << std::endl;
  file << calibration.exposure << std::endl;
  file << std::endl;

  file << "# Gain" << std::endl;
  file << calibration.gain << std::endl;
  file << std::endl;

  file << "# Blue" << std::endl;
  for(int i = 0 ; i < 3 ; i++)
    file << calibration.colorsRange[0].min[i] << " ";
  file << std::endl;

  for(int i = 0 ; i < 3 ; i++)
    file << calibration.colorsRange[0].max[i] << " ";
  file << std::endl;
  file << std::endl;

  file << "# Yellow" << std::endl;
  for(int i = 0 ; i < 3 ; i++)
    file << calibration.colorsRange[1].min[i] << " ";
  file << std::endl;

  for(int i = 0 ; i < 3 ; i++)
    file << calibration.colorsRange[1].max[i] << " ";
  file << std::endl;
  file << std::endl;

  file << "# Orange" << std::endl;
  for(int i = 0 ; i < 3 ; i++)
    file << calibration.colorsRange[2].min[i] << " ";
  file << std::endl;

  for(int i = 0 ; i < 3 ; i++)
    file << calibration.colorsRange[2].max[i] << " ";
  file << std::endl;
  file << std::endl;

  file << "# Green" << std::endl;
  for(int i = 0 ; i < 3 ; i++)
    file << calibration.colorsRange[3].min[i] << " ";
  file << std::endl;

  for(int i = 0 ; i < 3 ; i++)
    file << calibration.colorsRange[3].max[i] << " ";
  file << std::endl;
  file << std::endl;

  file << "# Pink" << std::endl;
  for(int i = 0 ; i < 3 ; i++)
    file << calibration.colorsRange[4].min[i] << " ";
  file << std::endl;

  for(int i = 0 ; i < 3 ; i++)
    file << calibration.colorsRange[4].max[i] << " ";
  file << std::endl;
  file << std::endl;

  file << "# Purple" << std::endl;
  for(int i = 0 ; i < 3 ; i++)
    file << calibration.colorsRange[5].min[i] << " ";
  file << std::endl;

  for(int i = 0 ; i < 3 ; i++)
    file << calibration.colorsRange[5].max[i] << " ";
  file << std::endl;
  file << std::endl;

  file << "# Red" << std::endl;
  for(int i = 0 ; i < 3 ; i++)
    file << calibration.colorsRange[6].min[i] << " ";
  file << std::endl;

  for(int i = 0 ; i < 3 ; i++)
    file << calibration.colorsRange[6].max[i] << " ";
  file << std::endl;
  file << std::endl;

  file << "# Brown" << std::endl;
  for(int i = 0 ; i < 3 ; i++)
    file << calibration.colorsRange[7].min[i] << " ";
  file << std::endl;

  for(int i = 0 ; i < 3 ; i++)
    file << calibration.colorsRange[7].max[i] << " ";
  
  file.close();
}

Calibration CalibrationRepository::update(std::string pathName, Calibration calibration){
  // TODO
  return new Calibration();
}

void CalibrationRepository::remove(std::string pathName){
  // TODO
}
