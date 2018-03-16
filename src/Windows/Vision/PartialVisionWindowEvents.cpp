/*
 * This file is part of the VSS-Vision project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#include <Windows/Vision/VisionWindow.h>

bool VisionWindow::onKeyboard(GdkEventKey*, Gtk::Window*) {
    return true;
}

void VisionWindow::onButtonOpenSaveDialog(Gtk::FileChooserDialog*, Gtk::Entry*) {

}

void VisionWindow::onButtonOpenLoadDialog(Gtk::FileChooserDialog*, Gtk::Entry*) {

}

void VisionWindow::onButtonSave(Gtk::FileChooserDialog*, Gtk::Entry*) {

}

void VisionWindow::onButtonLoad(Gtk::FileChooserDialog*, Gtk::Entry*) {

}

void VisionWindow::onRadioButtonImage(Gtk::RadioButton*) {

}

void VisionWindow::onRadioButtonVideo(Gtk::RadioButton*) {

}

void VisionWindow::onRadioButtonCamera(Gtk::RadioButton*) {

}

void VisionWindow::onSignalSelectFileInDialog(Gtk::FileChooserDialog*, Gtk::Entry*) {

}

void VisionWindow::onComboBoxSelectPath(Gtk::ComboBox*) {

}
