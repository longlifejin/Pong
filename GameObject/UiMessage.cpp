#include "pch.h"
#include "UiMessage.h"

UiMessage::UiMessage(const std::string& name)
	: TextGo(name)
{
}

void UiMessage::SetScore(int score)
{
	this->score = score;
	text.setString(scoreFormat + std::to_string(this->score));
}

void UiMessage::AddScore(int score)
{
	this->score += score;
	text.setString(scoreFormat + std::to_string(this->score));
}

void UiMessage::Reset()
{
	SetScore(0);
}