// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 DLL2_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// PLAYBACK_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifndef _IPLAYBACK_H
#define _IPLAYBACK_H

#include "playbackdefine.h"

class IPlayback
{
public:
	class /*PLAYBACK_API*/ PlaybackDelegate
	{
	public:
		virtual void test() = 0;
	};
public:
	virtual void play(bool) = 0;
	virtual	void stop() = 0;
	virtual	void jump(int) = 0;

	virtual void addDelegate(PlaybackDelegate*) = 0;
	virtual void delDelegate(PlaybackDelegate*) = 0;
};

extern "C" PLAYBACK_API IPlayback * GetInstance();

#endif // _IPLAYBACK_H

