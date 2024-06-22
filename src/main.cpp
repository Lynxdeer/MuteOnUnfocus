#include <Geode/Geode.hpp>
#include <windows.h>
#include <Geode/binding/AppDelegate.hpp>
#include <Geode/modify/CCScheduler.hpp>

using namespace geode::prelude;

HWND gdWindow = GetActiveWindow();
bool muted = false;

class $modify(CCScheduler) {
	void update(float dt) {
		/* 
		* For some reason, this if statement is completely reversed. Zero idea why.
		* If GD is the active window, it produces false, but if it is not, it produces true???
		* Frankly, it doesn't matter, cause it still works, but super weird
		*/
		if (gdWindow != GetActiveWindow()) {
			if (!muted) {
				AppDelegate::get()->resumeSound(); 
				muted = true;
			}
		} else if (muted) {
			AppDelegate::get()->pauseSound();
			muted = false;
		}
		CCScheduler::update(dt);
	}
};