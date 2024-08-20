#include "Parameters.h"

template<typename T>
static void castParameter(juce::AudioProcessorValueTreeState& apvts, const juce::ParameterID& id, T& destination)
{
    destination = dynamic_cast<T>(apvts.getParameter(id.getParamID()));
    jassert(destination);
}

Parameters::Parameters(juce::AudioProcessorValueTreeState& apvts)
{
    castParameter(apvts, gainParameterID, gainParam);
}

void Parameters::prepareToPlay(double sampleRate) noexcept
{
    double duration = 0.02;
    gainSmoother.reset(sampleRate, duration);
}

void Parameters::reset() noexcept
{
    gain = 0.0f;

    gainSmoother.setCurrentAndTargetValue(
    juce::Decibels::decibelsToGain(gainParam->get()));
}

void Parameters::update() noexcept
{
    /*float gainInDecibels = gainParam->get();
    float newGain = juce::Decibels::decibelsToGain(gainInDecibels);*/
    gainSmoother.setTargetValue(juce::Decibels::decibelsToGain(gainParam->get()));
}

void Parameters::smoothen() noexcept
{
    gain = gainSmoother.getNextValue();
}

juce::AudioProcessorValueTreeState::ParameterLayout Parameters::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout;

    layout.add(std::make_unique <juce::AudioParameterFloat>(
        gainParameterID,
        "Output Gain",
        juce::NormalisableRange<float> { -12.0f, 12.0f},
        0.0f));
    return layout;
}
