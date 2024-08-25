/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DelayAudioProcessorEditor::DelayAudioProcessorEditor (DelayAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    addAndMakeVisible(gainKnob);

    setSize (500, 330);
}

DelayAudioProcessorEditor::~DelayAudioProcessorEditor()
{
}

//==============================================================================
void DelayAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
  /*  g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));*/
    g.fillAll(juce::Colours::darkgrey);
    /*g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (40.0f));
    g.drawFittedText ("Delay Plug-in!", getLocalBounds(), juce::Justification::centred, 1);*/
}

void DelayAudioProcessorEditor::resized()
{
    gainKnob.setTopLeftPosition(215, 120);
}
