#include "PlaybackImpl.h"
#include <iostream>

void PlaybackImpl::play(bool flag)
{
	std::cout << "play " << flag << std::endl;;
	for (auto delegate : _delegates) {
		if (delegate) {
			delegate->test();
		}
	}
}

void PlaybackImpl::stop()
{
	std::cout << "stop\n";
}

void PlaybackImpl::jump(int index)
{
	std::cout << "jump " << index << std::endl;;
}

void PlaybackImpl::addDelegate(PlaybackDelegate* delegate)
{
	if (_delegates.find(delegate) != _delegates.end()) {
		return;
	}
	_delegates.insert(delegate);
}

void PlaybackImpl::delDelegate(PlaybackDelegate* delegate)
{
	if (_delegates.find(delegate) == _delegates.end()) {
		return;
	}
	_delegates.erase(delegate);
}

PLAYBACK_API IPlayback* GetInstance()
{
	static PlaybackImpl impl;
	return &impl;
}