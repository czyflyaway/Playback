#ifndef _PLAYBACK_IMPL_H
#define _PLAYBACK_IMPL_H

#include "IPlayback.h"

#include <set>

class PlaybackImpl : public IPlayback
{
public:
	PlaybackImpl() {

	}
public:

	virtual void play(bool flag) override;
	virtual	void stop() override;
	virtual	void jump(int index) override;

	virtual void addDelegate(PlaybackDelegate*) override;
	virtual void delDelegate(PlaybackDelegate*) override;

private:
	std::set<PlaybackDelegate*> _delegates;
};
#endif // !_PLAYBACK_IMPL_H