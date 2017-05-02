/*
 * Spi_Codec.h
 *
 * @brief Used for configuration of AD1938 codec for CTAG face2|4 Audio Card via spi-gpio
 *
 * Copyright (C) 2017 Henrik Langer henni19790@googlemail.com
 */

#ifndef SPI_CODEC_H_
#define SPI_CODEC_H_

#define REG_PLL_CLK_CONTROL_0 	0
#define REG_PLL_CLK_CONTROL_1 	1
#define REG_DAC_CONTROL_0 		2
#define REG_DAC_CONTROL_1 		3
#define REG_DAC_CONTROL_2 		4
#define REG_DAC_CHANNEL_MUTES 	5
#define REG_DAC_VOLUME_L1 		6
#define REG_DAC_VOLUME_R1 		7
#define REG_DAC_VOLUME_L2 		8
#define REG_DAC_VOLUME_R2 		9
#define REG_DAC_VOLUME_L3 		10
#define REG_DAC_VOLUME_R3 		11
#define REG_DAC_VOLUME_L4 		12
#define REG_DAC_VOLUME_R4 		13
#define REG_ADC_CONTROL_0 		14
#define REG_ADC_CONTROL_1 		15
#define REG_ADC_CONTROL_2 		16

#include <cstdlib>

class Spi_Codec {

public:
	enum CODEC_TYPE {
		MASTER_CODEC,
		SLAVE_CODEC
	};

	Spi_Codec();
	~Spi_Codec();

	int writeRegister(unsigned char reg, unsigned char value, CODEC_TYPE codec = MASTER_CODEC);
	unsigned char readRegister(unsigned char reg, CODEC_TYPE codec = MASTER_CODEC);

	int initCodec();
	int startAudio(int dummy_parameter = 0);
	int stopAudio();
	int setAudioSamplingRate(unsigned int newSamplingRate);
	unsigned int getAudioSamplingRate();
	int setDACVolume(int halfDbSteps);
	int setTDMSlots(unsigned int slots);
	int getTDMSlots();
	int dumpRegisters();

private:
	int _fd_master, _fd_slave;
	int _spiTransfer(unsigned char* tx_buf, unsigned char* rx_buf, size_t bytes, CODEC_TYPE codec = MASTER_CODEC);
};

#endif /* SPI_CODEC_H_ */
