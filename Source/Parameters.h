#pragma once

#include <JuceHeader.h>

const juce::ParameterID gainParameterID{ "gain", 1 };

class Parameters
{
public:

	Parameters(juce::AudioProcessorValueTreeState& apvts);

	static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

	void update() noexcept
	{
		gain = juce::Decibels::decibelsToGain(gainParam->get());
	}

	float gain = 0.0f;

private:
	juce::AudioParameterFloat* gainParam;
};
