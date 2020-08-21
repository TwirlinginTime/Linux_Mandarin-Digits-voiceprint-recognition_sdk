#ifndef __TWIRLINGVPRRD_API_H__
#define __TWIRLINGVPRRD_API_H__

#ifdef __cplusplus
extern "C"
{
#endif

	char *TwirlingVPRGetVersion();
	
	void *TwirlingVPRInit(int *features_len, const char* app_id, const char* passwd);

	void TwirlingVPRRelease(void *obj);
	
	int TwirlingVPRProcess(void *obj, char *file_name, float* d_vector);

	float math_distance(float* str1, float *str2, int len);

#ifdef __cplusplus
};
#endif

#endif // __TWIRLINGVPRRD_API_H__
