/*
 * This file is part of the VSS-Vision project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#include "Windows/Calibration/CalibrationWindow.h"

int main(int argc, char *argv[]) {
  ICalibrationWindow *calibrationWindow = new CalibrationWindow();
  calibrationWindow->run(argc, argv);
}
