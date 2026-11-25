
#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(MobileKeybindsPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool dontCreateObjects) {
        if (!PlayLayer::init(level, dontCreateObjects))
            return false;

        this->addEventListener(
            KeybindSettingPressedEventV3(Mod::get(), "p1-jump"),
            [this](Keybind const&, bool down, bool repeat, double timestamp) {
                if (repeat) return ListenerResult::Propagate;

                this->queueButton(
                    static_cast<int>(PlayerButton::Jump),
                    down, false, timestamp
                );

                return ListenerResult::Propagate;
            }
        );

        this->addEventListener(
            KeybindSettingPressedEventV3(Mod::get(), "p2-jump"),
            [this](Keybind const&, bool down, bool repeat, double timestamp) {
                if (repeat) return ListenerResult::Propagate;

                this->queueButton(
                    static_cast<int>(PlayerButton::Jump),
                    down, true, timestamp
                );

                return ListenerResult::Propagate;
            }
        );

        return true;
    }
};
