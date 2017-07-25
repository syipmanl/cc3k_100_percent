
#include "textdisplay.h"
#include <string>
#include <iostream>

TextDisplay::TextDisplay() {}

// may not needed
TextDisplay::~TextDisplay() {}

void TextDisplay::addrow(const string line) {
    tdDisplay.push_back(line);
}


vector<string> *TextDisplay::getDisplay(){
    return &tdDisplay;
}

void TextDisplay::change(int row, int col, char symbol) {
	tdDisplay[row][col] = symbol;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
    for (int i=0;i<td.tdDisplay.size();i++) {
        out<<td.tdDisplay.at(i)<<std::endl;
    }
    return out;
}
