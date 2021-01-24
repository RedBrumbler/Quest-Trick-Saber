#pragma once

#include "InputHandler.hpp"
#include "PluginConfig.hpp"
#include "AllEnums.hpp"

#include "UnityEngine/XR/XRNode.hpp"
#include <string>

class ThumbstickHandler : public InputHandler {
  private:
    Il2CppString* _inputString;

  public:
    ThumbstickHandler(UnityEngine::XR::XRNode node, float threshold, ThumbstickDir thumstickDir) : InputHandler(threshold) {
        // axis names are from HMLib's VRControllersInputManager
        std::string axis = thumstickDir == ThumbstickDir::Horizontal ? "Horizontal" : "Vertical";
        axis += node == UnityEngine::XR::XRNode::LeftHand ? "LeftHand" : "RightHand";
        _inputString = il2cpp_utils::createcsstr(axis, il2cpp_utils::StringType::Manual);
        IsReversed = PluginConfig::Instance().ReverseThumbstick;
    }

    float GetInputValue() {
        // if (val != 0) getLogger().debug("ThumbstickHandler input value: %f", val);
        return UnityEngine::Input::GetAxis(_inputString);
    }

    ~ThumbstickHandler() {
        free(_inputString);
    }
};