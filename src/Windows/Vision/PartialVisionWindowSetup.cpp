/*
 * This file is part of the VSS-Vision project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#include <Windows/Vision/VisionWindow.h>

VisionWindow::VisionWindow(){
}

VisionWindow::~VisionWindow(){
}

void VisionWindow::run(int argc, char *argv[]){
  Gtk::Main kit(argc, argv);

  threadWindowControl = new thread( std::bind( &VisionWindow::windowThreadWrapper, this ));
  threadWindowControl->join();
}

void VisionWindow::windowThreadWrapper() {
  builderWidget();
  setSignals();
  initializeWidget();

  Gtk::Main::run(*window);
}

void VisionWindow::initializeWidget(){
  window->maximize();
  window->show_all_children();
}

void VisionWindow::builderWidget(){

  auto builder = Gtk::Builder::create();

  try {
    builder->add_from_file("../glade/Vision.glade");

    builder->get_widget("window", window);

    builder->get_widget("button_save_calibration", buttonSave);
    builder->get_widget("button_load_calibration", buttonLoad);
    builder->get_widget("button_save_dialog", buttonOpenSaveDialog);
    builder->get_widget("button_load_dialog", buttonOpenLoadDialog);

    builder->get_widget("entry_chooser", entryChooserDialog);
    builder->get_widget("file_chooser_dialog", fileChooserDialog);

    builder->get_widget("radiobutton_camera", radioButtonCamera);

    builder->get_widget("combobox_path", comboBoxPath);
		builder->get_widget("combobox_team_1", comboBoxColorTeam1);
		builder->get_widget("combobox_team_2", comboBoxColorTeam2);
		builder->get_widget("combobox_robot_1", comboBoxColorRobot1);
		builder->get_widget("combobox_robot_2", comboBoxColorRobot2);
		builder->get_widget("combobox_robot_3", comboBoxColorRobot3);
		builder->get_widget("combobox_robot_4", comboBoxColorRobot4);
		builder->get_widget("combobox_robot_5", comboBoxColorRobot5);

    
  } catch(const Glib::FileError& ex) {
    std::cerr << "FileError: " << ex.what() << std::endl;

  } catch(const Glib::MarkupError& ex) {
    std::cerr << "MarkupError: " << ex.what() << std::endl;

  } catch(const Gtk::BuilderError& ex) {
    std::cerr << "BuilderError: " << ex.what() << std::endl;
  }
}

void VisionWindow::setSignals(){ 
  window->signal_key_press_event().connect(sigc::bind<Gtk::Window*>(sigc::mem_fun(this, &IVisionWindow::onKeyboard), window) , false);

  buttonOpenSaveDialog->signal_clicked().connect(sigc::bind<Gtk::FileChooserDialog*, Gtk::Entry*>(sigc::mem_fun(this, &IVisionWindow::onButtonOpenSaveDialog), fileChooserDialog, entryChooserDialog ));
  buttonOpenLoadDialog->signal_clicked().connect(sigc::bind<Gtk::FileChooserDialog*, Gtk::Entry*>(sigc::mem_fun(this, &IVisionWindow::onButtonOpenLoadDialog), fileChooserDialog, entryChooserDialog ));
  
  buttonSave->signal_clicked().connect(sigc::bind<Gtk::FileChooserDialog*, Gtk::Entry*>(sigc::mem_fun(this, &IVisionWindow::onButtonSave), fileChooserDialog, entryChooserDialog ));
  buttonLoad->signal_clicked().connect(sigc::bind<Gtk::FileChooserDialog*, Gtk::Entry*>(sigc::mem_fun(this, &IVisionWindow::onButtonLoad), fileChooserDialog, entryChooserDialog));

  fileChooserDialog->signal_selection_changed().connect(sigc::bind<Gtk::FileChooserDialog*, Gtk::Entry*>(sigc::mem_fun(this, &IVisionWindow::onSignalSelectFileInDialog), fileChooserDialog, entryChooserDialog ));
  
  comboBoxPath->signal_changed().connect(sigc::bind<Gtk::ComboBox*>(sigc::mem_fun(this, &IVisionWindow::onComboBoxSelectPath), comboBoxPath));
}