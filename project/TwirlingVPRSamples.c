#include "../include/TwirlingVPRRDApi.h"
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#ifdef _LINUX_COMPILE_
#include <unistd.h>
#else
//#include <windows.h>
#endif
#define SAMPLERATE (16000)
#define CHANNELS (1)
#define BITDEPTH (short)

int main(int argc, char **argv)
{
	printf("version = %s\n", TwirlingVPRGetVersion());

	int argv_num = 2;
	if (argc != argv_num)
	{
		printf("Usage:%s xxx.raw\n", argv[0]);
		return -1;
	}
	const char *appid = "";         //在此输入您在时代拓灵官网创建项目所获得的appid
	const char *pwd = "";           //在此输入您在时代拓灵官网创建项目所设置的app密码
	int set_len = 0;
	void *vpr_obj = TwirlingVPRInit(&set_len, appid, pwd);
	if (!vpr_obj)
		return -1;

	float *d_vector = new float[set_len];
	
	int ret = TwirlingVPRProcess(vpr_obj, argv[1], d_vector);
	printf("ret = %d\n",ret);
	
	for (int i=0;i<set_len;i++)
	{
		printf("%f,",d_vector[i]);
		if ((i+1) % 10 == 0)
			printf("\n");
	}
	printf("\n");
	float res = math_distance(d_vector, d_vector, set_len);
	printf("math_distance: %f\n", res);
	delete []d_vector;
	TwirlingVPRRelease(vpr_obj);

	return 0;
}
