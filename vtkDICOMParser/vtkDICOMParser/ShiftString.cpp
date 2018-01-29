#include "ShiftString.h"
#include "ShiftChar.h"
#include <assert.h>
std::ostream& operator<< (std::ostream& out, ShiftString* ss) {
	out << "Printing ShiftString Instance: " << std::endl;
	out << "String: " << ss->_str << std::endl;
	out << "StepLength: " << ss->_stplen << std::endl;
	out << "Update Status: " << ss->_updated << std::endl;
	return out;
}

ShiftString::ShiftString(const char* str = "XXX", int stplen = 0):
	_str(str),
	_stplen(stplen),
	_updated(false)
{}


ShiftString::~ShiftString()
{
}

ShiftString* ShiftString::Update() {
	assert(!_updated);
	for (size_t i = 0; i < _str.size() + 1 ; i++)
	{
		ShiftChar* encodeChar = new ShiftChar(_str[i], _stplen);
		encodeChar->Update();
		_str[i] = encodeChar->GetChar();
	}
	MarkUpdate();
	return this;
}

ShiftString* ShiftString::SetStr(const std::string& nStr) {
	_str = nStr;
	ClearUpdate();
	return this;
}

ShiftString* ShiftString::SetStepLength(int stplen) {
	_stplen = stplen;
	ClearUpdate();
	return this;
	{

	};
}
