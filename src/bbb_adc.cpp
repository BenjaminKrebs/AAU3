/*
 * bbb_adc.cpp
 *
 *  Created on: 17/11/2014
 *      Author: benjaminkrebs
 */


#include "bbb_adc.hpp"

BbbAdc::BbbAdc(analog_in_t analogIn)
{

	sprintf(mPath,"/sys/devices/ocp.3/helper.18/AIN%d",analogIn);
	mAdc_fd = open(mPath,O_RDONLY);
	if(mAdc_fd <0)
		perror("ADC file open");

	close(mAdc_fd);

}

BbbAdc::~BbbAdc()
{

}

unsigned int BbbAdc::get()
{
	unsigned int rv = 0;
	char buf[4];
	memset(buf,0,4);

	mAdc_fd = open(mPath,O_RDONLY);
	if(mAdc_fd <0)
		perror("ADC file open");

	int retVal = read(mAdc_fd,buf,4);
	if(retVal < 0)
		perror("ADC");

	close(mAdc_fd);

	rv = atoi(buf);
	return rv;
}

