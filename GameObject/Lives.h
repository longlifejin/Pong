#pragma once
#include "TextGo.h"
class Lives : public TextGo
{
protected:
	Lives(const Lives&) = delete;
	Lives(Lives&&) = delete;
	Lives& operator=(const Lives&) = delete;
	Lives& operator=(Lives&&) = delete;

public:
	Lives(const std::string& name = "");

	void SetLife(int life);
	void AddLife(int life);

	void Reset() override;

};

