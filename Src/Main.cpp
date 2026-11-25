
#include <Geode/Geode.hpp>
#include <Geode/loader/GameEvent.hpp>
#include <Geode/loader/SettingV3.hpp>
#include <Geode/binding/PlayLayer.hpp>

using namespace geode::prelude;

$on_game(Loaded) {
    listenForKeybindSettingPresses("p1-jump",
        [](Keybind const&, bool down, bool repeat, double timestamp) {
            if (repeat) return;
            if (auto* layer = PlayLayer::get()) {
                layer->queueButton(
                    static_cast<int>(PlayerButton::Jump),
                    down, true, timestamp
                );
            }
        }
    );

    listenForKeybindSettingPresses("p2-jump",
        [](Keybind const&, bool down, bool repeat, double timestamp) {
            if (repeat) return;
            if (auto* layer = PlayLayer::get()) {
                layer->queueButton(
                    static_cast<int>(PlayerButton::Jump),
                    down, false, timestamp
                );
            }
        }
    );
}
