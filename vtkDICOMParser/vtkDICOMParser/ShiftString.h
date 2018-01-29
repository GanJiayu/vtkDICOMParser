#pragma once
#include <string>
class ShiftString
{
public:
	explicit ShiftString(const char* str, int stplen);
	~ShiftString();
	ShiftString* Update();
	ShiftString* SetStr(const std::string& nStr);
	ShiftString* SetStepLength(int stplen);
	inline const std::string& GetStr() const {
		return _str;
	}
	inline int	 GetStepLength() const {
		return _stplen;
	}
	inline ShiftString* MarkUpdate() {
		_updated = true;
		return this;
	}
	inline ShiftString* ClearUpdate() {
		_updated = false;
		return this;
	}
	friend std::ostream& operator<< (std::ostream&, ShiftString*);
private:
	std::string _str;
	int			_stplen;
	bool		_updated;
};



