/*
  ==============================================================================

    RotaryKnob.h
    Created: 25 Aug 2024 10:16:25am
    Author:  tomfr

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class RotaryKnob  : public juce::Component
{
public:
    RotaryKnob(const juce::String& text, 
            juce::AudioProcessorValueTreeState& apvts, 
            const juce::ParameterID& parameterID, 
            bool drawFromMiddle = false);
    ~RotaryKnob() override;

    juce::Slider slider;
    juce::AudioProcessorValueTreeState::SliderAttachment attachment;
    juce::Label label;

    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RotaryKnob)
};
