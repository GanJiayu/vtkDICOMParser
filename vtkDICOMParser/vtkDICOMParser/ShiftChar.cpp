#include "ShiftChar.h"
#include <stdlib.h>
#include <assert.h>

ShiftChar::ShiftChar(char ori = 'X', int stplen = 0) :
	_ori(ori), 
	_pro(ori), 
	_updated(false),
	_stplen(stplen) {}

ShiftChar::~ShiftChar(){}

int ShiftChar::CorrectNegativeStep(int stplen, int step) {
	while (stplen<0)
	{
		stplen += step;
	}
	return stplen;
}

// 1. Num
// 2. UpperCase
// 3. LowerCase
// 0. Others
short ShiftChar::CheckCharType() const {
	if (_ori >= ASCII_NUM_DEBUT && _ori < ASCII_NUM_FIN)
	{
		return 1;
	}
	else if (_ori >= ASCII_UPPERCASE_DEBUT && _ori < ASCII_UPPERCASE_FIN)
	{
		return 2;
	} 
	else if (_ori >= ASCII_LOWERCASE_DEBUT && _ori < ASCII_LOWERCASE_FIN)
	{
		return 3;
	}
	else {
		return 0;
	}
}

char ShiftChar::Transform() {
	int stplen_num = CorrectNegativeStep(_stplen, 10);
	int stplen_let = CorrectNegativeStep(_stplen, 26);

	switch (CheckCharType())
	{
	case 1:
		return (ASCII_NUM_DEBUT + (((static_cast<short>(_ori) - ASCII_NUM_DEBUT) + stplen_num) % 10));
	case 2:
		return (ASCII_UPPERCASE_DEBUT + (((static_cast<short>(_ori) - ASCII_UPPERCASE_DEBUT) + stplen_let) % 26));
	case 3:
		return (ASCII_LOWERCASE_DEBUT + (((static_cast<short>(_ori) - ASCII_LOWERCASE_DEBUT) + stplen_let) % 26));
	default:
		return _ori;
	}
}

ShiftChar* ShiftChar::Update() {
	_pro = Transform();
	MarkUpdate();
	return this;
}

ShiftChar* ShiftChar::SetChar(char ori) {
	this->_ori = ori;
	ClearUpdate();
	return this;
}

ShiftChar* ShiftChar::SetStepLength(int stplen) {
	this->_stplen = stplen;
	ClearUpdate();
	return this;
}

int ShiftChar::GetStepLength() const {
	assert(this->_updated);
	return this->_stplen;
}

char ShiftChar::GetChar() const {
	assert(this->_updated);
	return this->_pro;
}

std::ostream& operator<< (std::ostream& out, const ShiftChar* sc) {
	out << "Printing shiftchar instance." << std::endl;
	out << "Original Char: " << sc->_ori << std::endl;
	out << "Processed Char: " << sc->_pro << std::endl;
	out << "StepLength: " << sc->_stplen << std::endl;
	out << "Update Status: " << sc->_updated << std::endl;
	return out;
}


