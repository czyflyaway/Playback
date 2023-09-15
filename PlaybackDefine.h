#ifdef PLAYAPI_EXPORTS
#define PLAYBACK_API __declspec(dllexport)
#else
#define PLAYBACK_API __declspec(dllimport)
#endif
