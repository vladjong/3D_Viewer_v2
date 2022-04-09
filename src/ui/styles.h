#pragma once

namespace s21 {

constexpr char BUTTON_STYLE[] = {
    "QPushButton {\n"
    " text-transform: uppercase;\n"
    " letter-spacing: 2.5px;\n"
    " color: #FCFEF1;\n"
    " background-color: #00589B;\n"
    " border: none;\n"
    "}\n"
    "\n"
    "QPushButton:hover {\n"
    "   background: rgba(0,0,0,0);\n"
    "   color: #3a7999;\n"
    "}\n"
    "\n"
    "QPushButton:pressed {\n"
    "   background: rgba(0,0,0,0);\n"
    "   color: #FCFEF1;\n"
    "}"};

constexpr char BUTTON_EXTRA_STYLE[] = {
    "QPushButton {\n"
    "   border-radius: 5px;\n"
    "   background-color: #25282C;\n"
    "   margin-bottom: 10px;\n"
    "}\n"
    "\n"
    "QPushButton:hover {\n"
    "   background-color: #2e3134;\n"
    "}\n"
    "\n"
    "QPushButton:pressed {\n"
    "   background-color: #3d4144;\n"
    "}"};

constexpr char BUTTON_SPIN_STYLE[] = {
    "QPushButton {\n"
    " border-radius: 5px;\n"
    " text-transform: uppercase;\n"
    " letter-spacing: 2.5px;\n"
    " color: #FCFEF1;\n"
    " background-color: #00589B;\n"
    " border: none;\n"
    "}\n"
    "\n"
    "QPushButton:hover {\n"
    "   background: rgba(0,0,0,0);\n"
    "   color: #3a7999;\n"
    "}\n"
    "\n"
    "QPushButton:pressed {\n"
    "   background: rgba(0,0,0,0);\n"
    "   color: #FCFEF1;\n"
    "}"};

constexpr char LINE_EDIT_STYLE[] = {
    "color: #FCFEF1;\n"
    "border: none;\n"
    "background-color: #25282C;\n"
    "border-radius: 5px;\n"
    "padding-left: 2px;"};

constexpr char LINE_EDIT_SETTING_STYLE[] = {
    "border:none;\n"
    "padding-left: 7px;\n"
    "border-radius: 5px;\n"
    "color: #FCFEF1;\n"
    "background-color: #25282C;"};

constexpr char LINE_STYLE[] = {
    "background-color: #FCFEF1;\n"
    "margin-top: 3px;\n"
    "border:none;"};

constexpr char COMBO_BOX_STYLE[] = {
    "selection-background-color: #25282C;\n"
    "selection-color: #00589B;\n"
    "border: none;\n"
    "border-radius: 5;\n"
    "color: #FCFEF1;\n"
    "background-color: #25282C;"};

}  // namespace s21
